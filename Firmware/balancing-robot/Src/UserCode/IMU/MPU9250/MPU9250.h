#ifndef _MPU9250_H_
#define _MPU9250_H_

#include <stdint.h>
#include <stdbool.h>

#include <UserCode/user_define.h>
#include "MPU9250_RegisterMap.h"

typedef enum{
	FS_SEL_0,
	FS_SEL_1,
	FS_SEL_2,
	FS_SEL_3
}gfsr_t;	// gyroscope full-scale range

typedef enum{
	AFS_SEL_0,
	AFS_SEL_1,
	AFS_SEL_2,
	AFS_SEL_3
}afsr_t;	// accelerometer full-scale range

typedef struct{
	gfsr_t gfsr;
	uint16_t lpfr; 	// low pass filter response
	uint16_t odr; 	// output data rate
}gyro_params_t;

typedef struct{
	afsr_t afsr;
	uint16_t lpfr; 	// low pass filter response
	uint16_t odr; 	// output data rate
}accel_params_t;

typedef struct{

}mag_params_t;

int mpu9250_init(gyro_params_t gyro_params, accel_params_t accel_params, mag_params_t mag_params);
int mpu9250_test();

int mpu9250_get_accel(float *ax, float *ay, float *az);
int mpu9250_get_gyro(float *gx, float *gy, float *gz);
int mpu9250_get_mag(float *mx, float *my, float *mz);

#endif
