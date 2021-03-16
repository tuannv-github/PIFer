/*
 * selfbalancing.c
 *
 *  Created on: Mar 15, 2021
 *      Author: tuannv
 */


/*
 * loading.c
 *
 *  Created on: Mar 12, 2021
 *      Author: tuannv
 */

#include <stdbool.h>

#include "../config.h"
#include "../abs/common.h"
#include "selfbalancing.h"


#define CEN_0	0
#define CEN_1	(NUM_PIXELS/2)
#define DEVISION_0	5
#define DEVISION_1	20

#define R 			200
#define G			0
#define B			0

#define NEXT(idx) ((idx)+1>=NUM_PIXELS ? 0 :  (idx+1))
#define PREV(idx) ((int32_t)(idx)-1>=0 ? (idx)-1 : (NUM_PIXELS-1))

static int16_t g_v = 0;
static int16_t g_w = 0;
static int16_t g_background = 0;
static int16_t g_background_dir = 1;

void neopixel_app_self_balancing_set(int16_t v, int16_t w){
	g_v = v;
	g_w = w;
}

void self_balancing_update(){

	int c_0 = CEN_0, c_1 = CEN_1;

	if(g_v > 0){
		for(int i=0; i<g_v; i++){
			c_0 = NEXT(c_0);
			c_1 = PREV(c_1);
		}
	}
	else if(g_v < 0){
		for(int i=g_v; i<0; i++){
			c_0 = PREV(c_0);
			c_1 = NEXT(c_1);
		}
	}

	if(g_w > 0){
		for(int i=0; i<g_w; i++){
			c_0 = PREV(c_0);
			c_1 = PREV(c_1);
		}
	}
	else if(g_w < 0){
		for(int i=g_w; i<0; i++){
			c_0 = NEXT(c_0);
			c_1 = NEXT(c_1);
		}
	}

	g_background+=g_background_dir;
	if(g_background > 50){
		g_background_dir = -1;
		g_background = 50;
	}
	else if(g_background < 0){
		g_background_dir = 1;
		g_background = 0;
	}
	for(uint16_t i=0; i<NUM_PIXELS; i++) {
		neopixel_set_color(i, 0, 50-g_background, g_background);
	}

	neopixel_set_color(PREV(c_0), R/DEVISION_0, G/DEVISION_0, B/DEVISION_0);
	neopixel_set_color(NEXT(c_0), 40, 0, 0);
	neopixel_set_color(c_0, R, G, B);


	neopixel_set_color(PREV(c_1), R/DEVISION_0, G/DEVISION_0, B/DEVISION_0);
	neopixel_set_color(NEXT(c_1), 40, 0, 0);
	neopixel_set_color(c_1, R, G, B);

	neopixel_show();
}
