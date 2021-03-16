/*
 * rainbow.c
 *
 *  Created on: Mar 12, 2021
 *      Author: tuannv
 */

#include "../config.h"
#include "../abs/common.h"
#include "rainbow.h"

static uint32_t rainbow_wheel(uint8_t wheel_pos) {
	wheel_pos = 255 - wheel_pos;
  if(wheel_pos < 85) {
    return RGB(255 - wheel_pos * 3, 0, wheel_pos * 3);
  }
  if(wheel_pos < 170) {
	  wheel_pos -= 85;
    return RGB(0, wheel_pos * 3, 255 - wheel_pos * 3);
  }
  wheel_pos -= 170;
  return RGB(wheel_pos * 3, 255 - wheel_pos * 3, 0);
}

static uint16_t g_color = 0;
void rainbow(){
	uint16_t i;
	g_color++;
	if(g_color>255) g_color = 0;
	for(i=0; i<NUM_PIXELS; i++) {
		uint32_t rgb_color = rainbow_wheel((i+g_color) & 255);
		neopixel_set_color(i, (rgb_color >> 16) & 0xFF, (rgb_color >> 8) & 0xFF, rgb_color & 0xFF);
	}
	neopixel_show();
}
