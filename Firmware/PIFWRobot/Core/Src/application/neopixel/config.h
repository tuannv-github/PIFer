/*
 * config.h
 *
 *  Created on: Mar 12, 2021
 *      Author: tuannv
 */

#ifndef INC_NEOPIXEL_CONFIG_H_
#define INC_NEOPIXEL_CONFIG_H_

#define TIMER			htim1
#define	TIMER_CHANNEL	TIM_CHANNEL_1
#define TIMER_DMA		hdma_tim1_ch1

#define PWM_HI (38)
#define PWM_LO (19)

#define NUM_BPP 		(3) // WS2812B
//#define NUM_BPP 		(4) // SK6812
#define NUM_PIXELS 		(16)
#define NUM_BYTES 		(NUM_BPP * NUM_PIXELS)

#endif /* INC_NEOPIXEL_CONFIG_H_ */
