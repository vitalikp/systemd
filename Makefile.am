#  -*- Mode: makefile; indent-tabs-mode: t -*-
#
#  This file is part of systemd.
#
#  Copyright 2010-2012 Lennart Poettering
#  Copyright 2010-2012 Kay Sievers
#  Copyright 2013 Zbigniew Jędrzejewski-Szmek
#  Copyright 2013 David Strauss
#
#  systemd is free software; you can redistribute it and/or modify it
#  under the terms of the GNU Lesser General Public License as published by
#  the Free Software Foundation; either version 2.1 of the License, or
#  (at your option) any later version.
#
#  systemd is distributed in the hope that it will be useful, but
#  WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
#  Lesser General Public License for more details.
#
#  You should have received a copy of the GNU Lesser General Public License
#  along with systemd; If not, see <http://www.gnu.org/licenses/>.

ACLOCAL_AMFLAGS = -I m4 ${ACLOCAL_FLAGS}
AM_MAKEFLAGS = --no-print-directory
AUTOMAKE_OPTIONS = color-tests parallel-tests

SUBDIRS = . po

# remove targets if the command fails
.DELETE_ON_ERROR:

# keep intermediate files
.SECONDARY:

# Keep the test-suite.log
.PRECIOUS: $(TEST_SUITE_LOG) Makefile

LIBSYSTEMD_CURRENT=3
LIBSYSTEMD_REVISION=0
LIBSYSTEMD_AGE=3

# The following four libraries only exist for compatibility reasons,
# their version info should not be bumped anymore
LIBSYSTEMD_LOGIN_CURRENT=9
LIBSYSTEMD_LOGIN_REVISION=3
LIBSYSTEMD_LOGIN_AGE=9

LIBSYSTEMD_DAEMON_CURRENT=0
LIBSYSTEMD_DAEMON_REVISION=12
LIBSYSTEMD_DAEMON_AGE=0

LIBSYSTEMD_ID128_CURRENT=0
LIBSYSTEMD_ID128_REVISION=28
LIBSYSTEMD_ID128_AGE=0

# Dirs of external packages
dbuspolicydir=@dbuspolicydir@
dbussessionservicedir=@dbussessionservicedir@
dbussystemservicedir=@dbussystemservicedir@
pamlibdir=@pamlibdir@
pamconfdir=@pamconfdir@
pkgconfigdatadir=$(datadir)/pkgconfig
pkgconfiglibdir=$(libdir)/pkgconfig
polkitpolicydir=$(datadir)/polkit-1/actions
bashcompletiondir=@bashcompletiondir@
zshcompletiondir=@zshcompletiondir@
rpmmacrosdir=$(prefix)/lib/rpm/macros.d
varlogdir=$(localstatedir)/log
systemdstatedir=$(localstatedir)/lib/systemd

# Our own, non-special dirs
pkgsysconfdir=$(sysconfdir)/systemd
userunitdir=$(prefix)/lib/systemd/user
userpresetdir=$(prefix)/lib/systemd/user-preset
tmpfilesdir=$(prefix)/lib/tmpfiles.d
sysctldir=$(prefix)/lib/sysctl.d
networkdir=$(rootprefix)/lib/systemd/network
pkgincludedir=$(includedir)/systemd
systemgeneratordir=$(rootlibexecdir)/system-generators
usergeneratordir=$(prefix)/lib/systemd/user-generators
systemshutdowndir=$(rootlibexecdir)/system-shutdown
systemsleepdir=$(rootlibexecdir)/system-sleep
systemunitdir=$(rootprefix)/lib/systemd/system
systempresetdir=$(rootprefix)/lib/systemd/system-preset
udevlibexecdir=$(rootprefix)/lib/udev
udevhomedir=$(udevlibexecdir)
udevrulesdir=$(udevlibexecdir)/rules.d
kernelinstalldir = $(prefix)/lib/kernel/install.d

# And these are the special ones for /
rootprefix=@rootprefix@
rootbindir=$(rootprefix)/bin
rootlibexecdir=$(rootprefix)/lib/systemd

CLEANFILES = $(BUILT_SOURCES)
DISTCLEANFILES =
EXTRA_DIST =
BUILT_SOURCES =
INSTALL_EXEC_HOOKS =
UNINSTALL_EXEC_HOOKS =
INSTALL_DATA_HOOKS =
UNINSTALL_DATA_HOOKS =
DISTCLEAN_LOCAL_HOOKS =
CLEAN_LOCAL_HOOKS =
pkginclude_HEADERS =
noinst_LTLIBRARIES =
lib_LTLIBRARIES =
include_HEADERS =
noinst_DATA =
pkgconfiglib_DATA =
polkitpolicy_in_in_files =
polkitpolicy_in_files =
polkitpolicy_files =
dist_udevrules_DATA =
nodist_udevrules_DATA =
nodist_pkgsysconf_DATA =
dist_pkgsysconf_DATA =
dist_pkgdata_DATA =
dist_dbuspolicy_DATA =
dist_dbussystemservice_DATA =
check_PROGRAMS =
check_DATA =
tests=
manual_tests =
if ENABLE_TESTS
noinst_PROGRAMS = $(manual_tests) $(tests)
TESTS = $(tests)
else
noinst_PROGRAMS =
TESTS =
endif
udevlibexec_PROGRAMS =

.PHONY: $(INSTALL_EXEC_HOOKS) $(UNINSTALL_EXEC_HOOKS) \
	$(INSTALL_DATA_HOOKS) $(UNINSTALL_DATA_HOOKS) \
	$(DISTCLEAN_LOCAL_HOOKS) $(CLEAN_LOCAL_HOOKS)

AM_CPPFLAGS = \
	-include $(top_builddir)/config.h \
	-DPKGSYSCONFDIR=\"$(pkgsysconfdir)\" \
	-DSYSTEM_CONFIG_UNIT_PATH=\"$(pkgsysconfdir)/system\" \
	-DSYSTEM_DATA_UNIT_PATH=\"$(systemunitdir)\" \
	-DUSER_CONFIG_UNIT_PATH=\"$(pkgsysconfdir)/user\" \
	-DUSER_DATA_UNIT_PATH=\"$(userunitdir)\" \
	-DSYSTEMD_CGROUP_AGENT_PATH=\"$(rootlibexecdir)/systemd-cgroups-agent\" \
	-DSYSTEMD_BINARY_PATH=\"$(rootlibexecdir)/systemd\" \
	-DSYSTEMD_SHUTDOWN_BINARY_PATH=\"$(rootlibexecdir)/systemd-shutdown\" \
	-DSYSTEMD_SLEEP_BINARY_PATH=\"$(rootlibexecdir)/systemd-sleep\" \
	-DSYSTEMCTL_BINARY_PATH=\"$(rootbindir)/systemctl\" \
	-DSYSTEMD_TTY_ASK_PASSWORD_AGENT_BINARY_PATH=\"$(rootbindir)/systemd-tty-ask-password-agent\" \
	-DSYSTEMD_STDIO_BRIDGE_BINARY_PATH=\"$(bindir)/systemd-stdio-bridge\" \
	-DROOTPREFIX=\"$(rootprefix)\" \
	-DRANDOM_SEED_DIR=\"$(localstatedir)/lib/systemd/\" \
	-DRANDOM_SEED=\"$(localstatedir)/lib/systemd/random-seed\" \
	-DSYSTEM_GENERATOR_PATH=\"$(systemgeneratordir)\" \
	-DUSER_GENERATOR_PATH=\"$(usergeneratordir)\" \
	-DSYSTEM_SHUTDOWN_PATH=\"$(systemshutdowndir)\" \
	-DSYSTEM_SLEEP_PATH=\"$(systemsleepdir)\" \
	-DX_SERVER=\"$(bindir)/X\" \
	-DUDEVLIBEXECDIR=\"$(udevlibexecdir)\" \
	-DPOLKIT_AGENT_BINARY_PATH=\"$(bindir)/pkttyagent\" \
	-DQUOTACHECK=\"$(QUOTACHECK)\" \
	-DKEXEC=\"$(KEXEC)\" \
	-I $(top_srcdir)/src \
	-I $(top_builddir)/src/shared \
	-I $(top_srcdir)/src/shared \
	-I $(top_srcdir)/src/login \
	-I $(top_srcdir)/src/systemd \
	-I $(top_builddir)/src/core \
	-I $(top_srcdir)/src/core \
	-I $(top_srcdir)/src/libsystemd/sd-bus \
	-I $(top_srcdir)/src/libsystemd/sd-event \
	-I $(top_srcdir)/src/libsystemd/sd-rtnl \
	$(OUR_CPPFLAGS)

AM_CFLAGS = $(OUR_CFLAGS)
AM_LDFLAGS = $(OUR_LDFLAGS)

# ------------------------------------------------------------------------------
define move-to-rootlibdir
	if test "$(libdir)" != "$(rootlibdir)"; then \
		$(MKDIR_P) $(DESTDIR)$(rootlibdir) && \
		so_img_name=$$(readlink $(DESTDIR)$(libdir)/$$libname) && \
		rm -f $(DESTDIR)$(libdir)/$$libname && \
		$(LN_S) --relative -f $(DESTDIR)$(rootlibdir)/$$so_img_name $(DESTDIR)$(libdir)/$$libname && \
		mv $(DESTDIR)$(libdir)/$$libname.* $(DESTDIR)$(rootlibdir); \
	fi
endef

INSTALL_DIRS =

SHUTDOWN_TARGET_WANTS =
LOCAL_FS_TARGET_WANTS =
MULTI_USER_TARGET_WANTS =
SYSINIT_TARGET_WANTS =
SOCKETS_TARGET_WANTS =
BUSNAMES_TARGET_WANTS =
TIMERS_TARGET_WANTS =
USER_SOCKETS_TARGET_WANTS =
USER_BUSNAMES_TARGET_WANTS =

SYSTEM_UNIT_ALIASES =
USER_UNIT_ALIASES =
GENERAL_ALIASES =

install-target-wants-hook:
	what="$(SHUTDOWN_TARGET_WANTS)" && wants=shutdown.target && dir=$(systemunitdir) && $(add-wants)
	what="$(LOCAL_FS_TARGET_WANTS)" && wants=local-fs.target && dir=$(systemunitdir) && $(add-wants)
	what="$(MULTI_USER_TARGET_WANTS)" && wants=multi-user.target && dir=$(systemunitdir) && $(add-wants)
	what="$(SYSINIT_TARGET_WANTS)" && wants=sysinit.target && dir=$(systemunitdir) && $(add-wants)
	what="$(SOCKETS_TARGET_WANTS)" && wants=sockets.target && dir=$(systemunitdir) && $(add-wants)
	what="$(BUSNAMES_TARGET_WANTS)" && wants=busnames.target && dir=$(systemunitdir) && $(add-wants)
	what="$(TIMERS_TARGET_WANTS)" && wants=timers.target && dir=$(systemunitdir) && $(add-wants)
	what="$(SLICES_TARGET_WANTS)" && wants=slices.target && dir=$(systemunitdir) && $(add-wants)
	what="$(USER_SOCKETS_TARGET_WANTS)" && wants=sockets.target && dir=$(userunitdir) && $(add-wants)
	what="$(USER_BUSNAMES_TARGET_WANTS)" && wants=busnames.target && dir=$(userunitdir) && $(add-wants)

define add-wants
	[ -z "$$what" ] || ( \
	  dir=$(DESTDIR)$$dir/$$wants.wants && \
	  $(MKDIR_P) -m 0755 $$dir && \
	  cd $$dir && \
	  rm -f $$what && \
	  for i in $$what; do $(LN_S) ../$$i . || exit $$? ; done )
endef

install-directories-hook:
	$(MKDIR_P) $(addprefix $(DESTDIR),$(INSTALL_DIRS))

install-aliases-hook:
	set -- $(SYSTEM_UNIT_ALIASES) && \
		dir=$(systemunitdir) && $(install-aliases)
	set -- $(USER_UNIT_ALIASES) && \
		dir=$(userunitdir) && $(install-relative-aliases)
	set -- $(GENERAL_ALIASES) && \
		dir= && $(install-relative-aliases)

define install-aliases
	while [ -n "$$1" ]; do \
		$(MKDIR_P) `dirname $(DESTDIR)$$dir/$$2` && \
		rm -f $(DESTDIR)$$dir/$$2 && \
		$(LN_S) $$1 $(DESTDIR)$$dir/$$2 && \
		shift 2 || exit $$?; \
	done
endef

define install-relative-aliases
	while [ -n "$$1" ]; do \
		$(MKDIR_P) `dirname $(DESTDIR)$$dir/$$2` && \
		rm -f $(DESTDIR)$$dir/$$2 && \
		$(LN_S) --relative $(DESTDIR)$$1 $(DESTDIR)$$dir/$$2 && \
		shift 2 || exit $$?; \
	done
endef

INSTALL_EXEC_HOOKS += \
	install-target-wants-hook \
	install-directories-hook \
	install-aliases-hook

# ------------------------------------------------------------------------------
AM_V_M4 = $(AM_V_M4_$(V))
AM_V_M4_ = $(AM_V_M4_$(AM_DEFAULT_VERBOSITY))
AM_V_M4_0 = @echo "  M4      " $@;

AM_V_XSLT = $(AM_V_XSLT_$(V))
AM_V_XSLT_ = $(AM_V_XSLT_$(AM_DEFAULT_VERBOSITY))
AM_V_XSLT_0 = @echo "  XSLT    " $@;

