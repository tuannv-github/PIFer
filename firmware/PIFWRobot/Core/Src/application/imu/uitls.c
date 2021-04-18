/*
 * uitls.c
 *
 *  Created on: Mar 22, 2021
 *      Author: tuannv
 */

#ifndef SRC_APPLICATION_IMU_UITLS_C_
#define SRC_APPLICATION_IMU_UITLS_C_

#include <math.h>

void quaternion_to_rpy(float rpy[3], float q[4]){
	float w=q[0], x=q[1], y=q[2], z=q[3];
    float t0 = +2.0 * (w * x + y * z);
	float t1 = +1.0 - 2.0 * (x * x + y * y);
	rpy[0] = atan2(t0, t1);
	float t2 = +2.0 * (w * y - z * x);
    t2 = t2 > +1.0 ? +1.0 : t2;
    t2 = t2 < -1.0 ? -1.0 : t2;
	rpy[1] = asin(t2);
    float t3 = +2.0 * (w * z + x * y);
    float t4 = +1.0 - 2.0 * (y * y + z * z);
	rpy[2] = atan2(t3, t4);
}

#endif /* SRC_APPLICATION_IMU_UITLS_C_ */
