#ifndef _MPU9250_H_
#define _MPU9250_H_

#include <stdint.h>
#include <stdbool.h>

int mpu9250_init();
int mpu9250_test();

int mpu9250_get_accel_gyro(float *ax, float *ay, float *az, float *gx, float *gy, float *gz);
int mpu9250_get_mag(float *mx, float *my, float *mz);

#endif