AM_V_GPERF = $(AM_V_GPERF_$(V))
AM_V_GPERF_ = $(AM_V_GPERF_$(AM_DEFAULT_VERBOSITY))
AM_V_GPERF_0 = @echo "  GPERF   " $@;

AM_V_LN = $(AM_V_LN_$(V))
AM_V_LN_ = $(AM_V_LN_$(AM_DEFAULT_VERBOSITY))
AM_V_LN_0 = @echo "  LN      " $@;

AM_V_RM = $(AM_V_RM_$(V))
AM_V_RM_ = $(AM_V_RM_$(AM_DEFAULT_VERBOSITY))
AM_V_RM_0 = @echo "  RM      " $@;

# ------------------------------------------------------------------------------
rootbin_PROGRAMS = \
	systemctl \
	systemd-notify \
	systemd-ask-password \
	systemd-tty-ask-password-agent \
	systemd-machine-id-setup

bin_PROGRAMS = \
	systemd-cgls \
	systemd-cgtop \
	systemd-detect-virt \
	systemd-delta \
	systemd-analyze \
	systemd-run

dist_bin_SCRIPTS = \
	src/kernel-install/kernel-install

dist_kernelinstall_SCRIPTS = \
	src/kernel-install/50-depmod.install

rootlibexec_PROGRAMS = \
	systemd \
	systemd-cgroups-agent \
	systemd-initctl \
	systemd-update-utmp \
	systemd-shutdownd \
	systemd-shutdown \
	systemd-remount-fs \
	systemd-reply-password \
	systemd-fsck \
	systemd-ac-power \
	systemd-sleep \
	systemd-bus-proxyd \
	systemd-socket-proxyd

systemgenerator_PROGRAMS = \
	systemd-getty-generator

dist_bashcompletion_DATA = \
	shell-completion/bash/busctl \
	shell-completion/bash/systemctl \
	shell-completion/bash/systemd-analyze \
	shell-completion/bash/systemd-cgls \
	shell-completion/bash/systemd-cgtop \
	shell-completion/bash/systemd-delta \
	shell-completion/bash/systemd-detect-virt \
	shell-completion/bash/systemd-run \
	shell-completion/bash/kernel-install

dist_zshcompletion_DATA = \
	shell-completion/zsh/_systemctl \
	shell-completion/zsh/_kernel-install \
	shell-completion/zsh/_systemd-analyze \
	shell-completion/zsh/_systemd-run \
	shell-completion/zsh/_sd_hosts_or_user_at_host \
	shell-completion/zsh/_systemd-delta \
	shell-completion/zsh/_systemd

dist_sysctl_DATA = \
	sysctl.d/50-default.conf

dist_systemunit_DATA = \
	units/graphical.target \
	units/multi-user.target \
	units/emergency.service \
	units/emergency.target \
	units/sysinit.target \
	units/basic.target \
	units/getty.target \
	units/halt.target \
	units/kexec.target \
	units/local-fs.target \
	units/local-fs-pre.target \
	units/initrd.target \
	units/initrd-fs.target \
	units/initrd-root-fs.target \
	units/remote-fs.target \
	units/remote-fs-pre.target \
	units/network.target \
	units/network-pre.target \
	units/network-online.target \
	units/nss-lookup.target \
	units/nss-user-lookup.target \
	units/hibernate.target \
	units/hybrid-sleep.target \
	units/poweroff.target \
	units/reboot.target \
	units/rescue.target \
	units/rpcbind.target \
	units/time-sync.target \
	units/shutdown.target \
	units/final.target \
	units/umount.target \
	units/sigpwr.target \
	units/sleep.target \
	units/sockets.target \
	units/busnames.target \
	units/timers.target \
	units/paths.target \
	units/suspend.target \
	units/swap.target \
	units/slices.target \
	units/system.slice \
	units/x-.slice \
	units/systemd-initctl.socket \
	units/systemd-shutdownd.socket \
	units/dev-hugepages.mount \
	units/dev-mqueue.mount \
	units/sys-kernel-config.mount \
	units/sys-kernel-debug.mount \
	units/sys-fs-fuse-connections.mount \
	units/tmp.mount \
	units/printer.target \
	units/sound.target \
	units/bluetooth.target \
	units/smartcard.target \
	units/systemd-ask-password-wall.path \
	units/systemd-ask-password-console.path \
	units/initrd-switch-root.target

nodist_systemunit_DATA = \
	units/getty@.service \
	units/serial-getty@.service \
	units/console-shell.service \
	units/console-getty.service \
	units/container-getty@.service \
	units/systemd-initctl.service \
	units/systemd-shutdownd.service \
	units/systemd-remount-fs.service \
	units/systemd-update-utmp.service \
	units/systemd-update-utmp-runlevel.service \
	units/systemd-ask-password-wall.service \
	units/systemd-ask-password-console.service \
	units/sysctl.service \
	units/emergency.service \
	units/rescue.service \
	units/user@.service \
	units/systemd-hibernate.service \
	units/systemd-hybrid-sleep.service \
	units/systemd-suspend.service \
	units/systemd-halt.service \
	units/systemd-poweroff.service \
	units/systemd-reboot.service \
	units/systemd-kexec.service \
	units/systemd-fsck@.service \
	units/systemd-fsck-root.service \
	units/debug-shell.service \
	units/initrd-parse-etc.service \
	units/initrd-cleanup.service \
	units/initrd-switch-root.service

dist_userunit_DATA = \
	units/user/basic.target \
	units/user/default.target \
	units/user/exit.target

nodist_userunit_DATA = \
	units/user/systemd-exit.service

EXTRA_DIST += \
	units/getty@.service.m4 \
	units/serial-getty@.service.m4 \
	units/console-shell.service.m4.in \
	units/console-getty.service.m4.in \
	units/container-getty@.service.m4.in \
	units/rescue.service.m4.in \
	units/systemd-initctl.service.in \
	units/systemd-shutdownd.service.in \
	units/systemd-remount-fs.service.in \
	units/systemd-update-utmp.service.in \
	units/systemd-update-utmp-runlevel.service.in \
	units/systemd-ask-password-wall.service.in \
	units/systemd-ask-password-console.service.in \
	units/sysctl.service.in \
	units/emergency.service.in \
	units/systemd-halt.service.in \
	units/systemd-poweroff.service.in \
	units/systemd-reboot.service.in \
	units/systemd-kexec.service.in \
	units/user/systemd-exit.service.in \
	units/systemd-fsck@.service.in \
	units/systemd-fsck-root.service.in \
	units/user@.service.in \
	units/debug-shell.service.in \
	units/systemd-hibernate.service.in \
	units/systemd-hybrid-sleep.service.in \
	units/systemd-suspend.service.in \
	units/quotaon.service.in \
	units/initrd-parse-etc.service.in \
	units/initrd-cleanup.service.in \
	units/initrd-switch-root.service.in

CLEANFILES += \
	units/console-shell.service.m4 \
	units/console-getty.service.m4 \
	units/container-getty@.service.m4 \
	units/rescue.service.m4 \
	units/user@.service.m4

# automake is broken and can't handle files with a dash in front
# http://debbugs.gnu.org/cgi/bugreport.cgi?bug=14728#8
units-install-hook:
	mv $(DESTDIR)$(systemunitdir)/x-.slice $(DESTDIR)/$(systemunitdir)/-.slice

units-uninstall-hook:
	rm -f $(DESTDIR)/$(systemunitdir)/-.slice

INSTALL_DATA_HOOKS += units-install-hook
UNINSTALL_DATA_HOOKS += units-uninstall-hook

dist_doc_DATA = \
	README \
	NEWS \
	LICENSE.LGPL2.1 \
	LICENSE.GPL2 \
	LICENSE.MIT \
	DISTRO_PORTING \
	src/libsystemd/sd-bus/PORTING-DBUS1 \
	src/libsystemd/sd-bus/DIFFERENCES \
	src/libsystemd/sd-bus/GVARIANT-SERIALIZATION

@INTLTOOL_POLICY_RULE@

# ------------------------------------------------------------------------------

MANPAGES =
MANPAGES_ALIAS =

include Makefile-man.am

.PHONY: man update-man-list
man: $(MANPAGES) $(MANPAGES_ALIAS) $(HTML_FILES) $(HTML_ALIAS)

XML_FILES = \
	${patsubst %.1,%.xml,${patsubst %.3,%.xml,${patsubst %.5,%.xml,${patsubst %.7,%.xml,${patsubst %.8,%.xml,$(MANPAGES)}}}}}
HTML_FILES = \
	${XML_FILES:.xml=.html}
HTML_ALIAS = \
	${patsubst %.1,%.html,${patsubst %.3,%.html,${patsubst %.5,%.html,${patsubst %.7,%.html,${patsubst %.8,%.html,$(MANPAGES_ALIAS)}}}}}

if ENABLE_MANPAGES
man_MANS = \
	$(MANPAGES) \
	$(MANPAGES_ALIAS)

noinst_DATA += \
	$(HTML_FILES) \
	$(HTML_ALIAS)

CLEANFILES += \
	$(man_MANS) \
	$(HTML_FILES) \
	$(HTML_ALIAS)

docs/html/man:
	$(AM_V_at)$(MKDIR_P) $(dir $@)
	$(AM_V_LN)$(LN_S) -f ../../man $@

noinst_DATA += \
	docs/html/man

CLEANFILES += \
	docs/html/man

endif

EXTRA_DIST += \
	$(XML_FILES) \
	$(HTML_FILES) \
	$(HTML_ALIAS) \
	$(man_MANS)

# ------------------------------------------------------------------------------
noinst_LTLIBRARIES += \
	libsystemd-shared.la

libsystemd_shared_la_SOURCES = \
	src/shared/linux/auto_dev-ioctl.h \
	src/shared/linux/fanotify.h \
	src/shared/ioprio.h \
	src/shared/missing.h \
	src/shared/initreq.h \
	src/shared/securebits.h \
	src/shared/special.h \
	src/shared/list.h \
	src/shared/macro.h \
	src/shared/def.h \
	src/shared/sparse-endian.h \
	src/shared/refcnt.h \
	src/shared/udev-util.h \
	src/shared/bus-errors.h \
	src/shared/device-nodes.c \
	src/shared/device-nodes.h \
	src/shared/util.c \
	src/shared/util.h \
	src/shared/virt.c \
	src/shared/virt.h \
	src/shared/architecture.c \
	src/shared/architecture.h \
	src/shared/efivars.c \
	src/shared/efivars.h \
	src/shared/path-util.c \
	src/shared/path-util.h \
	src/shared/time-util.c \
	src/shared/time-util.h \
	src/shared/hashmap.c \
	src/shared/hashmap.h \
	src/shared/siphash24.c \
	src/shared/siphash24.h \
	src/shared/set.c \
	src/shared/set.h \
	src/shared/fdset.c \
	src/shared/fdset.h \
	src/shared/prioq.c \
	src/shared/prioq.h \
	src/shared/sleep-config.c \
	src/shared/sleep-config.h \
	src/shared/strv.c \
	src/shared/strv.h \
	src/shared/env-util.c \
	src/shared/env-util.h \
	src/shared/strbuf.c \
	src/shared/strbuf.h \
	src/shared/strxcpyx.c \
	src/shared/strxcpyx.h \
	src/shared/conf-parser.c \
	src/shared/conf-parser.h \
	src/shared/log.c \
	src/shared/log.h \
	src/shared/ratelimit.h \
	src/shared/ratelimit.c \
	src/shared/exit-status.c \
	src/shared/exit-status.h \
	src/shared/utf8.c \
	src/shared/utf8.h \
	src/shared/gunicode.c \
	src/shared/gunicode.h \
	src/shared/pager.c \
	src/shared/pager.h \
	src/shared/socket-util.c \
	src/shared/socket-util.h \
	src/shared/conf-files.c \
	src/shared/conf-files.h \
	src/shared/cgroup-util.c \
	src/shared/cgroup-util.h \
	src/shared/cgroup-show.c \
	src/shared/cgroup-show.h \
	src/shared/unit-name.c \
	src/shared/unit-name.h \
	src/shared/utmp-wtmp.c \
	src/shared/utmp-wtmp.h \
	src/shared/watchdog.c \
	src/shared/watchdog.h \
	src/shared/spawn-ask-password-agent.c \
	src/shared/spawn-ask-password-agent.h \
	src/shared/replace-var.c \
	src/shared/replace-var.h \
	src/shared/spawn-polkit-agent.c \
	src/shared/spawn-polkit-agent.h \
	src/shared/clock-util.c \
	src/shared/clock-util.h \
	src/shared/time-dst.c \
	src/shared/time-dst.h \
	src/shared/calendarspec.c \
	src/shared/calendarspec.h \
	src/shared/fileio.c \
	src/shared/fileio.h \
	src/shared/output-mode.h \
	src/shared/MurmurHash2.c \
	src/shared/MurmurHash2.h \
	src/shared/acpi-fpdt.h \
	src/shared/acpi-fpdt.c \
	src/shared/boot-timestamps.h \
	src/shared/boot-timestamps.c \
	src/shared/mkdir.c \
	src/shared/mkdir.h \
	src/shared/smack-util.c \
	src/shared/smack-util.h \
	src/shared/apparmor-util.c \
	src/shared/apparmor-util.h \
	src/shared/ima-util.c \
	src/shared/ima-util.h \
	src/shared/ptyfwd.c \
	src/shared/ptyfwd.h \
	src/shared/errno-list.c \
	src/shared/errno-list.h \
	src/shared/af-list.c \
	src/shared/af-list.h \
	src/shared/audit.c \
	src/shared/audit.h \
	src/shared/xml.c \
	src/shared/xml.h \
	src/shared/condition-util.c \
	src/shared/condition-util.h \
	src/shared/bus-label.c \
	src/shared/bus-label.h \
	src/shared/generator.h \
	src/shared/generator.c \
	src/shared/clean-ipc.h \
	src/shared/clean-ipc.c \
	src/shared/login-shared.c \
	src/shared/login-shared.h \
	src/shared/ring.c \
	src/shared/ring.h \
	src/shared/async.c \
	src/shared/async.h \
	src/shared/eventfd-util.c \
	src/shared/eventfd-util.h \
	src/shared/copy.c \
	src/shared/copy.h

