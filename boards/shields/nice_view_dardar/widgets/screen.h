#pragma once

#include <lvgl.h>
#include <zephyr/kernel.h>
#include "util.h"
#include "luna.h"
#include "sleep_status.h"

struct zmk_widget_screen {
    sys_snode_t node;
    lv_obj_t *obj;
    lv_color_t cbuf[BUFFER_SIZE * BUFFER_SIZE];
    lv_color_t cbuf2[BUFFER_SIZE * BUFFER_SIZE];
    lv_color_t cbuf3[BUFFER_SIZE * BUFFER_SIZE];
    struct status_state state;
    struct zmk_widget_luna luna_widget;
    struct zmk_widget_sleep_status sleep_status_widget;
};

int zmk_widget_screen_init(struct zmk_widget_screen *widget, lv_obj_t *parent);
lv_obj_t *zmk_widget_screen_obj(struct zmk_widget_screen *widget);
