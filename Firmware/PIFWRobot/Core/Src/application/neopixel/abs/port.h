#ifndef _LED_DRIVER_SK6812
#define _LED_DRIVER_SK6812

#include <stdint.h>

void led_set_RGB(uint8_t index, uint8_t r, uint8_t g, uint8_t b);
void led_set_RGBW(uint8_t index, uint8_t r, uint8_t g, uint8_t b, uint8_t w);

uint32_t led_get_RGB(uint8_t index);

void led_render();

#endif