nodist_libsystemd_shared_la_SOURCES = \
	src/shared/errno-from-name.h \
	src/shared/errno-to-name.h \
	src/shared/af-from-name.h \
	src/shared/af-to-name.h

libsystemd_shared_la_CFLAGS = \
	$(AM_CFLAGS) \
	$(SECCOMP_CFLAGS)

# ------------------------------------------------------------------------------
noinst_LTLIBRARIES += \
	libsystemd-units.la

libsystemd_units_la_SOURCES = \
	src/shared/install.c \
	src/shared/install.h \
	src/shared/install-printf.c \
	src/shared/install-printf.h \
	src/shared/path-lookup.c \
	src/shared/path-lookup.h \
	src/shared/specifier.c \
	src/shared/specifier.h

# ------------------------------------------------------------------------------
noinst_LTLIBRARIES += \
	libsystemd-label.la

libsystemd_label_la_SOURCES = \
	src/shared/socket-label.c \
	src/shared/label.c \
	src/shared/label.h \
	src/shared/selinux-util.c \
	src/shared/selinux-util.h \
	src/shared/mkdir-label.c \
	src/shared/ask-password-api.c \
	src/shared/ask-password-api.h \
	src/shared/fileio-label.c \
	src/shared/fileio-label.h \
	src/shared/dev-setup.c \
	src/shared/dev-setup.h

libsystemd_label_la_CFLAGS = \
	$(AM_CFLAGS) \
	$(SELINUX_CFLAGS)

libsystemd_label_la_LIBADD = \
	$(SELINUX_LIBS)

# ------------------------------------------------------------------------------

if HAVE_SECCOMP
noinst_LTLIBRARIES += \
	libsystemd-seccomp.la

libsystemd_seccomp_la_SOURCES = \
	src/shared/seccomp-util.h \
	src/shared/seccomp-util.c

libsystemd_seccomp_la_CFLAGS = \
	$(AM_CFLAGS) \
	$(SECCOMP_CFLAGS)

libsystemd_seccomp_la_LIBADD = \
	$(SECCOMP_LIBS)
endif

# ------------------------------------------------------------------------------
noinst_LTLIBRARIES += \
	libsystemd-capability.la

libsystemd_capability_la_SOURCES = \
	src/shared/capability.c \
	src/shared/capability.h

libsystemd_capability_la_CFLAGS = \
	$(AM_CFLAGS) \
	$(CAP_CFLAGS)

libsystemd_capability_la_LIBADD = \
	$(CAP_LIBS)

# ------------------------------------------------------------------------------
noinst_LTLIBRARIES += \
	libsystemd-core.la

libsystemd_core_la_SOURCES = \
	src/core/unit.c \
	src/core/unit.h \
	src/core/unit-printf.c \
	src/core/unit-printf.h \
	src/core/job.c \
	src/core/job.h \
	src/core/manager.c \
	src/core/manager.h \
	src/core/transaction.c \
	src/core/transaction.h \
	src/core/load-fragment.c \
	src/core/load-fragment.h \
	src/core/service.c \
	src/core/service.h \
	src/core/socket.c \
	src/core/socket.h \
	src/core/busname.c \
	src/core/busname.h \
	src/core/target.c \
	src/core/target.h \
	src/core/snapshot.c \
	src/core/snapshot.h \
	src/core/device.c \
	src/core/device.h \
	src/core/mount.c \
	src/core/mount.h \
	src/core/automount.c \
	src/core/automount.h \
	src/core/swap.c \
	src/core/swap.h \
	src/core/timer.c \
	src/core/timer.h \
	src/core/path.c \
	src/core/path.h \
	src/core/slice.c \
	src/core/slice.h \
	src/core/scope.c \
	src/core/scope.h \
	src/core/load-dropin.c \
	src/core/load-dropin.h \
	src/core/execute.c \
	src/core/execute.h \
	src/core/kill.c \
	src/core/kill.h \
	src/core/dbus.c \
	src/core/dbus.h \
	src/core/dbus-manager.c \
	src/core/dbus-manager.h \
	src/core/dbus-unit.c \
	src/core/dbus-unit.h \
	src/core/dbus-job.c \
	src/core/dbus-job.h \
	src/core/dbus-service.c \
	src/core/dbus-service.h \
	src/core/dbus-socket.c \
	src/core/dbus-socket.h \
	src/core/dbus-busname.c \
	src/core/dbus-busname.h \
	src/core/dbus-target.c \
	src/core/dbus-target.h \
	src/core/dbus-snapshot.c \
	src/core/dbus-snapshot.h \
	src/core/dbus-device.c \
	src/core/dbus-device.h \
	src/core/dbus-mount.c \
	src/core/dbus-mount.h \
	src/core/dbus-automount.c \
	src/core/dbus-automount.h \
	src/core/dbus-swap.c \
	src/core/dbus-swap.h \
	src/core/dbus-timer.c \
	src/core/dbus-timer.h \
	src/core/dbus-path.c \
	src/core/dbus-path.h \
	src/core/dbus-slice.c \
	src/core/dbus-slice.h \
	src/core/dbus-scope.c \
	src/core/dbus-scope.h \
	src/core/dbus-execute.c \
	src/core/dbus-execute.h \
	src/core/dbus-kill.c \
	src/core/dbus-kill.h \
	src/core/dbus-cgroup.c \
	src/core/dbus-cgroup.h \
	src/core/cgroup.c \
	src/core/cgroup.h \
	src/core/selinux-access.c \
	src/core/selinux-access.h \
	src/core/selinux-setup.c \
	src/core/selinux-setup.h \
	src/core/smack-setup.c \
	src/core/smack-setup.h \
	src/core/ima-setup.c \
	src/core/ima-setup.h \
	src/core/locale-setup.h \
	src/core/locale-setup.c \
	src/core/machine-id-setup.c \
	src/core/machine-id-setup.h \
	src/core/mount-setup.c \
	src/core/mount-setup.h \
	src/core/loopback-setup.h \
	src/core/loopback-setup.c \
	src/core/condition.c \
	src/core/condition.h \
	src/core/namespace.c \
	src/core/namespace.h \
	src/core/build.h \
	src/core/sysfs-show.h \
	src/core/switch-root.h \
	src/core/switch-root.c \
	src/core/killall.h \
	src/core/killall.c \
	src/core/audit-fd.c \
	src/core/audit-fd.h \
	src/core/show-status.c \
	src/core/show-status.h

if HAVE_KMOD
libsystemd_core_la_SOURCES += \
	src/core/kmod-setup.c \
	src/core/kmod-setup.h
endif

nodist_libsystemd_core_la_SOURCES = \
	src/core/load-fragment-gperf.c \
	src/core/load-fragment-gperf-nulstr.c

libsystemd_core_la_CFLAGS = \
	$(AM_CFLAGS) \
	$(LIBUDEV_CFLAGS) \
	$(PAM_CFLAGS) \
	$(AUDIT_CFLAGS) \
	$(CAP_CFLAGS) \
	$(KMOD_CFLAGS) \
	$(APPARMOR_CFLAGS) \
	$(SECCOMP_CFLAGS) \
	-pthread

libsystemd_core_la_LIBADD = \
	libsystemd-capability.la \
	libsystemd-units.la \
	libsystemd-label.la \
	$(LIBUDEV_LIBS) \
	libsystemd-shared.la \
	libsystemd-internal.la \
	$(PAM_LIBS) \
	$(AUDIT_LIBS) \
	$(CAP_LIBS) \
	$(KMOD_LIBS) \
	$(APPARMOR_LIBS) \
	$(SECCOMP_LIBS)

if HAVE_SECCOMP
libsystemd_core_la_LIBADD += \
	libsystemd-seccomp.la
endif

src/core/load-fragment-gperf-nulstr.c: src/core/load-fragment-gperf.gperf
	$(AM_V_at)$(MKDIR_P) $(dir $@)
	$(AM_V_GEN)$(AWK) 'BEGIN{ keywords=0 ; FS="," ; print "extern const char load_fragment_gperf_nulstr[];" ; print "const char load_fragment_gperf_nulstr[] ="} ; keyword==1 { print "\"" $$1 "\\0\"" } ; /%%/ { keyword=1} ; END { print ";" }' < $< > $@

EXTRA_DIST += \
	src/core/load-fragment-gperf.gperf.m4

CLEANFILES += \
	src/core/load-fragment-gperf.gperf \
	src/core/load-fragment-gperf.c \
	src/core/load-fragment-gperf-nulstr.c \
	src/shared/errno-list.txt \
	src/shared/errno-from-name.gperf \
	src/shared/af-list.txt \
	src/shared/af-from-name.gperf

BUILT_SOURCES += \
	src/shared/errno-from-name.h \
	src/shared/errno-to-name.h \
	src/shared/af-from-name.h \
	src/shared/af-to-name.h

src/shared/errno-list.txt:
	$(AM_V_at)$(MKDIR_P) $(dir $@)
	$(AM_V_GEN)$(CPP) $(CFLAGS) $(AM_CPPFLAGS) $(CPPFLAGS) -dM -include errno.h - < /dev/null | $(AWK) '/^#define[ \t]+E[^ _]+[ \t]+/ { print $$2; }'  > $@

src/shared/errno-from-name.gperf: src/shared/errno-list.txt
	$(AM_V_at)$(MKDIR_P) $(dir $@)
	$(AM_V_GEN)$(AWK) 'BEGIN{ print "struct errno_name { const char* name; int id; };"; print "%null-strings"; print "%%";} { printf "%s, %s\n", $$1, $$1 }' < $< > $@

src/shared/errno-from-name.h: src/shared/errno-from-name.gperf
	$(AM_V_at)$(MKDIR_P) $(dir $@)
	$(AM_V_GPERF)$(GPERF) -L ANSI-C -t --ignore-case -N lookup_errno -H hash_errno_name -p -C < $< > $@

src/shared/errno-to-name.h: src/shared/errno-list.txt
	$(AM_V_at)$(MKDIR_P) $(dir $@)
	$(AM_V_GEN)$(AWK) 'BEGIN{ print "static const char* const errno_names[] = { "} !/EDEADLOCK/ && !/EWOULDBLOCK/ && !/ENOTSUP/ { printf "[%s] = \"%s\",\n", $$1, $$1 } END{print "};"}' < $< > $@

src/shared/af-list.txt:
	$(AM_V_at)$(MKDIR_P) $(dir $@)
	$(AM_V_GEN)$(CPP) $(CFLAGS) $(AM_CPPFLAGS) $(CPPFLAGS) -dM -include sys/socket.h - < /dev/null | grep -v AF_UNSPEC | grep -v AF_MAX | $(AWK) '/^#define[ \t]+AF_[^ \t]+[ \t]+PF_[^ \t]/ { print $$2; }'  > $@

src/shared/af-from-name.gperf: src/shared/af-list.txt
	$(AM_V_at)$(MKDIR_P) $(dir $@)
	$(AM_V_GEN)$(AWK) 'BEGIN{ print "struct af_name { const char* name; int id; };"; print "%null-strings"; print "%%";} { printf "%s, %s\n", $$1, $$1 }' < $< > $@

src/shared/af-from-name.h: src/shared/af-from-name.gperf
	$(AM_V_at)$(MKDIR_P) $(dir $@)
	$(AM_V_GPERF)$(GPERF) -L ANSI-C -t --ignore-case -N lookup_af -H hash_af_name -p -C < $< > $@

src/shared/af-to-name.h: src/shared/af-list.txt
	$(AM_V_at)$(MKDIR_P) $(dir $@)
	$(AM_V_GEN)$(AWK) 'BEGIN{ print "static const char* const af_names[] = { "} !/AF_FILE/ && !/AF_ROUTE/ && !/AF_LOCAL/ { printf "[%s] = \"%s\",\n", $$1, $$1 } END{print "};"}' < $< > $@

# ------------------------------------------------------------------------------
systemd_SOURCES = \
	src/core/main.c

systemd_CFLAGS = \
	$(AM_CFLAGS) \
	$(SECCOMP_CFLAGS)

systemd_LDADD = \
	libsystemd-core.la \
	$(RT_LIBS)

dist_pkgsysconf_DATA += \
	src/core/system.conf \
	src/core/user.conf

dist_dbuspolicy_DATA += \
	src/core/org.freedesktop.systemd1.conf

dist_dbussystemservice_DATA += \
	src/core/org.freedesktop.systemd1.service

polkitpolicy_in_in_files += \
	src/core/org.freedesktop.systemd1.policy.in.in

pkgconfigdata_DATA = \
	src/core/systemd.pc

nodist_rpmmacros_DATA = \
	src/core/macros.systemd

EXTRA_DIST += \
	src/core/systemd.pc.in \
	src/core/macros.systemd.in

