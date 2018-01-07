/*-*- Mode: C; c-basic-offset: 8; indent-tabs-mode: nil -*-*/

/***
  This file is part of systemd.

  Copyright 2013 Lennart Poettering

  systemd is free software; you can redistribute it and/or modify it
  under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation; either version 2.1 of the License, or
  (at your option) any later version.

  systemd is distributed in the hope that it will be useful, but
  WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with systemd; If not, see <http://www.gnu.org/licenses/>.
***/

#ifdef HAVE_VALGRIND_MEMCHECK_H
#include <valgrind/memcheck.h>
#endif

#include <fcntl.h>
#include <malloc.h>
#include <sys/mman.h>
#include <sys/prctl.h>

#include "util.h"
#include "strv.h"

#include "missing.h"
#include "bus-internal.h"
#include "bus-message.h"
#include "bus-kernel.h"
#include "bus-bloom.h"
#include "bus-util.h"
#include "bus-label.h"
#include "cgroup-util.h"

#define UNIQUE_NAME_MAX (3+DECIMAL_STR_MAX(uint64_t))

int bus_kernel_parse_unique_name(const char *s, uint64_t *id) {
        int r;

        assert(s);
        assert(id);

        if (!startswith(s, ":1."))
                return 0;

        r = safe_atou64(s + 3, id);
        if (r < 0)
                return r;

        return 1;
}

static void close_and_munmap(int fd, void *address, size_t size) {
        if (size > 0)
                assert_se(munmap(address, PAGE_ALIGN(size)) >= 0);

        safe_close(fd);
}

void bus_kernel_flush_memfd(sd_bus *b) {
        unsigned i;

        assert(b);

        for (i = 0; i < b->n_memfd_cache; i++)
                close_and_munmap(b->memfd_cache[i].fd, b->memfd_cache[i].address, b->memfd_cache[i].mapped);
}

int kdbus_translate_request_name_flags(uint64_t flags, uint64_t *kdbus_flags) {
        uint64_t f = 0;

        assert(kdbus_flags);

        if (flags & SD_BUS_NAME_ALLOW_REPLACEMENT)
                f |= KDBUS_NAME_ALLOW_REPLACEMENT;

        if (flags & SD_BUS_NAME_REPLACE_EXISTING)
                f |= KDBUS_NAME_REPLACE_EXISTING;

        if (flags & SD_BUS_NAME_QUEUE)
                f |= KDBUS_NAME_QUEUE;

        *kdbus_flags = f;
        return 0;
}

int kdbus_translate_attach_flags(uint64_t mask, uint64_t *kdbus_mask) {
        uint64_t m = 0;

        assert(kdbus_mask);

        if (mask & (SD_BUS_CREDS_UID|SD_BUS_CREDS_GID|SD_BUS_CREDS_PID|SD_BUS_CREDS_PID_STARTTIME|SD_BUS_CREDS_TID))
                m |= KDBUS_ATTACH_CREDS;

        if (mask & (SD_BUS_CREDS_COMM|SD_BUS_CREDS_TID_COMM))
                m |= KDBUS_ATTACH_COMM;

        if (mask & SD_BUS_CREDS_EXE)
                m |= KDBUS_ATTACH_EXE;

        if (mask & SD_BUS_CREDS_CMDLINE)
                m |= KDBUS_ATTACH_CMDLINE;

        if (mask & (SD_BUS_CREDS_CGROUP|SD_BUS_CREDS_UNIT|SD_BUS_CREDS_USER_UNIT|SD_BUS_CREDS_SLICE|SD_BUS_CREDS_SESSION|SD_BUS_CREDS_OWNER_UID))
                m |= KDBUS_ATTACH_CGROUP;

        if (mask & (SD_BUS_CREDS_EFFECTIVE_CAPS|SD_BUS_CREDS_PERMITTED_CAPS|SD_BUS_CREDS_INHERITABLE_CAPS|SD_BUS_CREDS_BOUNDING_CAPS))
                m |= KDBUS_ATTACH_CAPS;

        if (mask & SD_BUS_CREDS_SELINUX_CONTEXT)
                m |= KDBUS_ATTACH_SECLABEL;

        if (mask & (SD_BUS_CREDS_AUDIT_SESSION_ID|SD_BUS_CREDS_AUDIT_LOGIN_UID))
                m |= KDBUS_ATTACH_AUDIT;

        if (mask & SD_BUS_CREDS_WELL_KNOWN_NAMES)
                m |= KDBUS_ATTACH_NAMES;

        if (mask & SD_BUS_CREDS_CONNECTION_NAME)
                m |= KDBUS_ATTACH_CONN_NAME;

        *kdbus_mask = m;
        return 0;
}

int bus_kernel_create_bus(const char *name, bool world, char **s) {
        struct kdbus_cmd_make *make;
        struct kdbus_item *n;
        int fd;

        assert(name);
        assert(s);

        fd = open("/dev/kdbus/control", O_RDWR|O_NOCTTY|O_CLOEXEC);
        if (fd < 0)
                return -errno;

        make = alloca0(ALIGN8(offsetof(struct kdbus_cmd_make, items) +
                              offsetof(struct kdbus_item, data64) + sizeof(uint64_t) +
                              offsetof(struct kdbus_item, str) +
                              DECIMAL_STR_MAX(uid_t) + 1 + strlen(name) + 1));

        make->size = offsetof(struct kdbus_cmd_make, items);

        n = make->items;
        n->size = offsetof(struct kdbus_item, bloom_parameter) +
                  sizeof(struct kdbus_bloom_parameter);
        n->type = KDBUS_ITEM_BLOOM_PARAMETER;

        n->bloom_parameter.size = DEFAULT_BLOOM_SIZE;
        n->bloom_parameter.n_hash = DEFAULT_BLOOM_N_HASH;

        assert_cc(DEFAULT_BLOOM_SIZE > 0);
        assert_cc(DEFAULT_BLOOM_N_HASH > 0);

        make->size += ALIGN8(n->size);

        n = KDBUS_ITEM_NEXT(n);
        sprintf(n->str, UID_FMT "-%s", getuid(), name);
        n->size = offsetof(struct kdbus_item, str) + strlen(n->str) + 1;
        n->type = KDBUS_ITEM_MAKE_NAME;
        make->size += ALIGN8(n->size);

        make->flags = world ? KDBUS_MAKE_ACCESS_WORLD : 0;

        if (ioctl(fd, KDBUS_CMD_BUS_MAKE, make) < 0) {
                safe_close(fd);
                return -errno;
        }

        /* The higher 32bit of the flags field are considered
         * 'incompatible flags'. Refuse them all for now. */
        if (make->flags > 0xFFFFFFFFULL) {
                safe_close(fd);
                return -ENOTSUP;
        }

        if (s) {
                char *p;

                p = strjoin("/dev/kdbus/", n->str, "/bus", NULL);
                if (!p) {
                        safe_close(fd);
                        return -ENOMEM;
                }

                *s = p;
        }

        return fd;
}
