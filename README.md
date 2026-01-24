# nice-view-darius

BASED ON [nice-view-gem](https://github.com/M165437/nice-view-gem)

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

| Option                                     | Type | Description                                                                                                                                                                                                                                                       | Default |
| ------------------------------------------ | ---- | ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------- |
| `CONFIG_NICE_VIEW_GEM_WPM_FIXED_RANGE`     | bool | This shield uses a fixed range for the chart and gauge deflection. If you set this option to `n`, it will switch to a dynamic range, like the default nice!view shield, which dynamically adjusts based on the last 10 WPM values provided by ZMK.                | y       |
| `CONFIG_NICE_VIEW_GEM_WPM_FIXED_RANGE_MAX` | int  | You can adjust the maximum value of the fixed range to align with your current goal.                                                                                                                                                                              | 100     |

## Credits

Shoutout to Teenage Engineering for their [TX-6](https://teenage.engineering/products/tx-6), from which the inspiration (and maybe even a few pixel strokes) originated. 😬

As for the floating crystal, appreciation goes to the pixel wizardry of Trixelized, who graciously lent their art to this project. 💎

The font, Pixel Operator, is the work of Jayvee Enaguas, kindly shared under a [Creative Commons Zero (CC0) 1.0](https://creativecommons.org/publicdomain/zero/1.0/) license. 🖋️