CLEANFILES += \
	src/core/macros.systemd \
	src/core/org.freedesktop.systemd1.policy.in

# ------------------------------------------------------------------------------
manual_tests += \
	test-engine \
	test-ns \
	test-loopback \
	test-daemon \
	test-cgroup \
	test-cgroup-mask \
	test-install \
	test-watchdog \
	test-log \
	test-ipcrm

if HAVE_KMOD
manual_tests += \
	test-rtnl-manual
endif

tests += \
	test-job-type \
	test-env-replace \
	test-strbuf \
	test-strv \
	test-path-util \
	test-strxcpyx \
	test-unit-name \
	test-unit-file \
	test-utf8 \
	test-ellipsize \
	test-util \
	test-ring \
	test-tmpfiles \
	test-namespace \
	test-date \
	test-sleep \
	test-replace-var \
	test-sched-prio \
	test-calendarspec \
	test-strip-tab-ansi \
	test-cgroup-util \
	test-prioq \
	test-fileio \
	test-time \
	test-hashmap \
	test-list \
	test-tables \
	test-device-nodes \
	test-xml \
	test-architecture

EXTRA_DIST += \
	test/sched_idle_bad.service \
	test/sched_idle_ok.service \
	test/sched_rr_bad.service \
	test/sched_rr_ok.service \
	test/sched_rr_change.service \
	test/son.service \
	test/daughter.service \
	test/parent.slice

EXTRA_DIST += \
	src/test/test-helper.h

test_device_nodes_SOURCES = \
	src/test/test-device-nodes.c

test_device_nodes_LDADD = \
	libsystemd-shared.la

test_engine_SOURCES = \
	src/test/test-engine.c

test_engine_CFLAGS = \
	$(AM_CFLAGS) \
	$(SECCOMP_CFLAGS)

test_engine_LDADD = \
	libsystemd-core.la \
	$(RT_LIBS)

test_job_type_SOURCES = \
	src/test/test-job-type.c

test_job_type_CFLAGS = \
	$(AM_CFLAGS) \
	$(SECCOMP_CFLAGS)

test_job_type_LDADD = \
	libsystemd-core.la \
	$(RT_LIBS)

test_ns_SOURCES = \
	src/test/test-ns.c

test_ns_CFLAGS = \
	$(AM_CFLAGS) \
	$(SECCOMP_CFLAGS)

test_ns_LDADD = \
	libsystemd-core.la

test_loopback_SOURCES = \
	src/test/test-loopback.c

test_loopback_LDADD = \
	libsystemd-core.la

if ENABLE_EFI
manual_tests += \
	test-boot-timestamp

test_boot_timestamp_SOURCES = \
	src/test/test-boot-timestamps.c

test_boot_timestamp_LDADD = \
	libsystemd-shared.la
endif

test_unit_name_SOURCES = \
	src/test/test-unit-name.c

test_unit_name_CFLAGS = \
	$(AM_CFLAGS) \
	$(SECCOMP_CFLAGS)

test_unit_name_LDADD = \
	libsystemd-core.la \
	$(RT_LIBS)

test_unit_file_SOURCES = \
	src/test/test-unit-file.c

test_unit_file_CFLAGS = \
	$(AM_CFLAGS) \
	$(SECCOMP_CFLAGS)

test_unit_file_LDADD = \
	libsystemd-core.la \
	$(RT_LIBS)

test_utf8_SOURCES = \
	src/test/test-utf8.c

test_utf8_LDADD = \
	libsystemd-shared.la

test_util_SOURCES = \
	src/test/test-util.c

test_util_LDADD = \
	libsystemd-core.la

test_ring_SOURCES = \
	src/test/test-ring.c

test_ring_LDADD = \
	libsystemd-core.la

test_tmpfiles_SOURCES = \
	src/test/test-tmpfiles.c

test_tmpfiles_LDADD = \
	libsystemd-shared.la

test_namespace_SOURCES = \
	src/test/test-namespace.c

test_namespace_LDADD = \
	libsystemd-core.la

test_hashmap_SOURCES = \
	src/test/test-hashmap.c

test_hashmap_LDADD = \
	libsystemd-core.la

test_xml_SOURCES = \
	src/test/test-xml.c

test_xml_LDADD = \
	libsystemd-shared.la

test_list_SOURCES = \
	src/test/test-list.c

test_list_LDADD = \
	libsystemd-core.la

test_tables_SOURCES = \
	src/test/test-tables.c \
	src/shared/test-tables.h

test_tables_CFLAGS = \
	$(AM_CFLAGS) \
	$(SECCOMP_CFLAGS)

test_tables_LDADD = \
	libsystemd-core.la \
	$(RT_LIBS)

test_prioq_SOURCES = \
	src/test/test-prioq.c

test_prioq_LDADD = \
	libsystemd-core.la

test_fileio_SOURCES = \
	src/test/test-fileio.c

test_fileio_LDADD = \
	libsystemd-core.la

test_time_SOURCES = \
	src/test/test-time.c

test_time_LDADD = \
	libsystemd-core.la

test_architecture_SOURCES = \
	src/test/test-architecture.c

test_architecture_LDADD = \
	libsystemd-shared.la

test_log_SOURCES = \
	src/test/test-log.c

test_log_LDADD = \
	libsystemd-core.la

test_ipcrm_SOURCES = \
	src/test/test-ipcrm.c

test_ipcrm_LDADD = \
	libsystemd-shared.la \
	-lrt

test_rtnl_manual_SOURCES = \
	src/test/test-rtnl-manual.c

test_rtnl_manual_CFLAGS = \
	$(AM_CFLAGS) \
	$(KMOD_CFLAGS)

test_rtnl_manual_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la \
	$(KMOD_LIBS)

test_ellipsize_SOURCES = \
	src/test/test-ellipsize.c

test_ellipsize_LDADD = \
	libsystemd-core.la

test_date_SOURCES = \
	src/test/test-date.c

test_date_LDADD = \
	libsystemd-core.la

test_sleep_SOURCES = \
	src/test/test-sleep.c

test_sleep_LDADD = \
	libsystemd-core.la

test_replace_var_SOURCES = \
	src/test/test-replace-var.c

test_replace_var_LDADD = \
	libsystemd-shared.la

test_calendarspec_SOURCES = \
	src/test/test-calendarspec.c

test_calendarspec_LDADD = \
	libsystemd-shared.la

test_strip_tab_ansi_SOURCES = \
	src/test/test-strip-tab-ansi.c

test_strip_tab_ansi_LDADD = \
	libsystemd-shared.la

test_daemon_SOURCES = \
	src/test/test-daemon.c

test_daemon_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

test_cgroup_SOURCES = \
	src/test/test-cgroup.c

test_cgroup_LDADD = \
	libsystemd-label.la \
	libsystemd-shared.la \
	libsystemd-internal.la

test_cgroup_mask_SOURCES = \
	src/test/test-cgroup-mask.c

test_cgroup_mask_CPPFLAGS = \
	$(AM_CPPFLAGS) \
	-DTEST_DIR=\"$(abs_top_srcdir)/test\"

test_cgroup_mask_CFLAGS = \
	$(AM_CFLAGS) \
	$(SECCOMP_CFLAGS)

test_cgroup_mask_LDADD = \
	libsystemd-core.la \
	$(RT_LIBS)

test_cgroup_util_SOURCES = \
	src/test/test-cgroup-util.c

test_cgroup_util_LDADD = \
	libsystemd-label.la \
	libsystemd-internal.la \
	libsystemd-shared.la

test_env_replace_SOURCES = \
	src/test/test-env-replace.c

test_env_replace_LDADD = \
	libsystemd-shared.la

test_strbuf_SOURCES = \
	src/test/test-strbuf.c

test_strbuf_LDADD = \
	libsystemd-shared.la

test_strv_SOURCES = \
	src/test/test-strv.c

test_strv_LDADD = \
	libsystemd-units.la \
	libsystemd-internal.la \
	libsystemd-shared.la

test_path_util_SOURCES = \
	src/test/test-path-util.c

test_path_util_LDADD = \
	libsystemd-shared.la

test_strxcpyx_SOURCES = \
	src/test/test-strxcpyx.c

test_strxcpyx_LDADD = \
	libsystemd-shared.la

test_install_SOURCES = \
	src/test/test-install.c

test_install_LDADD = \
	libsystemd-units.la \
	libsystemd-label.la \
	libsystemd-shared.la \
	libsystemd-internal.la

test_watchdog_SOURCES = \
	src/test/test-watchdog.c

test_watchdog_LDADD = \
	libsystemd-shared.la

test_sched_prio_SOURCES = \
	src/test/test-sched-prio.c

test_sched_prio_CPPFLAGS = \
	$(AM_CPPFLAGS) \
	-DTEST_DIR=\"$(abs_top_srcdir)/test\"

test_sched_prio_CFLAGS = \
	$(AM_CFLAGS) \
	$(SECCOMP_CFLAGS)

test_sched_prio_LDADD = \
	libsystemd-core.la \
	$(RT_LIBS)

# ------------------------------------------------------------------------------
## .PHONY so it always rebuilds it
.PHONY: coverage lcov-run lcov-report coverage-sync

# run lcov from scratch, always
coverage:
	$(MAKE) lcov-run
	$(MAKE) lcov-report

coverage_dir = coverage
coverage_opts = --base-directory $(srcdir) --directory $(builddir) --rc 'geninfo_adjust_src_path=$(abspath $(srcdir))=>$(abspath $(builddir))'

if ENABLE_COVERAGE
# reset run coverage tests
lcov-run:
	@rm -rf $(coverage_dir)
	lcov $(coverage_opts) --zerocounters
	-$(MAKE) check

# generate report based on current coverage data
lcov-report:
	$(MKDIR_P) $(coverage_dir)
	lcov $(coverage_opts) --compat-libtool --capture --no-external \
		| sed 's|$(abspath $(builddir))|$(abspath $(srcdir))|' > $(coverage_dir)/.lcov.info
	genhtml -t "systemd test coverage" -o $(coverage_dir) $(coverage_dir)/.lcov.info
	@echo "Coverage report generated in $(abs_builddir)/$(coverage_dir)/index.html"

# lcov doesn't work properly with vpath builds, make sure that bad
# output is not uploaded by mistake.
coverage-sync: coverage
	test "$(builddir)" = "$(srcdir)"
	rsync -rlv --delete --omit-dir-times coverage/ $(www_target)/coverage

else
lcov-run lcov-report:
	echo "Need to reconfigure with --enable-coverage"
endif

# ------------------------------------------------------------------------------
systemd_analyze_SOURCES = \
	src/analyze/analyze.c

systemd_analyze_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

# ------------------------------------------------------------------------------
systemd_initctl_SOURCES = \
	src/initctl/initctl.c

systemd_initctl_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

# ------------------------------------------------------------------------------
systemd_update_utmp_SOURCES = \
	src/update-utmp/update-utmp.c

systemd_update_utmp_CFLAGS = \
	$(AM_CFLAGS) \
	$(AUDIT_CFLAGS)

systemd_update_utmp_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la \
	$(AUDIT_LIBS)

# ------------------------------------------------------------------------------
systemd_shutdownd_SOURCES = \
	src/shutdownd/shutdownd.c

systemd_shutdownd_LDADD = \
	libsystemd-label.la \
	libsystemd-internal.la \
	libsystemd-shared.la

dist_doc_DATA += \
	src/systemd/sd-shutdown.h

# ------------------------------------------------------------------------------
systemd_shutdown_SOURCES = \
	src/core/umount.c \
	src/core/umount.h \
	src/core/shutdown.c \
	src/core/mount-setup.c \
	src/core/mount-setup.h \
	src/core/killall.h \
	src/core/killall.c

systemd_shutdown_CFLAGS = \
	$(AM_CFLAGS) \
	$(UDEV_FLAGS)

systemd_shutdown_LDADD = \
	libsystemd-label.la \
	$(LIBUDEV_LIBS) \
	libsystemd-shared.la

# ------------------------------------------------------------------------------
if HAVE_KMOD
systemd_modules_load_SOURCES = \
	src/modules-load/modules-load.c

systemd_modules_load_CFLAGS = \
	$(AM_CFLAGS) \
	$(KMOD_CFLAGS)

systemd_modules_load_LDADD = \
	libsystemd-shared.la \
	$(KMOD_LIBS)

rootlibexec_PROGRAMS += \
	systemd-modules-load

nodist_systemunit_DATA += \
	units/systemd-modules-load.service

SYSINIT_TARGET_WANTS += \
	systemd-modules-load.service

if ENABLE_TMPFILES
nodist_systemunit_DATA += \
	units/kmod-static-nodes.service

SYSINIT_TARGET_WANTS += \
	kmod-static-nodes.service
endif
endif

EXTRA_DIST += \
	units/systemd-modules-load.service.in \
	units/kmod-static-nodes.service.in

# ------------------------------------------------------------------------------
if ENABLE_TMPFILES
systemd_tmpfiles_SOURCES = \
	src/tmpfiles/tmpfiles.c

systemd_tmpfiles_LDADD = \
	libsystemd-units.la \
	libsystemd-label.la \
	libsystemd-capability.la \
	libsystemd-internal.la \
	libsystemd-shared.la

rootbin_PROGRAMS += \
	systemd-tmpfiles

dist_systemunit_DATA += \
	units/systemd-tmpfiles-clean.timer

nodist_systemunit_DATA += \
	units/systemd-tmpfiles-setup-dev.service \
	units/systemd-tmpfiles-setup.service \
	units/systemd-tmpfiles-clean.service

