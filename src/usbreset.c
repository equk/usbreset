/*
 * USB Device Reset
 * Copyright (C) 2023 B.Walden
 *
 * This program resets the USB connection for a device
 * based vendor_id & product_id
 *
 * The main handler checks the device exists before trying to
 * init any connection
 *
 * License: MIT (LICENSE file should be included with source)
 */

#include <libusb-1.0/libusb.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// USB Device Handle
// (check usb device connected before attempting to open connection)
struct libusb_device_handle *usb_init(struct libusb_context *context, int venid, int devid)
{
    struct libusb_device **device_list;
    struct libusb_device_handle *handle = NULL;

    int deviceCount = libusb_get_device_list(context, &device_list);

    int i;
    for (i = 0; i < deviceCount; i++)
    {
        struct libusb_device *device = device_list[i];
        struct libusb_device_descriptor desc;
        libusb_get_device_descriptor(device, &desc);
        if (desc.idVendor == venid && desc.idProduct == devid)
        {
            libusb_open(device, &handle);
            break;
        }
    }

    libusb_free_device_list(device_list, 1);

    return handle;
}

// Close USB Handle
void usb_close(struct libusb_device_handle *handle)
{
    if (handle != NULL)
    {
        libusb_close(handle);
    }
}

int main(int argc, char **argv)
{
    struct libusb_context *context;
    struct libusb_device_handle *handle = NULL;

    if (argc != 3)
    {
        printf("USB Device Reset\n");
        printf("----------------\n\n");
        printf("No input given or input invalid\n\n");
        printf("Usage: %s <vid> <pid>\n", argv[0]);
        return 1;
    }

    int vid, pid;
    sscanf(argv[1], "%04x", &vid);
    sscanf(argv[2], "%04x", &pid);

    libusb_init(&context);
    libusb_set_option(NULL, LIBUSB_OPTION_LOG_LEVEL, 3);
    printf("Checking USB Device Connected ...\n");
    handle = usb_init(context, vid, pid);
    if (handle == NULL)
    {
        fprintf(stderr, "ERROR: USB device not found [%04x:%04x]\n", vid, pid);
        return 1;
    }
    printf("Resetting USB Device [%04x:%04x]\n", vid, pid);

    libusb_reset_device(handle);
    printf("USB Device reset [%04x:%04x]\n", vid, pid);

    usb_close(handle);
    libusb_exit(NULL);

    return 0;
}
