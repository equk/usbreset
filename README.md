# usbreset

Reset USB Devices In Linux Using `<vid>` `<pid>`

More info: [Reset USB Device In Linux - equk's blog](https://equk.co.uk/2023/09/25/reset-usb-device-in-linux/)

## list usb devices

```
$ lsusb
Bus 001 Device 006: ID 045e:028e Microsoft Corp. Xbox360 Controller
```

## usbreset

exec program with root privilege

use `<vid> <pid>` from `lsusb` output

```
$ sudo ./libusb_reset 045e 028e
Checking USB Device Connected ...
Resetting USB Device [045e:028e]
USB Device reset [045e:028e]
```

# Contact

Website: https://equk.co.uk

Mastodon: [@equilibriumuk@hachyderm.io](https://hachyderm.io/@equilibriumuk)

# License

MIT License
