/*
 * Copyright (c) 2024 The ZMK Contributors
 *
 * SPDX-License-Identifier: MIT
 */

#pragma once

#include <lvgl.h>
#include <zephyr/kernel.h>
#include "util.h"

void draw_luna(lv_obj_t *canvas, const struct status_state *state);
uint8_t get_luna_frame(uint8_t wpm);
