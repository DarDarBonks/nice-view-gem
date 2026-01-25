/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#include <zephyr/kernel.h>

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include "luna.h"

LV_IMG_DECLARE(dog_sit1_90);
LV_IMG_DECLARE(dog_sit2_90);
LV_IMG_DECLARE(dog_walk1_90);
LV_IMG_DECLARE(dog_walk2_90);
LV_IMG_DECLARE(dog_run1_90);
LV_IMG_DECLARE(dog_run2_90);

#define LUNA_FRAME_SIT1  0
#define LUNA_FRAME_SIT2  1
#define LUNA_FRAME_WALK1 2
#define LUNA_FRAME_WALK2 3
#define LUNA_FRAME_RUN1  4
#define LUNA_FRAME_RUN2  5

static const lv_img_dsc_t *luna_frames[] = {
    &dog_sit1_90,
    &dog_sit2_90,
    &dog_walk1_90,
    &dog_walk2_90,
    &dog_run1_90,
    &dog_run2_90,
};

uint8_t get_luna_frame(uint8_t wpm) {
    static uint8_t frame_toggle = 0;
    static uint8_t last_wpm_bracket = 0;
    uint8_t current_bracket;

    if (wpm < 15) {
        current_bracket = 0;
    } else if (wpm < 70) {
        current_bracket = 1;
    } else {
        current_bracket = 2;
    }

    if (current_bracket != last_wpm_bracket) {
        frame_toggle = 0;
        last_wpm_bracket = current_bracket;
    } else {
        frame_toggle = !frame_toggle;
    }

    if (wpm < 15) {
        return frame_toggle ? LUNA_FRAME_SIT1 : LUNA_FRAME_SIT2;
    } else if (wpm < 70) {
        return frame_toggle ? LUNA_FRAME_WALK1 : LUNA_FRAME_WALK2;
    } else {
        return frame_toggle ? LUNA_FRAME_RUN1 : LUNA_FRAME_RUN2;
    }
}

void draw_luna(lv_obj_t *canvas, const struct status_state *state) {
    lv_draw_img_dsc_t img_dsc;
    lv_draw_img_dsc_init(&img_dsc);

    uint8_t frame = state->luna_frame;
    if (frame >= sizeof(luna_frames) / sizeof(luna_frames[0])) {
        frame = 0;
    }

    lv_canvas_draw_img(canvas, 0, 0 + BUFFER_OFFSET_MIDDLE, luna_frames[frame], &img_dsc);
}
