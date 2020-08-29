#ifndef _MPU9250_H_
#define _MPU9250_H_

#include <application/imu/mpu9250/MPU9250_RegisterMap.h>
#include <application/user_define.h>
#include <stdint.h>
#include <stdbool.h>


typedef enum{
	GFS_SEL_250DPS,
	GFS_SEL_500DPS,
	GFS_SEL_1000DPS,
	GFS_SEL_2000DPS
}gfsr_t;	// gyroscope full-scale range

typedef enum{
	AFS_SEL_2G,
	AFS_SEL_4G,
	AFS_SEL_8G,
	AFS_SEL_16G
}afsr_t;	// accelerometer full-scale range

typedef struct{
	gfsr_t gfsr;
}gyro_params_t;

typedef struct{
	afsr_t afsr;
}accel_params_t;

typedef struct{

}mag_params_t;

int mpu9250_init(gyro_params_t gyro_params, accel_params_t accel_params, mag_params_t mag_params);
int mpu9250_test();

int mpu9250_get_accel_gyro(float *ax, float *ay, float *az, float *gx, float *gy, float *gz);
int mpu9250_get_mag(float *mx, float *my, float *mz);

#endif
