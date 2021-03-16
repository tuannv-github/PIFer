/*
 * config.h
 *
 *  Created on: Mar 12, 2021
 *      Author: tuannv
 */

#ifndef INC_NEOPIXEL_CONFIG_H_
#define INC_NEOPIXEL_CONFIG_H_

// 0 --> Circular DMA --> Small memory + High CPU usage
// 1 --> Normal	DMA --> Large memory + Low CPU usage
#define NEO_PIXEL_USE_IMPL	1

#define TIMER			htim1
#define	TIMER_CHANNEL	TIM_CHANNEL_1
#define TIMER_DMA		hdma_tim1_ch1

#define PWM_HI (50)
#define PWM_LO (28)

#define NUM_BPP 		(3) // WS2812B
//#define NUM_BPP 		(4) // SK6812
#define NUM_PIXELS 		(16)

#endif /* INC_NEOPIXEL_CONFIG_H_ */
