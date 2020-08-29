/*
 * Encoder.h
 *
 *  Created on: Dec 17, 2019
 *      Author: 16138
 */

#ifndef APPLICATION_ENCODER_ENCODER_H_
#define APPLICATION_ENCODER_ENCODER_H_

#include <application/motors/motors.h>

void enc_init();
int16_t enc_read(motors_t motor);

#endif /* APPLICATION_ENCODER_ENCODER_H_ */
