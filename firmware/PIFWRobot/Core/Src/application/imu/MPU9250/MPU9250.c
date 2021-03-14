
#include <string.h>

#include <application/imu/mpu9250/MPU9250.h>

#define MPU9250_I2C_ADDR	(0x68 << 1)
#define AK8963_I2C_ADDR		(0x0c << 1)
#define I2C_TIMEOUT_MS		20

float g_lsb_per_dpfs;
float g_lsb_per_g;
float g_microTesla_per_LSB;

static int mpu6500_read(uint8_t addr, uint8_t *value){
	if(HAL_I2C_Mem_Read(&MPU9250_I2C, MPU9250_I2C_ADDR, addr, 1, value, 1, I2C_TIMEOUT_MS) != HAL_OK)
		return -1;
	return 0;
}

static int mpu6500_write(uint8_t addr, uint8_t *value){
	if(HAL_I2C_Mem_Write(&MPU9250_I2C, MPU9250_I2C_ADDR, addr, 1, value, 1, I2C_TIMEOUT_MS) != HAL_OK)
		return -1;
	uint8_t tmp;
	if(mpu6500_read(addr, &tmp) < 0) return -1;
	if(tmp != *value) return -1;
	return 0;
}

static int mpu6500_read_bytes(uint8_t addr, uint8_t* value, uint8_t len){
	if(HAL_I2C_Mem_Read(&MPU9250_I2C, MPU9250_I2C_ADDR, addr, 1, value, len, I2C_TIMEOUT_MS) != HAL_OK){
		memset(value, 0, len);
		return -1;
	}
	return 0;
}

//static int mpu6500_write_bytes(uint8_t addr, uint8_t* value, uint8_t len){
//	if(HAL_I2C_Mem_Write(&MPU9250_I2C, MPU9250_I2C_ADDR, addr, 1, value, len, I2C_TIMEOUT_MS) != HAL_OK)
//		return -1;
//	return 0;
//}

//static int mpu6500_read_mask(uint8_t addr, uint8_t* value, uint8_t mask){
//	if(HAL_I2C_Mem_Read(&MPU9250_I2C, MPU9250_I2C_ADDR, addr, 1, value, 1, I2C_TIMEOUT_MS) != HAL_OK){
//		*value = 0;
//		return -1;
//	}
//	*value &= mask;
//	return 0;
//}

static int mpu6500_write_mask(uint8_t addr, uint8_t* value, uint8_t mask){
	uint8_t tmp;
	if(mpu6500_read(addr, &tmp) < 0) return -1;
	tmp &= ~mask;
	tmp += (*value & mask);
	if(mpu6500_write(addr, &tmp) < 0) return -1;
	return 0;
}

static void ak8963_read(uint8_t addr, uint8_t* value){
	HAL_I2C_Mem_Read(&MPU9250_I2C, AK8963_I2C_ADDR, addr, 1, value, 1, I2C_TIMEOUT_MS);
}

//static void ak8963_write(uint8_t addr, uint8_t* value){
//	HAL_I2C_Mem_Write(&MPU9250_I2C, AK8963_I2C_ADDR, addr, 1, value, 1, I2C_TIMEOUT_MS);
//}

