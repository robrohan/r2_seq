#include <libusb.h>
#include <stdio.h>
#include <stdlib.h>

// #define VENDOR_ID  0x0000 // Replace with your device's Vendor ID
// #define PRODUCT_ID 0x0000 // Replace with your device's Product ID

#define VENDOR_ID 2372
#define PRODUCT_ID 340

int main() {
    libusb_device_handle *handle = NULL;
    int rc = libusb_init(NULL);
    if (rc < 0) {
        printf("Error initializing libusb: %s\n", libusb_error_name(rc));
        return 1;
    }

    handle = libusb_open_device_with_vid_pid(NULL, VENDOR_ID, PRODUCT_ID);
    if (!handle) {
        printf("Cannot open device\n");
        libusb_exit(NULL);
        return 1;
    }

    if (libusb_kernel_driver_active(handle, 0) == 1) {
        libusb_detach_kernel_driver(handle, 0);
    }

    rc = libusb_claim_interface(handle, 0);
    if (rc < 0) {
        printf("Cannot claim interface: %s\n", libusb_error_name(rc));
        libusb_close(handle);
        libusb_exit(NULL);
        return 1;
    }

    unsigned char midi_message[] = {0x90, 0x3C, 0x7F}; // Note On, Middle C, Full Velocity
    int transferred = 0;
    rc = libusb_bulk_transfer(handle, 0x01, midi_message, sizeof(midi_message), &transferred, 0);
    if (rc < 0) {
        printf("Error sending MIDI message: %s\n", libusb_error_name(rc));
    } else {
        printf("MIDI message sent successfully\n");
    }

    libusb_release_interface(handle, 0);
    libusb_close(handle);
    libusb_exit(NULL);
    return 0;
}
