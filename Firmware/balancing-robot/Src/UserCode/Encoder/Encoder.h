/*
 * Encoder.h
 *
 *  Created on: Dec 17, 2019
 *      Author: 16138
 */

#ifndef USERCODE_ENCODER_ENCODER_H_
#define USERCODE_ENCODER_ENCODER_H_

#include <UserCode/Motors/Motors.h>

void enc_init();
int16_t enc_read(motors_t motor);

#endif /* USERCODE_ENCODER_ENCODER_H_ */
