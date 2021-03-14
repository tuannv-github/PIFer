/*
 * common.h
 *
 *  Created on: Mar 12, 2021
 *      Author: tuannv
 */

#ifndef SRC_NEOPIXEL_COMMON_H_
#define SRC_NEOPIXEL_COMMON_H_

#include <stdint.h>

#define RGB(r,g,b) (uint32_t)(((uint32_t)(r) << 16) | ((uint32_t)(g) <<  8) | (b))

void neopixel_set_brightness(uint8_t brightness);
void neopixel_set_color(uint8_t index, uint8_t r, uint8_t g, uint8_t b);
void neopixel_set_color32(uint8_t index, uint32_t color);

uint32_t neopixel_get_color32(uint8_t index);

void neopixel_show();

#endif /* SRC_NEOPIXEL_COMMON_H_ */
