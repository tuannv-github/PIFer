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
void neopixel_set_color(uint8_t index, float r, float g, float b);
void neopixel_set_color32(uint8_t index, uint32_t color);

uint32_t neopixel_get_color32(uint8_t index);

int neopixel_show();

typedef void (*neopixel_update_func_t)(void);

#endif /* SRC_NEOPIXEL_COMMON_H_ */
