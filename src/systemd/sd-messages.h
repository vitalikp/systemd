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

#define SD_MESSAGE_STARTUP_FINISHED SD_ID128_MAKE(b0,7a,24,9c,d0,24,41,4a,82,dd,00,cd,18,13,78,ff)

#define SD_MESSAGE_UNIT_STARTING    SD_ID128_MAKE(7d,49,58,e8,42,da,4a,75,8f,6c,1c,dc,7b,36,dc,c5)
#define SD_MESSAGE_UNIT_STARTED     SD_ID128_MAKE(39,f5,34,79,d3,a0,45,ac,8e,11,78,62,48,23,1f,bf)
#define SD_MESSAGE_UNIT_STOPPING    SD_ID128_MAKE(de,5b,42,6a,63,be,47,a7,b6,ac,3e,aa,c8,2e,2f,6f)
#define SD_MESSAGE_UNIT_STOPPED     SD_ID128_MAKE(9d,1a,aa,27,d6,01,40,bd,96,36,54,38,aa,d2,02,86)
#define SD_MESSAGE_UNIT_FAILED      SD_ID128_MAKE(be,02,cf,68,55,d2,42,8b,a4,0d,f7,e9,d0,22,f0,3d)
#define SD_MESSAGE_UNIT_RELOADING   SD_ID128_MAKE(d3,4d,03,7f,ff,18,47,e6,ae,66,9a,37,0e,69,47,25)
#define SD_MESSAGE_UNIT_RELOADED    SD_ID128_MAKE(7b,05,eb,c6,68,38,42,22,ba,a8,88,11,79,cf,da,54)

#define SD_MESSAGE_SPAWN_FAILED     SD_ID128_MAKE(64,12,57,65,1c,1b,4e,c9,a8,62,4d,7a,40,a9,e1,e7)

#define SD_MESSAGE_FORWARD_SYSLOG_MISSED SD_ID128_MAKE(00,27,22,9c,a0,64,41,81,a7,6c,4e,92,45,8a,fa,2e)

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
