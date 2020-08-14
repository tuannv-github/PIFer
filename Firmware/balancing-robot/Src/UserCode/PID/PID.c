/*
 * PID.c
 *
 *  Created on: Oct 10, 2019
 *      Author: 16138
 */
#include "math.h"
#include "PID.h"

float pid_compute(pid_params_t *pid_params, float sp, float fb){

	// Save set point, feed back and error
	pid_params->sp = sp;
	pid_params->fb = fb;
	pid_params->err = sp-fb;

	// Compute P part
	pid_params->P_Part = pid_params->KP*pid_params->err;

	// Compute I part and saturate it
	pid_params->I_Part = pid_params->preIPart + pid_params->KI*pid_params->err;
	if(pid_params->I_Part < pid_params->minIpart) pid_params->I_Part = pid_params->minIpart;
	if(pid_params->I_Part > pid_params->maxIPart) pid_params->I_Part = pid_params->maxIPart;
	pid_params->preIPart = pid_params->I_Part;

	// Compute D part and saturate it
	if(pid_params->isFistCompute){
		pid_params->preError = pid_params->err;
		pid_params->isFistCompute = false;
	}
	pid_params->D_Part = pid_params->KD*(pid_params->err-pid_params->preError);
	if(pid_params->D_Part < pid_params->minDpart) pid_params->D_Part = pid_params->minDpart;
	if(pid_params->D_Part > pid_params->maxDPart) pid_params->D_Part = pid_params->maxDPart;
	pid_params->preError = pid_params->err;

	// Compute control signal and saturate it
	pid_params->U = pid_params->P_Part + pid_params->I_Part + pid_params->D_Part;
	if(pid_params->U < pid_params->minOut) pid_params->U = pid_params->minOut;
	if(pid_params->U > pid_params->maxOut) pid_params->U = pid_params->maxOut;

	return pid_params->U;
}

void pid_reset(pid_params_t *pid_params){
	pid_params->sp=0;
	pid_params->fb=0;
	pid_params->err=0;
	pid_params->isFistCompute=true;
	pid_params->preIPart = 0;
	pid_params->preError = 0;
	pid_params->P_Part=0;
	pid_params->I_Part=0;
	pid_params->D_Part=0;
	pid_params->U=0;
}