dist_tmpfiles_DATA = \
	tmpfiles.d/systemd.conf \
	tmpfiles.d/systemd-nologin.conf \
	tmpfiles.d/tmp.conf \
	tmpfiles.d/x11.conf \
	tmpfiles.d/var.conf

SYSINIT_TARGET_WANTS += \
	systemd-tmpfiles-setup-dev.service \
	systemd-tmpfiles-setup.service

dist_zshcompletion_DATA += \
	shell-completion/zsh/_systemd-tmpfiles

TIMERS_TARGET_WANTS += \
	systemd-tmpfiles-clean.timer

INSTALL_DIRS += \
	$(tmpfilesdir) \
	$(sysconfdir)/tmpfiles.d
endif

EXTRA_DIST += \
	units/systemd-tmpfiles-setup-dev.service.in \
	units/systemd-tmpfiles-setup.service.in \
	units/systemd-tmpfiles-clean.service.in

# ------------------------------------------------------------------------------
systemd_machine_id_setup_SOURCES = \
	src/machine-id-setup/machine-id-setup-main.c \
	src/core/machine-id-setup.c \
	src/core/machine-id-setup.h

systemd_machine_id_setup_LDADD = \
	libsystemd-label.la \
	libsystemd-internal.la \
	libsystemd-shared.la

# ------------------------------------------------------------------------------
systemd_sleep_SOURCES = \
	src/sleep/sleep.c

systemd_sleep_LDADD = \
	libsystemd-shared.la

# ------------------------------------------------------------------------------
systemd_fsck_SOURCES = \
	src/fsck/fsck.c

systemd_fsck_CFLAGS = \
	$(AM_CFLAGS) \
	$(LIBUDEV_CFLAGS)

systemd_fsck_LDADD = \
	libsystemd-internal.la \
	$(LIBUDEV_LIBS) \
	libsystemd-shared.la

# ------------------------------------------------------------------------------
systemd_ac_power_SOURCES = \
	src/ac-power/ac-power.c

systemd_ac_power_CFLAGS = \
	$(AM_CFLAGS) \
	$(LIBUDEV_CFLAGS)

systemd_ac_power_LDADD = \
	$(LIBUDEV_LIBS) \
	libsystemd-shared.la

# ------------------------------------------------------------------------------
systemd_detect_virt_SOURCES = \
	src/detect-virt/detect-virt.c

systemd_detect_virt_LDADD = \
	libsystemd-shared.la

systemd-detect-virt-install-hook:
	-$(SETCAP) cap_dac_override,cap_sys_ptrace=ep $(DESTDIR)$(bindir)/systemd-detect-virt

INSTALL_EXEC_HOOKS += \
	systemd-detect-virt-install-hook

# ------------------------------------------------------------------------------
systemd_delta_SOURCES = \
	src/delta/delta.c

systemd_delta_LDADD = \
	libsystemd-shared.la

# ------------------------------------------------------------------------------
systemd_getty_generator_SOURCES = \
	src/getty-generator/getty-generator.c

systemd_getty_generator_LDADD = \
	libsystemd-label.la \
	libsystemd-shared.la

# ------------------------------------------------------------------------------
if ENABLE_EFI
bootctl_SOURCES = \
	src/boot/boot.h \
	src/boot/boot-loader.h \
	src/boot/bootctl.c \
	src/boot/boot-loader.c \
	src/boot/boot-efi.c

bootctl_LDADD = \
	libsystemd-shared.la \
	libsystemd-internal.la

bin_PROGRAMS += \
	bootctl

dist_bashcompletion_DATA += \
	shell-completion/bash/bootctl

dist_zshcompletion_DATA += \
	shell-completion/zsh/_bootctl

endif

# ------------------------------------------------------------------------------
if ENABLE_KDBUS
systemgenerator_PROGRAMS +=  \
	systemd-dbus1-generator

systemd_dbus1_generator_SOURCES = \
	src/dbus1-generator/dbus1-generator.c

systemd_dbus1_generator_LDADD = \
	libsystemd-label.la \
	libsystemd-shared.la \
	libsystemd-internal.la

dbus1-generator-install-hook:
	$(AM_V_at)$(MKDIR_P) $(DESTDIR)$(usergeneratordir)
	$(AM_V_RM)rm -f $(DESTDIR)$(usergeneratordir)/systemd-dbus1-generator
	$(AM_V_LN)$(LN_S) --relative -f $(DESTDIR)$(systemgeneratordir)/systemd-dbus1-generator $(DESTDIR)$(usergeneratordir)/systemd-dbus1-generator

dbus1-generator-uninstall-hook:
	rm -f $(DESTDIR)$(usergeneratordir)/systemd-dbus1-generator

INSTALL_EXEC_HOOKS += dbus1-generator-install-hook
UNINSTALL_EXEC_HOOKS += dbus1-generator-uninstall-hook
endif

# ------------------------------------------------------------------------------
systemd_remount_fs_SOURCES = \
	src/remount-fs/remount-fs.c \
	src/core/mount-setup.c \
	src/core/mount-setup.h

systemd_remount_fs_LDADD = \
	libsystemd-label.la \
	libsystemd-shared.la

# ------------------------------------------------------------------------------
systemd_cgroups_agent_SOURCES = \
	src/cgroups-agent/cgroups-agent.c

systemd_cgroups_agent_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

# ------------------------------------------------------------------------------
systemctl_SOURCES = \
	src/systemctl/systemctl.c

systemctl_LDADD = \
	libsystemd-units.la \
	libsystemd-label.la \
	libsystemd-internal.la \
	libsystemd-shared.la

# ------------------------------------------------------------------------------
systemd_notify_SOURCES = \
	src/notify/notify.c \
	src/readahead/sd-readahead.c

systemd_notify_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

# ------------------------------------------------------------------------------
systemd_ask_password_SOURCES = \
	src/ask-password/ask-password.c

systemd_ask_password_LDADD = \
	libsystemd-label.la \
	libsystemd-shared.la

# ------------------------------------------------------------------------------
systemd_reply_password_SOURCES = \
	src/reply-password/reply-password.c

systemd_reply_password_LDADD = \
	libsystemd-shared.la

# ------------------------------------------------------------------------------
systemd_cgls_SOURCES = \
	src/cgls/cgls.c

systemd_cgls_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

# ------------------------------------------------------------------------------
systemd_cgtop_SOURCES = \
	src/cgtop/cgtop.c

systemd_cgtop_LDADD = \
	libsystemd-shared.la

# ------------------------------------------------------------------------------
systemd_run_SOURCES = \
	src/run/run.c

systemd_run_LDADD = \
	libsystemd-label.la \
	libsystemd-capability.la \
	libsystemd-internal.la \
	libsystemd-shared.la

# ------------------------------------------------------------------------------
systemd_bus_proxyd_SOURCES = \
	src/bus-proxyd/bus-proxyd.c

systemd_bus_proxyd_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

bus-proxyd-install-hook:
	$(AM_V_at)$(MKDIR_P) $(DESTDIR)$(bindir)
	$(AM_V_RM)rm -f $(DESTDIR)$(bindir)/systemd-stdio-bridge
	$(AM_V_LN)$(LN_S) --relative -f $(DESTDIR)$(rootlibexecdir)/systemd-bus-proxyd $(DESTDIR)$(bindir)/systemd-stdio-bridge

bus-proxyd-uninstall-hook:
	rm -f $(DESTDIR)$(bindir)/systemd-stdio-bridge

INSTALL_EXEC_HOOKS += bus-proxyd-install-hook
UNINSTALL_EXEC_HOOKS += bus-proxyd-uninstall-hook

if ENABLE_KDBUS
nodist_systemunit_DATA += \
	units/systemd-bus-proxyd@.service

dist_systemunit_DATA += \
	units/systemd-bus-proxyd.socket

dist_userunit_DATA += \
	units/user/systemd-bus-proxyd.socket \
	units/user/systemd-bus-proxyd@.service
endif

EXTRA_DIST += \
	units/systemd-bus-proxyd@.service.in

# ------------------------------------------------------------------------------
systemd_tty_ask_password_agent_SOURCES = \
	src/tty-ask-password-agent/tty-ask-password-agent.c

systemd_tty_ask_password_agent_LDADD = \
	libsystemd-label.la \
	libsystemd-shared.la

# ------------------------------------------------------------------------------
libsystemd_internal_la_SOURCES = \
	src/systemd/sd-bus.h \
	src/systemd/sd-bus-protocol.h \
	src/systemd/sd-bus-vtable.h \
	src/systemd/sd-memfd.h \
	src/systemd/sd-utf8.h \
	src/systemd/sd-event.h \
	src/systemd/sd-rtnl.h \
	src/systemd/sd-resolve.h \
	src/systemd/sd-login.h \
	src/systemd/sd-id128.h \
	src/systemd/sd-daemon.h \
	src/libsystemd/sd-bus/sd-bus.c \
	src/libsystemd/sd-bus/bus-control.c \
	src/libsystemd/sd-bus/bus-control.h \
	src/libsystemd/sd-bus/bus-error.c \
	src/libsystemd/sd-bus/bus-error.h \
	src/libsystemd/sd-bus/bus-internal.c \
	src/libsystemd/sd-bus/bus-internal.h \
	src/libsystemd/sd-bus/bus-socket.c \
	src/libsystemd/sd-bus/bus-socket.h \
	src/libsystemd/sd-bus/bus-kernel.c \
	src/libsystemd/sd-bus/bus-kernel.h \
	src/libsystemd/sd-bus/bus-container.c \
	src/libsystemd/sd-bus/bus-container.h \
	src/libsystemd/sd-bus/bus-message.c \
	src/libsystemd/sd-bus/bus-message.h \
	src/libsystemd/sd-bus/bus-creds.c \
	src/libsystemd/sd-bus/bus-creds.h \
	src/libsystemd/sd-bus/bus-signature.c \
	src/libsystemd/sd-bus/bus-signature.h \
	src/libsystemd/sd-bus/bus-type.c \
	src/libsystemd/sd-bus/bus-type.h \
	src/libsystemd/sd-bus/bus-match.c \
	src/libsystemd/sd-bus/bus-match.h \
	src/libsystemd/sd-bus/bus-bloom.c \
	src/libsystemd/sd-bus/bus-bloom.h \
	src/libsystemd/sd-bus/bus-introspect.c \
	src/libsystemd/sd-bus/bus-introspect.h \
	src/libsystemd/sd-bus/bus-objects.c \
	src/libsystemd/sd-bus/bus-objects.h \
	src/libsystemd/sd-bus/bus-gvariant.c \
	src/libsystemd/sd-bus/bus-gvariant.h \
	src/libsystemd/sd-bus/bus-convenience.c \
	src/libsystemd/sd-bus/bus-track.c \
	src/libsystemd/sd-bus/bus-track.h \
	src/libsystemd/sd-bus/bus-util.c \
	src/libsystemd/sd-bus/bus-util.h \
	src/libsystemd/sd-bus/bus-slot.c \
	src/libsystemd/sd-bus/bus-slot.h \
	src/libsystemd/sd-bus/bus-protocol.h \
	src/libsystemd/sd-bus/kdbus.h \
	src/libsystemd/sd-bus/sd-memfd.c \
	src/libsystemd/sd-utf8/sd-utf8.c \
	src/libsystemd/sd-event/sd-event.c \
	src/libsystemd/sd-event/event-util.h \
	src/libsystemd/sd-rtnl/sd-rtnl.c \
	src/libsystemd/sd-rtnl/rtnl-internal.h \
	src/libsystemd/sd-rtnl/rtnl-message.c \
	src/libsystemd/sd-rtnl/rtnl-types.h \
	src/libsystemd/sd-rtnl/rtnl-types.c \
	src/libsystemd/sd-rtnl/rtnl-util.h \
	src/libsystemd/sd-rtnl/rtnl-util.c \
	src/libsystemd/sd-id128/sd-id128.c \
	src/libsystemd/sd-daemon/sd-daemon.c \
	src/libsystemd/sd-login/sd-login.c

nodist_libsystemd_internal_la_SOURCES = \
	src/libsystemd/libsystemd.sym \
	src/libsystemd/sd-bus/bus-error-mapping.c

libsystemd_internal_la_CFLAGS = \
	$(AM_CFLAGS) \
	-pthread

libsystemd_internal_la_LIBADD = \
	$(RT_LIBS)

libsystemd_resolve_la_SOURCES = \
	src/libsystemd/sd-resolve/sd-resolve.c \
	src/libsystemd/sd-resolve/resolve-util.h

libsystemd_resolve_la_CFLAGS = \
	$(AM_CFLAGS) \
	-pthread

libsystemd_resolve_la_LIBADD = \
	-lresolv

noinst_LTLIBRARIES += \
	libsystemd-internal.la \
	libsystemd-resolve.la

libsystemd_dump_la_SOURCES = \
	src/libsystemd/sd-bus/bus-dump.c \
	src/libsystemd/sd-bus/bus-dump.h

libsystemd_dump_la_CFLAGS = \
	$(AM_CFLAGS) \
	$(CAP_CFLAGS)

noinst_LTLIBRARIES += \
	libsystemd-dump.la

EXTRA_DIST += \
	src/libsystemd/libsystemd.sym.m4 \
	src/libsystemd/libsystemd.pc.in \
	src/libsystemd/sd-bus/bus-error-mapping.gperf \
	src/libsystemd/sd-bus/DIFFERENCES \
	src/libsystemd/sd-bus/GVARIANT-SERIALIZATION