int mpu9250_init(gyro_params_t gyro_params, accel_params_t accel_params, mag_params_t mag_params){
	uint8_t tmp;

	// Reset mpu9250
	tmp = H_RESET;
	if(mpu6500_write_mask(MPU9250_PWR_MGMT_1, &tmp, H_RESET_MASK) < 0) return -1;

	// Wake up chip.
	tmp = 0x00;
	if(mpu6500_write(MPU9250_PWR_MGMT_1, &tmp) < 0) return -1;

	// i2c bypass mode clock source
	tmp = BYPASS_EN;
	if(mpu6500_write_mask(MPU9250_INT_PIN_CFG, &tmp, BYPASS_EN_MASK) < 0) return -1;

	if(mpu9250_test() < 0) return -1;

	// mpu9250 clock source
	tmp = CLKSEL;
	if(mpu6500_write_mask(MPU9250_PWR_MGMT_1, &tmp, CLKSEL_MASK) < 0) return -1;

	switch(gyro_params.gfsr){
		case GFS_SEL_250DPS:
			tmp = GYRO_FS_SEL_250DPS;
			if(mpu6500_write_mask(MPU9250_GYRO_CONFIG, &tmp, GYRO_FS_SEL_MASK) < 0) return -1;
			g_lsb_per_dpfs = 131.f;
			break;
		case GFS_SEL_500DPS:
			tmp = GYRO_FS_SEL_500DPS;
			if(mpu6500_write_mask(MPU9250_GYRO_CONFIG, &tmp, GYRO_FS_SEL_MASK) < 0) return -1;
			g_lsb_per_dpfs = 65.5f;
			break;
	    case GFS_SEL_1000DPS:
			tmp = GYRO_FS_SEL_1000DPS;
			if(mpu6500_write_mask(MPU9250_GYRO_CONFIG, &tmp, GYRO_FS_SEL_MASK) < 0) return -1;
			g_lsb_per_dpfs = 32.8f;
	    	break;
	    case GFS_SEL_2000DPS:
			tmp = GYRO_FS_SEL_2000DPS;
			if(mpu6500_write_mask(MPU9250_GYRO_CONFIG, &tmp, GYRO_FS_SEL_MASK) < 0) return -1;
			g_lsb_per_dpfs = 16.4f;
	      break;
		default:
			tmp = GYRO_FS_SEL_250DPS;
			if(mpu6500_write_mask(MPU9250_GYRO_CONFIG, &tmp, GYRO_FS_SEL_MASK) < 0) return -1;
			g_lsb_per_dpfs = 131.f;
			break;
	}

	switch(accel_params.afsr){
		case AFS_SEL_2G:
			tmp = ACCEL_FS_SEL_2G;
			if(mpu6500_write_mask(MPU9250_ACCEL_CONFIG, &tmp, ACCEL_FS_SEL_MASK) < 0) return -1;
			g_lsb_per_g = 16384.f;
			break;
		case AFS_SEL_4G:
			tmp = ACCEL_FS_SEL_4G;
			if(mpu6500_write_mask(MPU9250_ACCEL_CONFIG, &tmp, ACCEL_FS_SEL_MASK) < 0) return -1;
			g_lsb_per_g = 8192.f;
			break;
	    case AFS_SEL_8G:
			tmp = ACCEL_FS_SEL_8G;
			if(mpu6500_write_mask(MPU9250_ACCEL_CONFIG, &tmp, ACCEL_FS_SEL_MASK) < 0) return -1;
			g_lsb_per_g = 4096.f;
	    	break;
	    case AFS_SEL_16G:
			tmp = ACCEL_FS_SEL_16G;
			if(mpu6500_write_mask(MPU9250_ACCEL_CONFIG, &tmp, ACCEL_FS_SEL_MASK) < 0) return -1;
			g_lsb_per_g = 2048.f;
	      break;
		default:
			tmp = ACCEL_FS_SEL_2G;
			if(mpu6500_write_mask(MPU9250_ACCEL_CONFIG, &tmp, ACCEL_FS_SEL_MASK) < 0) return -1;
			g_lsb_per_g = 16384.f;
			break;
	}

	g_microTesla_per_LSB = 0.6f;

	return 0;
}

int mpu9250_test(){
	uint8_t tmp;

	mpu6500_read(MPU9250_WHO_AM_I, &tmp);
	if(tmp!=MPU9250_WAI_RESULT) return -1;

	ak8963_read(AK8963_WIA, &tmp);
	if(tmp!=AK8963_WAI_RESULT) return -1;

	return 0;
}

int mpu9250_get_accel_gyro(float *ax, float *ay, float *az, float *gx, float *gy, float *gz){
	uint8_t buffer[14] = {};
	if(mpu6500_read_bytes(MPU9250_ACCEL_XOUT_H, buffer, 14) < 0){
		return -1;
	}

    *ax = (int16_t)((int16_t)buffer[0]  << 8) | buffer[1];	*ax /= g_lsb_per_g;
    *ay = (int16_t)((int16_t)buffer[2]  << 8) | buffer[3];  *ay /= g_lsb_per_g;
    *az = (int16_t)((int16_t)buffer[4]  << 8) | buffer[5];  *az /= g_lsb_per_g;
    *gx = (int16_t)((int16_t)buffer[8]  << 8) | buffer[9];	*gx /= g_lsb_per_dpfs;
    *gy = (int16_t)((int16_t)buffer[10] << 8) | buffer[11]; *gy /= g_lsb_per_dpfs;
    *gz = (int16_t)((int16_t)buffer[12] << 8) | buffer[13]; *gz /= g_lsb_per_dpfs;

	return 0;
}

int mpu9250_get_mag(float *mx, float *my, float *mz){
	*mx=0;
	*my=0;
	*mz=0;
	return -1;
}
