#include "MPU9250.h"

#define MPU9250_I2C_ADDR	(0x68 << 1)
#define AK8963_I2C_ADDR		(0x0c << 1)
#define I2C_TIMEOUT_MS		20

static void mpu9250_read(uint8_t addr, uint8_t* value){
	HAL_I2C_Mem_Read(&MPU9250_I2C, MPU9250_I2C_ADDR, addr, 1, value, 1, I2C_TIMEOUT_MS);
}

static void mpu9250_write(uint8_t addr, uint8_t* value){
	HAL_I2C_Mem_Write(&MPU9250_I2C, MPU9250_I2C_ADDR, addr, 1, value, 1, I2C_TIMEOUT_MS);
}

static void mpu9250_read_mask(uint8_t addr, uint8_t* value, uint8_t mask){
	HAL_I2C_Mem_Read(&MPU9250_I2C, MPU9250_I2C_ADDR, addr, 1, value, 1, I2C_TIMEOUT_MS);
	*value &= mask;
}

static void mpu9250_write_mask(uint8_t addr, uint8_t* value, uint8_t mask){
	uint8_t tmp;
	mpu9250_read(addr, &tmp);
	tmp &= ~mask;
	*value = (*value & mask) + tmp;
	mpu9250_write(addr, value);
}

static void ak8963_read(uint8_t addr, uint8_t* value){
	HAL_I2C_Mem_Read(&MPU9250_I2C, AK8963_I2C_ADDR, addr, 1, value, 1, I2C_TIMEOUT_MS);
}

static void ak8963_write(uint8_t addr, uint8_t* value){
	HAL_I2C_Mem_Write(&MPU9250_I2C, AK8963_I2C_ADDR, addr, 1, value, 1, I2C_TIMEOUT_MS);
}

int mpu9250_init(gyro_params_t gyro_params, accel_params_t accel_params, mag_params_t mag_params){
	uint8_t tmp;

	// i2c bypass mode clock source
	tmp = BYPASS_EN;
	mpu9250_write_mask(MPU9250_INT_PIN_CFG, &tmp, BYPASS_EN_MASK);

	if(mpu9250_test() < 0) return -1;

	// mpu9250 clock source
	tmp = CLKSEL;
	mpu9250_write_mask(MPU9250_PWR_MGMT_1, &tmp, CLKSEL_MASK);

	switch(gyro_params.gfsr){
		case FS_SEL_0:
			break;
		case FS_SEL_1:
			break;
	    case FS_SEL_2:
	    	break;
	    case FS_SEL_3:
	      break;
	}

	return 0;
}

int mpu9250_test(){
	uint8_t tmp;

	mpu9250_read(MPU9250_WHO_AM_I, &tmp);
	if(tmp!=MPU9250_WAI_RESULT) return -1;

	ak8963_read(AK8963_WIA, &tmp);
	if(tmp!=AK8963_WAI_RESULT) return -1;

	return 0;
}

int mpu9250_get_accel(float *ax, float *ay, float *az){
	return false;
}

int mpu9250_get_gyro(float *gx, float *gy, float *gz){
	return false;
}

int mpu9250_get_mag(float *mx, float *my, float *mz){
	return false;
}
