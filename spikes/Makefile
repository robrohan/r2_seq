
CC:=gcc

find_usb:
	ioreg -l | grep -i "USB Vendor Name\|USB Product Name\|idVendor\|idProduct"
#	system_profiler SPUSBDataType

build:
	$(CC) -I./libusb-1.0.27/libusb \
		./libusb-1.0.27/libusb/.libs/libusb-1.0.a \
		midi_sender.c \
		-o midi_sender \
		-Wl,-framework,IOKit \
		-Wl,-framework,CoreFoundation \
		-Wl,-framework,Security \
		-lobjc
#	cp ./libusb-1.0.27/libusb/.libs/libusb-1.0.dylib ./libusb-1.0.dylib

libusb:
#	Download libusb
	wget https://github.com/libusb/libusb/releases/download/v1.0.27/libusb-1.0.27.tar.bz2
	tar -xjf libusb-1.0.27.tar.bz2

	cd libusb-1.0.27; \
	./configure --enable-static; \
	make
#	sudo make install

run:
	./midi_sender