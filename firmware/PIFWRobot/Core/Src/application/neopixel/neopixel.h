/*
 * neopixel.h
 *
 *  Created on: Mar 15, 2021
 *      Author: tuannv
 */

#ifndef SRC_APPLICATION_NEOPIXEL_NEOPIXEL_H_
#define SRC_APPLICATION_NEOPIXEL_NEOPIXEL_H_

typedef enum {
	NEOPIXEL_APP_LOADING = 0,
	NEOPIXEL_APP_RAINBOW,
	NEOPIXEL_APP_SELFBALACING,
	NEOPIXEL_APP_MAX
}neoxpixel_app_t;

void neopixel_init();
void neopixel_set_app(neoxpixel_app_t neoxpixel_app);

#endif /* SRC_APPLICATION_NEOPIXEL_NEOPIXEL_H_ */
