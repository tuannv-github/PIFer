#ifndef _MPU6050_H_
#define _MPU6050_H_

#include "stdbool.h"
#include "UserCode/user_define.h"

typedef enum{
	MPU6050_INTERNAL_8MHZ_OSC 	= 0 << 0,
	MPU6050_PLL_X_GYRO 			= 1 << 0,
	MPU6050_PLL_Y_GYRO 			= 2 << 0,
	MPU6050_PLL_Z_GYRO 			= 3 << 0,
	MPU6050_PLL_EXT_32KHZ 		= 4 << 0,
	MPU6050_PLL_EXT_19MHZ 		= 5 << 0,
	MPU6050_CLOCK_STOP 			= 7 << 0
}mpu6050_clock_source_t;

typedef enum{
	MPU6050_FS_SEL_250 	= 0 << 3, // ± 250 °/s
	MPU6050_FS_SEL_500 	= 1 << 3, // ± 500 °/s
	MPU6050_FS_SEL_1000 = 2 << 3, // ± 1000 °/s
	MPU6050_FS_SEL_2000 = 3 << 3, // ± 2000 °/s
}mpu6050_fs_sel_t;

typedef enum{
	MPU6050_AFS_SEL_2G 	= 0 << 3, // ± 2g
	MPU6050_AFS_SEL_4G 	= 1 << 3, // ± 4g
	MPU6050_AFS_SEL_8G 	= 2 << 3, // ± 8g
	MPU6050_AFS_SEL_16G = 3 << 3, // ± 16g
}mpu6050_afs_sel_t;

void MPU6050_init();
bool MPU6050_test_connection();
void mpu6050_set_full_scale_gyro_range(mpu6050_fs_sel_t fs_sel);
void mpu6050_set_full_scale_accel_range(mpu6050_afs_sel_t afs_sel);
void mpu6050_get_motion(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz);

#endif /* _MPU6050_H_ */
