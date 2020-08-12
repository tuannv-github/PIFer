/*
 * Params.h
 *
 *  Created on: Oct 12, 2019
 *      Author: 16138
 */

#ifndef USERCODE_PARAMS_PARAMS_H_
#define USERCODE_PARAMS_PARAMS_H_

#include <stdint.h>
#include "UserCode/PID/PID.h"

typedef struct{
	pid_params_t pid[3];

	float believe_in_gyro;
	float angle_adjusted; // Calibrated vertical angle in earth frame

	int32_t gx_offset;
	int32_t gy_offset;
	int32_t gz_offset;

	int32_t mx_offset;
	int32_t my_offset;
	int32_t mz_offset;

	int32_t mx_scale;
	int32_t my_scale;
	int32_t mz_scale;

	bool motor0_invert;
	bool motor1_invert;
	bool encoder0_invert;
	bool encoder1_invert;
	bool encoder_exchange;
}params_t;

extern params_t params;

void params_save();
bool params_load();

#endif /* USERCODE_PARAMS_PARAMS_H_ */
