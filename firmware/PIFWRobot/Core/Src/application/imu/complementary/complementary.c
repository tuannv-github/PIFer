/*
 * complementary.c
 *
 *  Created on: Mar 22, 2021
 *      Author: tuannv
 */

#include <math.h>

#include "complementary.h"

static float qw,qx,qy,qz;

void complementary_init(){
	qw = 1.0f;
	qx = qy = qz = 0.0f;
}

void complementary_update(float gx, float gy, float gz, float ax, float ay, float az, float mx, float my, float mz, float dt){
	float q_omega[4];
	float dt2 = dt/2.0f;
	q_omega[0] = qw - dt2*gx*qx - dt2*gy*qy - dt2*gz*qz;
	q_omega[1] = qx + dt2*gx*qw - dt2*gy*qz + dt2*gz*qy;
	q_omega[2] = qy + dt2*gx*qz + dt2*gy*qw - dt2*gz*qx;
	q_omega[3] = qz - dt2*gx*qy + dt2*gy*qx + dt2*gz*qw;

	// theta=roll, phi=pitch, psi=yaw
	float theta = atan2(ay,az);
	float phi = atan2(-ax,sqrt(ay*ay+az*az));
	float psi = atan2(mz*sin(phi)-my*cos(phi),mx*cos(theta)+sin(theta)*(my*sin(phi)+mz*cos(phi)));

	float q_am[4];
	theta /= 2; phi /= 2; psi /= 2;
	float cos_theta = cos(theta), sin_theta = sin(theta);
	float cos_phi = cos(phi), sin_phi = sin(phi);
	float cos_psi = cos(psi), sin_psi = sin(psi);
	q_am[0] = cos_theta*cos_phi*cos_psi + sin_theta*sin_phi*sin_psi;
	q_am[1] = sin_theta*cos_phi*cos_psi - cos_theta*sin_phi*sin_psi;
	q_am[2] = cos_theta*sin_phi*cos_psi + sin_theta*cos_phi*sin_psi;
	q_am[3] = cos_theta*cos_phi*sin_psi - sin_theta*sin_phi*cos_psi;

	qw = (1-params.complementary_gain)*q_omega[0] + params.complementary_gain*q_am[0];
	qx = (1-params.complementary_gain)*q_omega[1] + params.complementary_gain*q_am[1];
	qy = (1-params.complementary_gain)*q_omega[2] + params.complementary_gain*q_am[2];
	qz = (1-params.complementary_gain)*q_omega[3] + params.complementary_gain*q_am[3];
}

void complementary_get_q(float q[4]){
	q[0] = qw;
	q[1] = qx;
	q[2] = qy;
	q[3] = qz;
}

