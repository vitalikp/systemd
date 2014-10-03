/*-*- Mode: C; c-basic-offset: 8; indent-tabs-mode: nil -*-*/

/***
  This file is part of systemd.

  Copyright 2013 Tom Gundersen <teg@jklm.no>

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

#include "sd-event.h"
#include "sd-daemon.h"

#include "networkd.h"

int main(int argc, char *argv[]) {
        _cleanup_manager_free_ Manager *m = NULL;
        int r;

        log_set_target(LOG_TARGET_AUTO);
        log_parse_environment();
        log_open();

        umask(0022);

        if (argc != 1) {
                log_error("This program takes no arguments.");
                r = -EINVAL;
                goto out;
        }

        /* Always create the directories people can create inotify
         * watches in. */
        r = mkdir_label("/run/systemd/network", 0755);
        if (r < 0)
                log_error("Could not create runtime directory: %s",
                          strerror(-r));

        r = mkdir_label("/run/systemd/network/links", 0755);
        if (r < 0)
                log_error("Could not create runtime directory 'links': %s",
                          strerror(-r));

        r = mkdir_label("/run/systemd/network/leases", 0755);
        if (r < 0)
                log_error("Could not create runtime directory 'leases': %s",
                          strerror(-r));

        r = manager_new(&m);
        if (r < 0) {
                log_error("Could not create manager: %s", strerror(-r));
                goto out;
        }

        r = manager_udev_listen(m);
        if (r < 0) {
                log_error("Could not connect to udev: %s", strerror(-r));
                goto out;
        }

        r = manager_rtnl_listen(m);
        if (r < 0) {
                log_error("Could not connect to rtnl: %s", strerror(-r));
                goto out;
        }

        r = manager_bus_listen(m);
        if (r < 0) {
                log_error("Could not connect to system bus: %s", strerror(-r));
                goto out;
        }

        r = manager_load_config(m);
        if (r < 0) {
                log_error("Could not load configuration files: %s", strerror(-r));
                goto out;
        }

        r = manager_rtnl_enumerate_links(m);
        if (r < 0) {
                log_error("Could not enumerate links: %s", strerror(-r));
                goto out;
        }

        sd_notify(false,
                  "READY=1\n"
                  "STATUS=Processing requests...");

        r = sd_event_loop(m->event);
        if (r < 0) {
                log_error("Event loop failed: %s", strerror(-r));
                goto out;
        }

out:
        sd_notify(false,
                  "STATUS=Shutting down...");

        return r < 0 ? EXIT_FAILURE : EXIT_SUCCESS;
}