CLEANFILES += \
	src/libsystemd/libsystemd.sym \
	src/libsystemd/sd-bus/bus-error-mapping.c

BUILT_SOURCES += \
	src/libsystemd/libsystemd.sym

libsystemd_la_SOURCES = \
	$(libsystemd_internal_la_SOURCES) \
	$(libsystemd_resolve_la_SOURCES)

nodist_libsystemd_la_SOURCES = \
	$(nodist_libsystemd_internal_la_SOURCES)

libsystemd_la_CFLAGS = \
	$(libsystemd_internal_la_CFLAGS) \
	$(libsystemd_resolve_la_CFLAGS)

libsystemd_la_LDFLAGS = \
	$(AM_LDFLAGS) \
	-version-info $(LIBSYSTEMD_CURRENT):$(LIBSYSTEMD_REVISION):$(LIBSYSTEMD_AGE) \
	-Wl,--version-script=$(top_builddir)/src/libsystemd/libsystemd.sym

libsystemd_la_LIBADD = \
	libsystemd-shared.la \
	$(libsystemd_internal_la_LIBADD) \
	$(libsystemd_resolve_la_LIBADD)

libsystemd-install-hook:
	libname=libsystemd.so && $(move-to-rootlibdir)

libsystemd-uninstall-hook:
	rm -f $(DESTDIR)$(rootlibdir)/libsystemd.so*

INSTALL_EXEC_HOOKS += libsystemd-install-hook
UNINSTALL_EXEC_HOOKS += libsystemd-uninstall-hook

pkgconfiglib_DATA += \
	src/libsystemd/libsystemd.pc

pkginclude_HEADERS += \
	src/systemd/sd-login.h \
	src/systemd/sd-id128.h \
	src/systemd/sd-daemon.h

if ENABLE_KDBUS
pkginclude_HEADERS += \
	src/systemd/sd-bus.h \
	src/systemd/sd-bus-protocol.h \
	src/systemd/sd-bus-vtable.h \
	src/systemd/sd-memfd.h \
	src/systemd/sd-utf8.h \
	src/systemd/sd-event.h \
	src/systemd/sd-rtnl.h \
	src/systemd/sd-resolve.h
endif

lib_LTLIBRARIES += \
	libsystemd.la

tests += \
	test-bus-marshal \
	test-bus-signature \
	test-bus-chat \
	test-bus-cleanup \
	test-bus-server \
	test-bus-match \
	test-bus-kernel \
	test-bus-kernel-bloom \
	test-bus-kernel-benchmark \
	test-bus-memfd \
	test-bus-zero-copy \
	test-bus-introspect \
	test-bus-objects \
	test-bus-error \
	test-bus-creds \
	test-bus-gvariant \
	test-event \
	test-rtnl \
	test-resolve

bin_PROGRAMS += \
	busctl

test_bus_marshal_SOURCES = \
	src/libsystemd/sd-bus/test-bus-marshal.c

test_bus_marshal_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la \
	libsystemd-dump.la \
	libsystemd-capability.la \
	$(GLIB_LIBS) \
	$(DBUS_LIBS) \
	$(CAP_LIBS)

test_bus_marshal_CFLAGS = \
	$(AM_CFLAGS) \
	$(GLIB_CFLAGS) \
	$(DBUS_CFLAGS) \
	$(CAP_CFLAGS)

test_bus_signature_SOURCES = \
	src/libsystemd/sd-bus/test-bus-signature.c

test_bus_signature_LDADD = \
	libsystemd-shared.la \
	libsystemd-internal.la

test_bus_chat_SOURCES = \
	src/libsystemd/sd-bus/test-bus-chat.c

test_bus_chat_CFLAGS = \
	$(AM_CFLAGS) \
	-pthread

test_bus_chat_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

test_bus_cleanup_SOURCES = \
	src/libsystemd/sd-bus/test-bus-cleanup.c

test_bus_cleanup_CFLAGS = \
	$(AM_CFLAGS) \
	$(SECCOMP_CFLAGS)

test_bus_cleanup_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

test_bus_server_SOURCES = \
	src/libsystemd/sd-bus/test-bus-server.c

test_bus_server_CFLAGS = \
	$(AM_CFLAGS) \
	-pthread

test_bus_server_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

test_bus_objects_SOURCES = \
	src/libsystemd/sd-bus/test-bus-objects.c

test_bus_objects_CFLAGS = \
	$(AM_CFLAGS) \
	$(CAP_CFLAGS) \
	-pthread

test_bus_objects_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la \
	libsystemd-dump.la \
	libsystemd-capability.la \
	$(CAP_LIBS)

test_bus_error_SOURCES = \
	src/libsystemd/sd-bus/test-bus-error.c

test_bus_error_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

test_bus_gvariant_SOURCES = \
	src/libsystemd/sd-bus/test-bus-gvariant.c

test_bus_gvariant_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la \
	libsystemd-dump.la \
	libsystemd-capability.la \
	$(GLIB_LIBS) \
	$(CAP_LIBS)

test_bus_gvariant_CFLAGS = \
	$(AM_CFLAGS) \
	$(GLIB_CFLAGS)
	$(CAP_CFLAGS)

test_bus_creds_SOURCES = \
	src/libsystemd/sd-bus/test-bus-creds.c

test_bus_creds_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la \
	libsystemd-dump.la \
	libsystemd-capability.la

test_bus_match_SOURCES = \
	src/libsystemd/sd-bus/test-bus-match.c

test_bus_match_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

test_bus_kernel_SOURCES = \
	src/libsystemd/sd-bus/test-bus-kernel.c

test_bus_kernel_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la \
	libsystemd-dump.la \
	libsystemd-capability.la \
	$(CAP_LIBS)

test_bus_kernel_CFLAGS = \
	$(AM_CFLAGS) \
	$(CAP_CFLAGS)

test_bus_kernel_bloom_SOURCES = \
	src/libsystemd/sd-bus/test-bus-kernel-bloom.c

test_bus_kernel_bloom_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

test_bus_kernel_benchmark_SOURCES = \
	src/libsystemd/sd-bus/test-bus-kernel-benchmark.c

test_bus_kernel_benchmark_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

test_bus_memfd_SOURCES = \
	src/libsystemd/sd-bus/test-bus-memfd.c

test_bus_memfd_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

test_bus_zero_copy_SOURCES = \
	src/libsystemd/sd-bus/test-bus-zero-copy.c

test_bus_zero_copy_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la \
	libsystemd-dump.la \
	libsystemd-capability.la \
	$(CAP_LIBS)

test_bus_zero_copy_CFLAGS = \
	$(AM_CFLAGS) \
	$(CAP_CFLAGS)

test_bus_introspect_SOURCES = \
	src/libsystemd/sd-bus/test-bus-introspect.c

test_bus_introspect_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

test_event_SOURCES = \
	src/libsystemd/sd-event/test-event.c

test_event_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

test_rtnl_SOURCES = \
	src/libsystemd/sd-rtnl/test-rtnl.c

test_rtnl_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

test_resolve_SOURCES = \
	src/libsystemd/sd-resolve/test-resolve.c

test_resolve_LDADD = \
	libsystemd-resolve.la \
	libsystemd-internal.la \
	libsystemd-shared.la

test_resolve_CFLAGS = \
	$(AM_CFLAGS) \
	-pthread

busctl_SOURCES = \
	src/libsystemd/sd-bus/busctl.c

busctl_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la \
	libsystemd-dump.la \
	libsystemd-capability.la \
	$(CAP_LIBS)

busctl_CFLAGS = \
	$(AM_CFLAGS) \
	$(CAP_CFLAGS)

# ------------------------------------------------------------------------------
INSTALL_DIRS += \
	$(sysconfdir)/udev/rules.d

nodist_udevrules_DATA += \
	rules/99-systemd.rules

EXTRA_DIST += \
	rules/99-systemd.rules.in

CLEANFILES += \
	rules/99-systemd.rules

# ------------------------------------------------------------------------------
test_id128_SOURCES = \
	src/test/test-id128.c

test_id128_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

tests += \
	test-id128

# ------------------------------------------------------------------------------

rootlibexec_PROGRAMS += \
	systemd-activate

systemd_activate_SOURCES = \
	src/activate/activate.c

systemd_activate_LDADD = \
	libsystemd-label.la \
	libsystemd-internal.la \
	libsystemd-shared.la

# ------------------------------------------------------------------------------
pkginclude_HEADERS += \
	src/systemd/_sd-common.h

# ------------------------------------------------------------------------------

systemd_socket_proxyd_SOURCES = \
	src/socket-proxy/socket-proxyd.c

systemd_socket_proxyd_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la \
	libsystemd-resolve.la

# ------------------------------------------------------------------------------
if ENABLE_BINFMT
systemd_binfmt_SOURCES = \
	src/binfmt/binfmt.c

systemd_binfmt_LDADD = \
	libsystemd-shared.la

rootlibexec_PROGRAMS += \
	systemd-binfmt

dist_systemunit_DATA += \
	units/proc-sys-fs-binfmt_misc.automount \
	units/proc-sys-fs-binfmt_misc.mount

nodist_systemunit_DATA += \
	units/systemd-binfmt.service

INSTALL_DIRS += \
	$(prefix)/lib/binfmt.d \
	$(sysconfdir)/binfmt.d

SYSINIT_TARGET_WANTS += \
	systemd-binfmt.service \
	proc-sys-fs-binfmt_misc.automount

endif

EXTRA_DIST += \
	units/systemd-binfmt.service.in

# ------------------------------------------------------------------------------
if ENABLE_READAHEAD
systemd_readahead_SOURCES = \
	src/readahead/readahead.c \
	src/readahead/readahead-collect.c \
	src/readahead/readahead-replay.c \
	src/readahead/readahead-analyze.c \
	src/readahead/readahead-common.c \
	src/readahead/readahead-common.h

systemd_readahead_CFLAGS = \
	$(AM_CFLAGS) \
	$(LIBUDEV_CFLAGS)

systemd_readahead_LDADD = \
	libsystemd-internal.la \
	$(LIBUDEV_LIBS) \
	libsystemd-shared.la

dist_doc_DATA += \
	src/readahead/sd-readahead.c \
	src/systemd/sd-readahead.h

rootlibexec_PROGRAMS += \
	systemd-readahead

dist_systemunit_DATA += \
	units/systemd-readahead-drop.service \
	units/systemd-readahead-done.timer

nodist_systemunit_DATA += \
	units/systemd-readahead-collect.service \
	units/systemd-readahead-replay.service \
	units/systemd-readahead-done.service

manual_tests += \
	test-ssd

test_ssd_SOURCES = \
	src/readahead/test-ssd.c \
	src/readahead/readahead-common.c \
	src/readahead/readahead-common.h

test_ssd_CFLAGS = \
	$(AM_CFLAGS) \
	$(LIBUDEV_CFLAGS)

test_ssd_LDADD = \
	libsystemd-internal.la \
	$(LIBUDEV_LIBS) \
	libsystemd-shared.la

endif

EXTRA_DIST += \
	units/systemd-readahead-collect.service.in \
	units/systemd-readahead-replay.service.in \
	units/systemd-readahead-done.service.in

# ------------------------------------------------------------------------------
if ENABLE_QUOTACHECK
rootlibexec_PROGRAMS += \
	systemd-quotacheck

nodist_systemunit_DATA += \
	units/systemd-quotacheck.service

systemd_quotacheck_SOURCES = \
	src/quotacheck/quotacheck.c

systemd_quotacheck_LDADD = \
	libsystemd-shared.la
endif

EXTRA_DIST += \
	units/systemd-quotacheck.service.in

nodist_systemunit_DATA += \
	units/quotaon.service

# ------------------------------------------------------------------------------
if ENABLE_RANDOMSEED
rootlibexec_PROGRAMS += \
	systemd-random-seed

nodist_systemunit_DATA += \
	units/systemd-random-seed.service

systemd_random_seed_SOURCES = \
	src/random-seed/random-seed.c

systemd_random_seed_LDADD = \
	libsystemd-label.la \
	libsystemd-shared.la

SYSINIT_TARGET_WANTS += \
	systemd-random-seed.service

endif

EXTRA_DIST += \
	units/systemd-random-seed.service.in

# ------------------------------------------------------------------------------
if ENABLE_RFKILL
rootlibexec_PROGRAMS += \
	systemd-rfkill

nodist_systemunit_DATA += \
	units/systemd-rfkill@.service

systemd_rfkill_SOURCES = \
	src/rfkill/rfkill.c

systemd_rfkill_CFLAGS = \
	$(AM_CFLAGS) \
	$(LIBUDEV_CFLAGS)

systemd_rfkill_LDADD = \
	libsystemd-label.la \
	$(LIBUDEV_LIBS) \
	libsystemd-shared.la
endif

EXTRA_DIST += \
	units/systemd-rfkill@.service.in

# ------------------------------------------------------------------------------
if ENABLE_KDBUS
dist_systemunit_DATA += \
	units/org.freedesktop.systemd1.busname

BUSNAMES_TARGET_WANTS += \
	org.freedesktop.systemd1.busname
endif

# ------------------------------------------------------------------------------
if HAVE_MYHOSTNAME
libnss_myhostname_la_SOURCES = \
	src/nss-myhostname/nss-myhostname.c \
	src/nss-myhostname/ifconf.h \
	src/nss-myhostname/netlink.c

libnss_myhostname_la_LDFLAGS = \
	$(AM_LDFLAGS) \
	-module \
	-export-dynamic \
	-avoid-version \
	-shared \
	-shrext .so.2

