# usbreset

reset usb devices using `<vid>` `<pid>`

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
