/*
 * common.c
 *
 *  Created on: Mar 12, 2021
 *      Author: tuannv
 */

#include "../config.h"
#include "common.h"
#include "port.h"

#define MAX_BRIGHTNESS			255.0f

static float g_brightness = 255.0f;

void neopixel_set_brightness(uint8_t brightness) {
	g_brightness = brightness;
}

void neopixel_set_color(uint8_t index, uint8_t r, uint8_t g, uint8_t b){
	led_set_RGB(index, r*g_brightness/MAX_BRIGHTNESS, g*g_brightness/MAX_BRIGHTNESS, b*g_brightness/MAX_BRIGHTNESS);
}

void neopixel_set_color32(uint8_t index, uint32_t color){
	neopixel_set_color(index, (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
}

uint32_t neopixel_get_color32(uint8_t index){
	return led_get_RGB(index);
}

void neopixel_show(){
	led_render();
}
