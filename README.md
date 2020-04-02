# Bernardo's Keyboard Layouts

A few keyboard layouts Bernardo uses for various keyboards

## Building

In order to be able to make frequent updates, I maintain my layout in this
repository.``

    git clone https://github.com/qmk/qmk_firmware.git
    git clone https://github.com/berfarah/keyboard-layouts.git
    cd qmk_firmware

    # Link the directory (using erogtravel as an example)
    ln -sf layouts/community/ergotravel/berfarah_master "$PWD/../keyboard-layouts/ergotravel"

    # to build
    make ergotravel/rev1:berfarah_master

    # to flash
    make ergotravel/rev1:berfarah_master:dfu


Note that different hardware has different bootloaders:

|Hardware |Bootloader|
|---------|----------|
|Promicro |avrdude   |
|EliteC   |dfu       |
|EliteC LP|dfu       |
