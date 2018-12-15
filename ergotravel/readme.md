# Bernardo's Ergotravel

For details on QMK's features, check out their gitbook
[here](https://docs.qmk.fm/)

## [Layout](./keymap.c)

I map F19 to spotlight so I like having that handy.

## Building

In order to be able to make frequent updates, I maintain this layout [in its own
repository](berfarah:ergotravel-layout)

```sh
git clone https://github.com/qmk/qmk_firmware.git
cd qmk_firmware
git clone https://github.com/berfarah/ergotravel-layout.git \
          layouts/community/ergotravel/berfarah_master
```

To use this keyboard:

```sh
# to build
make ergotravel/rev1:berfarah_master

# to flash:
make ergotravel/rev1:berfarah_master:avrdude
```