libnss_myhostname_la_LIBADD = \
	libsystemd-shared.la \
	libsystemd-internal.la

lib_LTLIBRARIES += \
	libnss_myhostname.la
endif

# ------------------------------------------------------------------------------
if ENABLE_LOGIND
systemd_logind_SOURCES = \
	src/login/logind.c \
	src/login/logind.h

nodist_systemd_logind_SOURCES = \
	src/login/logind-gperf.c

systemd_logind_LDADD = \
	libsystemd-logind-core.la

libsystemd_logind_core_la_SOURCES = \
	src/login/logind-core.c \
	src/login/logind-device.c \
	src/login/logind-device.h \
	src/login/logind-button.c \
	src/login/logind-button.h \
	src/login/logind-action.c \
	src/login/logind-action.h \
	src/login/logind-seat.c \
	src/login/logind-seat.h \
	src/login/logind-session.c \
	src/login/logind-session.h \
	src/login/logind-session-device.c \
	src/login/logind-session-device.h \
	src/login/logind-user.c \
	src/login/logind-user.h \
	src/login/logind-inhibit.c \
	src/login/logind-inhibit.h \
	src/login/logind-dbus.c \
	src/login/logind-session-dbus.c \
	src/login/logind-seat-dbus.c \
	src/login/logind-user-dbus.c

libsystemd_logind_core_la_CFLAGS = \
	$(AM_CFLAGS) \
	$(LIBUDEV_CFLAGS)

libsystemd_logind_core_la_LIBADD = \
	libsystemd-label.la \
	libsystemd-capability.la \
	libsystemd-internal.la \
	$(LIBUDEV_LIBS) \
	libsystemd-shared.la

noinst_LTLIBRARIES += \
	libsystemd-logind-core.la

systemd_user_sessions_SOURCES = \
	src/login/user-sessions.c

systemd_user_sessions_LDADD = \
	libsystemd-shared.la

rootlibexec_PROGRAMS += \
	systemd-logind \
	systemd-user-sessions

loginctl_SOURCES = \
	src/login/loginctl.c \
	src/login/sysfs-show.c

loginctl_CFLAGS = \
	$(AM_CFLAGS) \
	$(LIBUDEV_CFLAGS)

loginctl_LDADD = \
	libsystemd-internal.la \
	$(LIBUDEV_LIBS) \
	libsystemd-shared.la

rootbin_PROGRAMS += \
	loginctl

dist_bashcompletion_DATA += \
	shell-completion/bash/loginctl

dist_zshcompletion_DATA += \
	shell-completion/zsh/_loginctl \
	shell-completion/zsh/_systemd-inhibit

systemd_inhibit_SOURCES = \
	src/login/inhibit.c

systemd_inhibit_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

rootbin_PROGRAMS += \
	systemd-inhibit

test_login_SOURCES = \
	src/libsystemd/sd-login/test-login.c

test_login_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

test_login_shared_SOURCES = \
	src/login/test-login-shared.c

test_login_shared_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

test_inhibit_SOURCES = \
	src/login/test-inhibit.c

test_inhibit_LDADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

test_login_tables_SOURCES = \
	src/login/test-login-tables.c

test_login_tables_LDADD = \
	libsystemd-logind-core.la

manual_tests += \
	test-login \
	test-inhibit

tests += \
	test-login-tables \
	test-login-shared

if HAVE_PAM
pam_systemd_la_SOURCES = \
	src/login/pam-module.c

pam_systemd_la_CFLAGS = \
	$(AM_CFLAGS) \
	$(PAM_CFLAGS) \
	-fvisibility=hidden

pam_systemd_la_LDFLAGS = \
	$(AM_LDFLAGS) \
	-module \
	-export-dynamic \
	-avoid-version \
	-shared \
	-export-symbols-regex '^pam_sm_.*'

pam_systemd_la_LIBADD = \
	libsystemd-capability.la \
	libsystemd-internal.la \
	libsystemd-shared.la \
	$(PAM_LIBS)

pamlib_LTLIBRARIES = \
	pam_systemd.la

dist_pamconf_DATA = \
	src/login/systemd-user
endif

nodist_systemunit_DATA += \
	units/systemd-logind.service \
	units/systemd-user-sessions.service

dist_systemunit_DATA += \
	units/user.slice \
	units/org.freedesktop.login1.busname

dist_dbussystemservice_DATA += \
	src/login/org.freedesktop.login1.service

dist_dbuspolicy_DATA += \
	src/login/org.freedesktop.login1.conf

dist_pkgsysconf_DATA += \
	src/login/logind.conf

polkitpolicy_files += \
	src/login/org.freedesktop.login1.policy

INSTALL_DIRS += \
	$(systemdstatedir)

MULTI_USER_TARGET_WANTS += \
	systemd-logind.service \
	systemd-user-sessions.service

SYSTEM_UNIT_ALIASES += \
	systemd-logind.service dbus-org.freedesktop.login1.service

BUSNAMES_TARGET_WANTS += \
	org.freedesktop.login1.busname

if ENABLE_MULTI_SEAT_X

systemd_multi_seat_x_SOURCES = \
	src/login/multi-seat-x.c

systemd_multi_seat_x_LDADD = \
	libsystemd-label.la \
	libsystemd-shared.la

rootlibexec_PROGRAMS += \
	systemd-multi-seat-x

endif

dist_udevrules_DATA += \
	src/login/70-uaccess.rules \
	src/login/70-power-switch.rules

nodist_udevrules_DATA += \
	src/login/71-seat.rules \
	src/login/73-seat-late.rules

CLEANFILES += \
	src/login/logind-gperf.c \
	src/login/71-seat.rules \
	src/login/73-seat-late.rules
endif

polkitpolicy_in_files += \
	src/login/org.freedesktop.login1.policy.in

EXTRA_DIST += \
	src/login/logind-gperf.gperf \
	src/login/71-seat.rules.in \
	src/login/73-seat-late.rules.in \
	units/systemd-logind.service.in \
	units/systemd-user-sessions.service.in

# ------------------------------------------------------------------------------
if ENABLE_COMPAT_LIBS
EXTRA_DIST += \
	src/compat-libs/linkwarning.h

libsystemd-%.c: src/compat-libs/libsystemd-%.sym
	$(AM_V_at)$(MKDIR_P) $(dir $@)
	$(AM_V_GEN)sed -r -n 's/^ +(sd_.*);/obsolete_lib(\1,$(notdir $(basename $<)));/p' <$< >$@

BUILT_SOURCES += \
	libsystemd-login.c \
	libsystemd-id128.c \
	libsystemd-daemon.c

libsystemd_login_la_SOURCES = \
	libsystemd-login.c \
	src/compat-libs/libsystemd-login.sym

libsystemd_login_la_CPPFLAGS = \
	$(AM_CFLAGS) \
	-imacros$(top_srcdir)/src/compat-libs/linkwarning.h

libsystemd_login_la_LDFLAGS = \
	$(AM_LDFLAGS) \
	-version-info $(LIBSYSTEMD_LOGIN_CURRENT):$(LIBSYSTEMD_LOGIN_REVISION):$(LIBSYSTEMD_LOGIN_AGE) \
	-Wl,--version-script=$(top_srcdir)/src/compat-libs/libsystemd-login.sym

libsystemd_login_la_LIBADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

libsystemd_id128_la_SOURCES = \
	libsystemd-id128.c \
	src/compat-libs/libsystemd-id128.sym

libsystemd_id128_la_CPPFLAGS = \
	$(AM_CFLAGS) \
	-imacros$(top_srcdir)/src/compat-libs/linkwarning.h

libsystemd_id128_la_LDFLAGS = \
	$(AM_LDFLAGS) \
	-version-info $(LIBSYSTEMD_ID128_CURRENT):$(LIBSYSTEMD_ID128_REVISION):$(LIBSYSTEMD_ID128_AGE) \
	-Wl,--version-script=$(top_srcdir)/src/compat-libs/libsystemd-id128.sym

libsystemd_id128_la_LIBADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

libsystemd_daemon_la_SOURCES = \
	libsystemd-daemon.c \
	src/compat-libs/libsystemd-daemon.sym

libsystemd_daemon_la_CPPFLAGS = \
	$(AM_CFLAGS) \
	-imacros$(top_srcdir)/src/compat-libs/linkwarning.h

libsystemd_daemon_la_LDFLAGS = \
	$(AM_LDFLAGS) \
	-version-info $(LIBSYSTEMD_DAEMON_CURRENT):$(LIBSYSTEMD_DAEMON_REVISION):$(LIBSYSTEMD_DAEMON_AGE) \
	-Wl,--version-script=$(top_srcdir)/src/compat-libs/libsystemd-daemon.sym

libsystemd_daemon_la_LIBADD = \
	libsystemd-internal.la \
	libsystemd-shared.la

lib_LTLIBRARIES += \
	libsystemd-login.la \
	libsystemd-id128.la \
	libsystemd-daemon.la

pkgconfiglib_DATA += \
	src/compat-libs/libsystemd-login.pc \
	src/compat-libs/libsystemd-id128.pc \
	src/compat-libs/libsystemd-daemon.pc

# move lib from $(libdir) to $(rootlibdir) and update devel link, if needed
compat-lib-install-hook:
	libname=libsystemd-login.so && $(move-to-rootlibdir)
	libname=libsystemd-id128.so && $(move-to-rootlibdir)
	libname=libsystemd-daemon.so && $(move-to-rootlibdir)

compat-lib-uninstall-hook:
	rm -f $(DESTDIR)$(rootlibdir)/libsystemd-login.so*
	rm -f $(DESTDIR)$(rootlibdir)/libsystemd-id128.so*
	rm -f $(DESTDIR)$(rootlibdir)/libsystemd-daemon.so*

INSTALL_EXEC_HOOKS += compat-lib-install-hook
UNINSTALL_EXEC_HOOKS += compat-lib-uninstall-hook
endif

EXTRA_DIST += \
	src/compat-libs/libsystemd-login.pc.in \
	src/compat-libs/libsystemd-id128.pc.in \
	src/compat-libs/libsystemd-daemon.pc.in

# ------------------------------------------------------------------------------
substitutions = \
       '|rootlibexecdir=$(rootlibexecdir)|' \
       '|rootbindir=$(rootbindir)|' \
       '|bindir=$(bindir)|' \
       '|SYSTEMCTL=$(rootbindir)/systemctl|' \
       '|SYSTEMD_NOTIFY=$(rootbindir)/systemd-notify|' \
       '|pkgsysconfdir=$(pkgsysconfdir)|' \
       '|SYSTEM_CONFIG_UNIT_PATH=$(pkgsysconfdir)/system|' \
       '|USER_CONFIG_UNIT_PATH=$(pkgsysconfdir)/user|' \
       '|pkgdatadir=$(pkgdatadir)|' \
       '|systemunitdir=$(systemunitdir)|' \
       '|userunitdir=$(userunitdir)|' \
       '|systempresetdir=$(systempresetdir)|' \
       '|userpresetdir=$(userpresetdir)|' \
       '|udevrulesdir=$(udevrulesdir)|' \
       '|tmpfilesdir=$(tmpfilesdir)|' \
       '|sysctldir=$(sysctldir)|' \
       '|systemgeneratordir=$(systemgeneratordir)|' \
       '|usergeneratordir=$(usergeneratordir)|' \
       '|PACKAGE_VERSION=$(PACKAGE_VERSION)|' \
       '|PACKAGE_NAME=$(PACKAGE_NAME)|' \
       '|PACKAGE_URL=$(PACKAGE_URL)|' \
       '|RANDOM_SEED_DIR=$(localstatedir)/lib/systemd/|' \
       '|RANDOM_SEED=$(localstatedir)/lib/systemd/random-seed|' \
       '|prefix=$(prefix)|' \
       '|exec_prefix=$(exec_prefix)|' \
       '|libdir=$(libdir)|' \
       '|includedir=$(includedir)|' \
       '|VERSION=$(VERSION)|' \
       '|rootprefix=$(rootprefix)|' \
       '|udevlibexecdir=$(udevlibexecdir)|' \
       '|SUSHELL=$(SUSHELL)|' \
       '|DEBUGTTY=$(DEBUGTTY)|' \
       '|KILL=$(KILL)|' \
       '|KMOD=$(KMOD)|' \
       '|MKDIR_P=$(MKDIR_P)|' \
       '|QUOTAON=$(QUOTAON)|' \
       '|QUOTACHECK=$(QUOTACHECK)|' \
       '|VARLOGDIR=$(varlogdir)|' \
       '|NTP_SERVERS=$(NTP_SERVERS)|' \
       '|DNS_SERVERS=$(DNS_SERVERS)|' \
       '|systemuidmax=$(SYSTEM_UID_MAX)|' \
       '|systemgidmax=$(SYSTEM_GID_MAX)|'

SED_PROCESS = \
	$(AM_V_GEN)$(MKDIR_P) $(dir $@) && \
	$(SED) $(subst '|,-e 's|@,$(subst =,\@|,$(subst |',|g',$(substitutions)))) \
		< $< > $@

units/%: units/%.in
	$(SED_PROCESS)

man/%: man/%.in
	$(SED_PROCESS)

sysctl.d/%: sysctl.d/%.in
	$(SED_PROCESS)

%.pc: %.pc.in
	$(SED_PROCESS)

src/core/macros.%: src/core/macros.%.in
	$(SED_PROCESS)

src/%.policy.in: src/%.policy.in.in
	$(SED_PROCESS)

