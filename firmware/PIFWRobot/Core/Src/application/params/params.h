/*
 * Params.h
 *
 *  Created on: Oct 12, 2019
 *      Author: 16138
 */

#ifndef APPLICATION_PARAMS_PARAMS_H_
#define APPLICATION_PARAMS_PARAMS_H_

#include <application/mav/mavlink/protocol/mavlink.h>
#include <stdint.h>
#include <application/pid/pid.h>

typedef struct{
	pid_params_t pid[3];

	tilt_type_t tilt_type;
	float tilt_offset;
	float g_believe;

	float gx_bias;
	float gy_bias;
	float gz_bias;

	float mx_bias;
	float my_bias;
	float mz_bias;

	float mx_scale;
	float my_scale;
	float mz_scale;

	bool motor0_invert;
	bool motor1_invert;
	bool encoder0_invert;
	bool encoder1_invert;
	bool encoder_exchange;
	int16_t motor0_pos_deadband;
	int16_t motor0_neg_deadband;
	int16_t motor1_pos_deadband;
	int16_t motor1_neg_deadband;

	float madgwick_beta;

}params_t;

extern params_t params;

void params_save();
bool params_load();

#endif /* APPLICATION_PARAMS_PARAMS_H_ */
