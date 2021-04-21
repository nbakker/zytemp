#!/bin/sh
#
# PROVIDE: zytemp
# REQUIRE: DAEMON NETWORKING
# BEFORE: LOGIN
# KEYWORD: nojail shutdown
#

case "$1" in
  start|faststart|onestart)
	echo "Starting zytemp."
	/usr/local/sbin/zytemp /dev/uhid0
	;;
  stop|faststop)
	;;
  restart|reload)
	;;
  *)
	echo "Usage: $0 start ($@)" >&2
esac

exit 0
