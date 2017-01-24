# zyTemp
## Tools for the USB-zyTemp environmental measurement device

This chipset is incorporated in devices sold by various companies, like [co2Meter.com](http://www.co2meter.com/products/co2mini-co2-indoor-air-quality-monitor) or [TFA Dostmann](https://www.amazon.de/dp/B00TH3OW4Q).

[Henry Plötz](https://hackaday.io/project/5301-reverse-engineering-a-low-cost-usb-co-monitor/log/17909-all-your-base-are-belong-to-us) did great work reverse engineering the particulars of how to get the device to start talking and how to subsequently interpret that data.

This repository contains a C program for FreeBSD that does the initial work to get the data flowing, because ioctls in Python that require pointers being passed around are hard.
