/*
 * loading.c
 *
 *  Created on: Mar 12, 2021
 *      Author: tuannv
 */

#include <stdbool.h>

#include "../config.h"
#include "../abs/common.h"
#include "loading.h"

static uint32_t current_idx = 0;

#define NEXT(idx) ((idx)+1>=NUM_PIXELS ? 0 :  (idx+1))
#define PREV(idx) ((int32_t)(idx)-1>=0 ? (idx)-1 : (NUM_PIXELS-1))

void loading(){
	current_idx = NEXT(current_idx);
	bool updated[NUM_PIXELS] = {false};
    for(int i=0; i<NUM_PIXELS; i++) {
    	if(i != current_idx) {
    		if(!updated[i]) neopixel_set_color(i, 0, 0, 0);
    	}
    	else{
    		uint8_t idx = i;
    		neopixel_set_color(idx, 0, 60, 200);
    		updated[idx] = true;

    		idx = PREV(idx);
    		neopixel_set_color(idx, 0, 50, 160);
    		updated[idx] = true;

    		idx = PREV(idx);
    		neopixel_set_color(idx, 0, 40, 120);
    		updated[idx] = true;

    		idx = PREV(idx);
    		neopixel_set_color(idx, 0, 30, 80);
    		updated[idx] = true;

    		idx = PREV(idx);
    		neopixel_set_color(idx, 0, 20, 40);
    		updated[idx] = true;

    		idx = PREV(idx);
    		neopixel_set_color(idx, 0, 10, 20);
    		updated[idx] = true;

    		idx = PREV(idx);
    		neopixel_set_color(idx, 0, 5, 10);
    		updated[idx] = true;
    	}
    }
    neopixel_show();
}
