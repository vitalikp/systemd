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


