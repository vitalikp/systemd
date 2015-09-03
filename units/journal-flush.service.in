#  This file is part of systemd.
#
#  systemd is free software; you can redistribute it and/or modify it
#  under the terms of the GNU Lesser General Public License as published by
#  the Free Software Foundation; either version 2.1 of the License, or
#  (at your option) any later version.

[Unit]
Description=Trigger Flushing of Journal to Persistent Storage
Documentation=man:journald.service(8) man:journald.conf(5)
DefaultDependencies=no
Requires=journald.service
After=journald.service local-fs.target remote-fs.target
Before=systemd-user-sessions.service

[Service]
ExecStart=@rootbindir@/systemctl kill --kill-who=main --signal=SIGUSR1 journald.service
Type=oneshot
