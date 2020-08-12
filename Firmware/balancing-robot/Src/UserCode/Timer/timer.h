/*
 * timer.h
 *
 *  Created on: Sep 6, 2019
 *      Author: 16138
 */

#ifndef TIMER_TIMER_H_
#define TIMER_TIMER_H_

#include <stdint.h>

typedef void (*timer_callback_func_t)(uint8_t *context);
typedef int8_t timer_id_t;

typedef enum{
	TIMER_MODE_REPEAT,
	TIMER_MODE_ONE_SHOT
}timer_mode_t;

typedef struct{
	timer_callback_func_t timer_callback_func;
	uint16_t period_ms;
	uint16_t cnt;
	uint8_t *context;
	uint8_t id;
	timer_mode_t mode;
}callback_t;

timer_id_t timer_register_callback(timer_callback_func_t timer_callback_func, uint16_t period_ms, uint8_t* context, timer_mode_t mode);
void timer_unregister_callback(timer_id_t id);

uint64_t milis();
void user_systick();

#endif /* TIMER_TIMER_H_ */
