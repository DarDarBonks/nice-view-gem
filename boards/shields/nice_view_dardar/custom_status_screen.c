#include "widgets/screen.h"
#include "widgets/luna.h"
#include "widgets/sleep_status.h"

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(zmk, CONFIG_ZMK_LOG_LEVEL);

#include "assets/pixel_operator_mono.c"
#include "assets/custom_fonts.h"

#if IS_ENABLED(CONFIG_NICE_VIEW_WIDGET_STATUS)
static struct zmk_widget_screen screen_widget;
static struct zmk_widget_luna luna_widget;
static struct zmk_widget_sleep_status sleep_status_widget;
#endif

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen;
    screen = lv_obj_create(NULL);

#if IS_ENABLED(CONFIG_NICE_VIEW_WIDGET_STATUS)
    zmk_widget_screen_init(&screen_widget, screen);
    lv_obj_align(zmk_widget_screen_obj(&screen_widget), LV_ALIGN_TOP_LEFT, 0, 0);
    
    zmk_widget_luna_init(&luna_widget, screen);
    lv_obj_align(zmk_widget_luna_obj(&luna_widget), LV_ALIGN_CENTER, 0, 20);
    
    zmk_widget_sleep_status_init(&sleep_status_widget, screen);
    lv_obj_align(zmk_widget_sleep_status_obj(&sleep_status_widget), LV_ALIGN_CENTER, 0, 0);
#endif

    return screen;
}
