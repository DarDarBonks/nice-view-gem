# nice-view-darius

BASED ON [nice-view-gem](https://github.com/M165437/nice-view-gem)

ALSO USING ASSETS FROM [zmk-nice-oled](https://github.com/mctechnology17/zmk-nice-oled)

ALSO USING ASSETS FROM [nice-luffy-gear-five](https://github.com/whoop-t/nice-luffy-gear-five)

ALSO USING ASSETS FROM [hammerbeam-slideshow](https://github.com/GPeye/hammerbeam-slideshow) 

```yml
manifest:
  remotes:
    - name: zmkfirmware
      url-base: https://github.com/zmkfirmware
    - name: DarDarBonks
      url-base: https://github.com/DarDarBonks
  projects:
    - name: zmk
      remote: zmkfirmware
      revision: main
      import: app/west.yml
    - name: nice-view-dardar
      remote: DarDarBonks
      revision: main
  self:
    path: config
```

Now, simply swap out the default nice_view shield on the board for nice_view_gem in your `build.yaml` file.

```yml
---
include:
  - board: corne_choc_pro_left
    snippet: studio-rpc-usb-uart
    shield: nice_view_dardar
    cmake-args: -DCONFIG_ZMK_STUDIO=y
  - board: corne_choc_pro_right
    shield: nice_view_dardar
    snippet: studio-rpc-usb-uart
```

Finally, make sure to enable the custom status screen in your ZMK configuration:

```conf
CONFIG_ZMK_DISPLAY=y
CONFIG_ZMK_DISPLAY_STATUS_SCREEN_CUSTOM=y
```

## Configuration

Modify the behavior of this shield by adjusting these options in your personal configuration files. For a more detailed explanation, refer to [Configuration in the ZMK documentation](https://zmk.dev/docs/config).

## Credits

[nice-view-gem](https://github.com/M165437/nice-view-gem)

[zmk-nice-oled](https://github.com/mctechnology17/zmk-nice-oled)

[nice-luffy-gear-five](https://github.com/whoop-t/nice-luffy-gear-five)

[hammerbeam-slideshow](https://github.com/GPeye/hammerbeam-slideshow)
