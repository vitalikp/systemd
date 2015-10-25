/*-*- Mode: C; c-basic-offset: 8; indent-tabs-mode: nil -*-*/

#ifndef foosdmessageshfoo
#define foosdmessageshfoo

/***
  This file is part of systemd.

  Copyright 2012 Lennart Poettering

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

#include "sd-id128.h"
#include "_sd-common.h"

_SD_BEGIN_DECLARATIONS;

#define SD_MESSAGE_SPAWN_FAILED     SD_ID128_MAKE(64,12,57,65,1c,1b,4e,c9,a8,62,4d,7a,40,a9,e1,e7)

#define SD_MESSAGE_OVERMOUNTING     SD_ID128_MAKE(1d,ee,03,69,c7,fc,47,36,b7,09,9b,38,ec,b4,6e,e7)

#define SD_MESSAGE_LID_OPENED       SD_ID128_MAKE(b7,2e,a4,a2,88,15,45,a0,b5,0e,20,0e,55,b9,b0,6f)
#define SD_MESSAGE_LID_CLOSED       SD_ID128_MAKE(b7,2e,a4,a2,88,15,45,a0,b5,0e,20,0e,55,b9,b0,70)
#define SD_MESSAGE_SYSTEM_DOCKED    SD_ID128_MAKE(f5,f4,16,b8,62,07,4b,28,92,7a,48,c3,ba,7d,51,ff)
#define SD_MESSAGE_SYSTEM_UNDOCKED  SD_ID128_MAKE(51,e1,71,bd,58,52,48,56,81,10,14,4c,51,7c,ca,53)
#define SD_MESSAGE_POWER_KEY        SD_ID128_MAKE(b7,2e,a4,a2,88,15,45,a0,b5,0e,20,0e,55,b9,b0,71)
#define SD_MESSAGE_SUSPEND_KEY      SD_ID128_MAKE(b7,2e,a4,a2,88,15,45,a0,b5,0e,20,0e,55,b9,b0,72)
#define SD_MESSAGE_HIBERNATE_KEY    SD_ID128_MAKE(b7,2e,a4,a2,88,15,45,a0,b5,0e,20,0e,55,b9,b0,73)

_SD_END_DECLARATIONS;

#endif
