/*
 * config.h
 *
 *  Created on: Mar 20, 2021
 *      Author: tuannv
 */

#ifndef SRC_MPU9250_CONFIG_H_
#define SRC_MPU9250_CONFIG_H_

#define MPU9250_I2C			hi2c1
#define MPU9250_I2C_ADDR	(0x68 << 1)
#define AK8963_I2C_ADDR		(0x0c << 1)
#define I2C_TIMEOUT_MS		20

//GFS_SEL_250DPS	--> 0
//GFS_SEL_500DPS	--> 1
//GFS_SEL_1000DPS	--> 2
//GFS_SEL_2000DPS	--> 3
#define GFS_SEL			0

//AFS_SEL_2G		--> 0
//AFS_SEL_4G		--> 1
//AFS_SEL_8G		--> 2
//AFS_SEL_16G		--> 3
#define ACCEL_FS_SEL	0

#endif /* SRC_MPU9250_CONFIG_H_ */