%.rules: %.rules.in
	$(SED_PROCESS)

%.conf: %.conf.in
	$(SED_PROCESS)

%.sh: %.sh.in
	$(SED_PROCESS)
	$(AM_V_GEN)chmod +x $@

src/%.c: src/%.gperf
	$(AM_V_at)$(MKDIR_P) $(dir $@)
	$(AM_V_GPERF)$(GPERF) < $< > $@

src/%: src/%.m4
	$(AM_V_at)$(MKDIR_P) $(dir $@)
	$(AM_V_M4)$(M4) -P $(M4_DEFINES) < $< > $@

units/%: units/%.m4
	$(AM_V_at)$(MKDIR_P) $(dir $@)
	$(AM_V_M4)$(M4) -P $(M4_DEFINES) -DFOR_SYSTEM=1 < $< > $@

units/user/%: units/user/%.m4
	$(AM_V_at)$(MKDIR_P) $(dir $@)
	$(AM_V_M4)$(M4) -P $(M4_DEFINES) -DFOR_USER=1 < $< > $@

if ENABLE_POLKIT
nodist_polkitpolicy_DATA = \
	$(polkitpolicy_files) \
	$(polkitpolicy_in_in_files:.policy.in.in=.policy)
endif

EXTRA_DIST += \
	$(polkitpolicy_in_files) \
	$(polkitpolicy_in_in_files)

CLEANFILES += \
	$(nodist_systemunit_DATA) \
	$(nodist_userunit_DATA) \
	$(pkgconfigdata_DATA) \
	$(pkgconfiglib_DATA) \
	$(nodist_polkitpolicy_DATA)

# ------------------------------------------------------------------------------
if ENABLE_MANPAGES
man/custom-entities.ent: configure.ac
	$(AM_V_GEN)$(MKDIR_P) $(dir $@)
	$(AM_V_GEN)(echo '<?xml version="1.0" encoding="utf-8" ?>' && \
	 printf '$(subst '|,<!ENTITY ,$(subst =, ",$(subst |',">\n,$(substitutions))))') \
	 > $@ # '

DISTCLEANFILES += \
	man/custom-entities.ent

XSLTPROC_FLAGS = \
	--nonet \
	--xinclude \
	--stringparam man.output.quietly 1 \
	--stringparam funcsynopsis.style ansi \
	--stringparam man.authors.section.enabled 0 \
	--stringparam man.copyright.section.enabled 0 \
	--stringparam systemd.version $(VERSION) \
	--path '$(builddir)/man:$(srcdir)/man'

XSLTPROC_PROCESS_MAN = \
	$(AM_V_XSLT)$(XSLTPROC) -o $@ $(XSLTPROC_FLAGS) $(srcdir)/man/custom-man.xsl $<

XSLTPROC_PROCESS_HTML = \
	$(AM_V_XSLT)$(XSLTPROC) -o $@ $(XSLTPROC_FLAGS) $(srcdir)/man/custom-html.xsl $<

man/%.1: man/%.xml man/custom-man.xsl man/custom-entities.ent
	$(XSLTPROC_PROCESS_MAN)

man/%.3: man/%.xml man/custom-man.xsl man/custom-entities.ent
	$(XSLTPROC_PROCESS_MAN)

man/%.5: man/%.xml man/custom-man.xsl man/custom-entities.ent
	$(XSLTPROC_PROCESS_MAN)

man/%.7: man/%.xml man/custom-man.xsl man/custom-entities.ent
	$(XSLTPROC_PROCESS_MAN)

man/%.8: man/%.xml man/custom-man.xsl man/custom-entities.ent
	$(XSLTPROC_PROCESS_MAN)

man/%.html: man/%.xml man/custom-html.xsl man/custom-entities.ent
	$(XSLTPROC_PROCESS_HTML)

define html-alias
	$(AM_V_LN)$(LN_S) -f $(notdir $<) $@
endef

endif

EXTRA_DIST += \
	man/custom-html.xsl \
	man/custom-man.xsl

# ------------------------------------------------------------------------------
SOCKETS_TARGET_WANTS += \
	systemd-initctl.socket \
	systemd-shutdownd.socket

SYSINIT_TARGET_WANTS += \
	systemd-update-utmp.service
LOCAL_FS_TARGET_WANTS += \
	systemd-remount-fs.service \
	tmp.mount
MULTI_USER_TARGET_WANTS += \
	getty.target \
	systemd-ask-password-wall.path
SYSINIT_TARGET_WANTS += \
	dev-hugepages.mount \
	dev-mqueue.mount \
	sys-kernel-config.mount \
	sys-kernel-debug.mount \
	sys-fs-fuse-connections.mount \
	sysctl.service \
	systemd-ask-password-console.path

SYSTEM_UNIT_ALIASES += \
	graphical.target default.target \
	reboot.target ctrl-alt-del.target \
	getty@.service autovt@.service

USER_UNIT_ALIASES += \
	$(systemunitdir)/shutdown.target shutdown.target \
	$(systemunitdir)/sockets.target sockets.target \
	$(systemunitdir)/busnames.target busnames.target \
	$(systemunitdir)/timers.target timers.target \
	$(systemunitdir)/paths.target paths.target \
	$(systemunitdir)/bluetooth.target bluetooth.target \
	$(systemunitdir)/printer.target printer.target \
	$(systemunitdir)/sound.target sound.target \
	$(systemunitdir)/smartcard.target smartcard.target

GENERAL_ALIASES += \
	$(systemunitdir)/remote-fs.target $(pkgsysconfdir)/system/multi-user.target.wants/remote-fs.target \
	$(systemunitdir)/getty@.service $(pkgsysconfdir)/system/getty.target.wants/getty@tty1.service \
	$(pkgsysconfdir)/user $(sysconfdir)/xdg/systemd/user \
	$(dbussystemservicedir)/org.freedesktop.systemd1.service $(dbussessionservicedir)/org.freedesktop.systemd1.service

INSTALL_DIRS += \
	$(prefix)/lib/modules-load.d \
	$(sysconfdir)/modules-load.d \
	$(prefix)/lib/systemd/network \
	$(sysconfdir)/systemd/network \
	$(prefix)/lib/sysctl.d \
	$(sysconfdir)/sysctl.d \
	$(prefix)/lib/kernel/install.d \
	$(sysconfdir)/kernel/install.d \
	$(systemshutdowndir) \
	$(systemsleepdir) \
	$(systemgeneratordir) \
	$(usergeneratordir) \
	\
	$(userunitdir) \
	$(pkgsysconfdir)/system \
	$(pkgsysconfdir)/system/multi-user.target.wants \
	$(pkgsysconfdir)/system/getty.target.wants \
	$(pkgsysconfdir)/user \
	$(dbussessionservicedir) \
	$(sysconfdir)/xdg/systemd

install-exec-hook: $(INSTALL_EXEC_HOOKS)

uninstall-hook: $(UNINSTALL_DATA_HOOKS) $(UNINSTALL_EXEC_HOOKS)

install-data-hook: $(INSTALL_DATA_HOOKS)

distclean-local: $(DISTCLEAN_LOCAL_HOOKS)

clean-local: $(CLEAN_LOCAL_HOOKS)
	rm -rf $(abs_srcdir)/install-tree

DISTCHECK_CONFIGURE_FLAGS = \
	--with-dbuspolicydir=$$dc_install_base/$(dbuspolicydir) \
	--with-dbussessionservicedir=$$dc_install_base/$(dbussessionservicedir) \
	--with-dbussystemservicedir=$$dc_install_base/$(dbussystemservicedir) \
	--with-bashcompletiondir=$$dc_install_base/$(bashcompletiondir) \
	--with-zshcompletiondir=$$dc_install_base/$(zshcompletiondir) \
	--with-pamlibdir=$$dc_install_base/$(pamlibdir) \
	--with-pamconfdir=$$dc_install_base/$(pamconfdir) \
	--with-rootprefix=$$dc_install_base \
	--disable-split-usr \
	--enable-kdbus \
	--enable-compat-libs

# check "broken" platforms limited toolchains for link breakage before we release
.PHONY: linkcheck
linkcheck:
	$(MAKE) CFLAGS='-fno-lto' LDFLAGS='-Wl,-fuse-ld=gold -Wl,--as-needed -Wl,--no-gc-sections' distcheck

.PHONY: kdbus-update
kdbus-update:
	( cd $(top_srcdir)/src/libsystemd/sd-bus/ && \
	wget -N https://d-bus.googlecode.com/git/kdbus.h )

.PHONY: git-tag
git-tag:
	git tag -s "v$(VERSION)" -m "systemd $(VERSION)"

www_target = www.freedesktop.org:/srv/www.freedesktop.org/www/software/systemd
.PHONY: upload
upload: all check dist
	scp systemd-$(VERSION).tar.xz $(www_target)

.PHONY: doc-sync
doc-sync: all
	rsync -rlv --delete-excluded --include="*.html" --exclude="*" --omit-dir-times man/ $(www_target)/man/

.PHONY: tango
tango: upload
	cp -v systemd-$(VERSION).tar.xz /home/lennart/git.fedora/systemd/
	scp man/*.html tango:public/systemd-man/

.PHONY: install-tree
install-tree: all
	rm -rf $(abs_srcdir)/install-tree
	$(MAKE) install DESTDIR=$(abs_srcdir)/install-tree
	tree $(abs_srcdir)/install-tree

# Let's run all tests of the test suite, but under valgrind. Let's
# exclude the one perl script we have in there
.PHONY: valgrind-tests
valgrind-tests: $(TESTS)
	$(AM_V_GEN)for f in $(filter-out %.pl, $^); do \
		if file $$f | grep -q shell; then \
		echo -e "$${x}Skipping non-binary $$f"; else \
		echo -e "$${x}Running $$f"; \
		libtool --mode=execute valgrind -q --leak-check=full --max-stackframe=5242880 --error-exitcode=55 $(builddir)/$$f ; fi; \
		x="\n\n"; \
	done

exported-%: %
	$(AM_V_GEN)nm -g --defined-only $(builddir)/.libs/$(<:.la=.so) 2>&1 /dev/null | grep " T " | cut -d" " -f3 > $@

exported: $(addprefix exported-, $(lib_LTLIBRARIES))
	$(AM_V_GEN)cat $^ > $@

.PHONY: check-api-docs
check-api-docs: exported man
	$(AM_V_GEN)for symbol in `cat exported` ; do \
		if test -f $(builddir)/man/$$symbol.html ; then \
			echo "  Symbol $$symbol() is documented." ; \
		else \
			echo "‣ Symbol $$symbol() lacks documentation." ; \
		fi ; \
	done

OBJECT_VARIABLES:=$(filter %_OBJECTS,$(.VARIABLES))
ALL_OBJECTS:=$(foreach v,$(OBJECT_VARIABLES),$($(v)))

undefined defined: $(ALL_OBJECTS)
	$(AM_V_GEN)for f in $(ALL_OBJECTS) ; do \
		nm -g --$@-only `echo $(builddir)/"$$f" | sed -e 's,\([^/]*\).lo$$,.libs/\1.o,'` ; \
	done | cut -c 20- | cut -d @ -f 1 | sort -u > $@

CLEANFILES += \
	defined \
	undefined

.PHONY: check-api-unused
check-api-unused: defined undefined exported
	( cat exported undefined ) | sort -u  | diff -u - defined | grep ^+ | grep -v ^+++ | cut -c2-

.PHONY: check-includes
check-includes: $(top_srcdir)/tools/check-includes.pl
	$(AM_V_GEN) find * -name '*.[hcS]' -type f -print | sort -u \
		| xargs $(top_srcdir)/tools/check-includes.pl

EXTRA_DIST += \
	$(top_srcdir)/tools/check-includes.pl

# Stupid test that everything purported to be exported really is
define generate-sym-test
	$(AM_V_at)$(MKDIR_P) $(dir $@)
	$(AM_V_at)printf '#include <stdio.h>\n' > $@
	$(AM_V_at)printf '#include "%s"\n' $(notdir $(filter %.h, $^)) >> $@
	$(AM_V_at)printf 'void* functions[] = {\n' >> $@
	$(AM_V_GEN)sed -r -n 's/^ +([a-zA-Z0-9_]+);/\1,/p' $< >> $@
	$(AM_V_at)printf '};\nint main(void) {\n' >> $@
	$(AM_V_at)printf 'unsigned i; for (i=0;i<sizeof(functions)/sizeof(void*);i++) printf("%%p\\n", functions[i]);\n' >> $@
	$(AM_V_at)printf 'return 0; }\n' >> $@
endef

test-libsystemd-sym.c: \
		$(top_builddir)/src/libsystemd/libsystemd.sym \
		src/systemd/sd-daemon.h \
		src/systemd/sd-login.h \
		src/systemd/sd-bus.h \
		src/systemd/sd-utf8.h \
		src/systemd/sd-resolve.h
	$(generate-sym-test)

test_libsystemd_sym_SOURCES = \
	test-libsystemd-sym.c
test_libsystemd_sym_LDADD = \
	libsystemd.la

BUILT_SOURCES += \
	$(test_libsystemd_sym_SOURCES)

tests += \
	test-libsystemd-sym

.PHONY: cppcheck
cppcheck:
	cppcheck --enable=all -q $(top_srcdir)

# Used to extract compile flags for YCM.
print-%:
	@echo $($*)

git-contrib:
	@git shortlog -s `git describe --abbrev=0`.. | cut -c8- | awk '{ print $$0 "," }' | sort -u
