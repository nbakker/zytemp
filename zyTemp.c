#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <dev/usb/usbhid.h>
#include <dev/usb/usb_ioctl.h>

int
main(int argc, char *argv[])
{
	int fd, r;
	struct usb_gen_descriptor ugd;

	if (argc != 2 || argv[1][0] == '-') {
		printf("Usage: zytemp UHIDDEVICE\n");
		exit(0);
	}

	fd = open(argv[1], O_RDWR);
	if (fd == -1) {
		fprintf(stderr, "open(\"%s\"): %s\n", argv[1], strerror(errno));
		exit(1);
	}

	memset(&ugd, 0, sizeof(ugd));
	ugd.ugd_data = "\xc4\xc6\xc0\x92\x40\x23\xdc\x96";
	/* key for subsequent reads */
	ugd.ugd_maxlen = 8;
	ugd.ugd_report_type = UHID_FEATURE_REPORT;

	r = ioctl(fd, USB_SET_REPORT, &ugd);
	if (r) { perror("ioctl(USB_SET_REPORT)"); }
	
	return 0;
}
