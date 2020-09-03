/*
 * Params.h
 *
 *  Created on: Oct 12, 2019
 *      Author: 16138
 */

#ifndef APPLICATION_PARAMS_PARAMS_H_
#define APPLICATION_PARAMS_PARAMS_H_

#include <stdint.h>
#include <application/pid/pid.h>
#include <application/com/mavlink/protocol/mavlink.h>

typedef struct{
	pid_params_t pid[3];

	tilt_type_t tilt_type;
	float tilt_offset;
	float g_believe;

	float gx_offset;
	float gy_offset;
	float gz_offset;

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

#endif /* APPLICATION_PARAMS_PARAMS_H_ */
