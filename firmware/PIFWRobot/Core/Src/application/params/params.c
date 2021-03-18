/*
 * Params.c
 *
 *  Created on: Oct 12, 2019
 *      Author: 16138
 */

#include <application/params/params.h>
#include <application/user_define.h>
#include <stm32f1xx.h>

params_t params = {
		.pid[0] = {
				.KP = 0,
				.KI = 0,
				.KD = 0,

				.minIpart = -1000,
				.maxIPart = 1000,
				.minDpart = -1000,
				.maxDPart = 1000,
				.minOut = -1000,
				.maxOut = 1000,

				.preIPart = 0,
				.preError = 0,
				.isFistCompute = true
		},

		.pid[1] = {
				.KP = 0,
				.KI = 0,
				.KD = 0,

				.minIpart = -1000,
				.maxIPart = 1000,
				.minDpart = -1000,
				.maxDPart = 1000,
				.minOut = -1000,
				.maxOut = 1000,

				.preIPart = 0,
				.preError = 0,
				.isFistCompute = true
		},

		.pid[2] = {
				.KP = 0,
				.KI = 0,
				.KD = 0,

				.minIpart = -1000,
				.maxIPart = 1000,
				.minDpart = -1000,
				.maxDPart = 1000,
				.minOut = -1000,
				.maxOut = 1000,

				.preIPart = 0,
				.preError = 0,
				.isFistCompute = true
		},

		.tilt_type = ROLL,
		.tilt_offset = 0,
		.g_believe = 0.99,

		.gx_offset = 1,
		.gy_offset = 2,
		.gz_offset = 3,
};

static uint32_t address = PARAMS_PAGE_ADDRESS;

static void write(uint32_t* ptr){
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, address, *ptr);
	address+=4;
}

static void read(uint32_t* ptr){
	*ptr = *((__IO uint32_t*)address);
	address+=4;
}

void params_save(){
	HAL_FLASH_Unlock();

	FLASH_EraseInitTypeDef EraseInitStruct;
	EraseInitStruct.TypeErase   = FLASH_TYPEERASE_PAGES;
	EraseInitStruct.PageAddress = PARAMS_PAGE_ADDRESS;
	EraseInitStruct.NbPages     = 1;

	uint32_t PageError = 0;
	HAL_FLASHEx_Erase(&EraseInitStruct, &PageError);

	address = PARAMS_PAGE_ADDRESS;

	uint32_t saved = HAVE_SAVED_DATA;
	write(&saved);

	// wheels pid
	write((uint32_t*)(&params.pid[0].KP));
	write((uint32_t*)(&params.pid[0].KI));
	write((uint32_t*)(&params.pid[0].KD));

	write((uint32_t*)(&params.pid[1].KP));
	write((uint32_t*)(&params.pid[1].KI));
	write((uint32_t*)(&params.pid[1].KD));

	// stability or sync pid
	write((uint32_t*)(&params.pid[2].KP));
	write((uint32_t*)(&params.pid[2].KI));
	write((uint32_t*)(&params.pid[2].KD));

	// IMU
	write((uint32_t*)(&params.tilt_type));
	write((uint32_t*)(&params.tilt_offset));
	write((uint32_t*)(&params.g_believe));

	write((uint32_t*)(&params.gx_offset));
	write((uint32_t*)(&params.gy_offset));
	write((uint32_t*)(&params.gz_offset));

	write((uint32_t*)(&params.mx_offset));
	write((uint32_t*)(&params.my_offset));
	write((uint32_t*)(&params.mz_offset));

	write((uint32_t*)(&params.mx_scale));
	write((uint32_t*)(&params.my_scale));
	write((uint32_t*)(&params.mz_scale));

	//HW
	write((uint32_t*)(&params.motor0_invert));
	write((uint32_t*)(&params.motor1_invert));
	write((uint32_t*)(&params.encoder0_invert));
	write((uint32_t*)(&params.encoder1_invert));
	write((uint32_t*)(&params.encoder_exchange));

	write((uint32_t*)(&params.motor0_pos_deadband));
	write((uint32_t*)(&params.motor0_neg_deadband));
	write((uint32_t*)(&params.motor1_pos_deadband));
	write((uint32_t*)(&params.motor1_neg_deadband));

	HAL_FLASH_Lock();
}

bool params_load(){
	address = PARAMS_PAGE_ADDRESS;

	if((*(__IO uint32_t*) address) != HAVE_SAVED_DATA) return false;
	address+=4;

	// wheels pid
	read((uint32_t*)(&params.pid[0].KP));
	read((uint32_t*)(&params.pid[0].KI));
	read((uint32_t*)(&params.pid[0].KD));

	read((uint32_t*)(&params.pid[1].KP));
	read((uint32_t*)(&params.pid[1].KI));
	read((uint32_t*)(&params.pid[1].KD));

	// stability or sync pid
	read((uint32_t*)(&params.pid[2].KP));
	read((uint32_t*)(&params.pid[2].KI));
	read((uint32_t*)(&params.pid[2].KD));

	// IMU
	read((uint32_t*)(&params.tilt_type));
	read((uint32_t*)(&params.tilt_offset));
	read((uint32_t*)(&params.g_believe));

	read((uint32_t*)(&params.gx_offset));
	read((uint32_t*)(&params.gy_offset));
	read((uint32_t*)(&params.gz_offset));

	read((uint32_t*)(&params.mx_offset));
	read((uint32_t*)(&params.my_offset));
	read((uint32_t*)(&params.mz_offset));

	read((uint32_t*)(&params.mx_scale));
	read((uint32_t*)(&params.my_scale));
	read((uint32_t*)(&params.mz_scale));

	//HW
	read((uint32_t*)(&params.motor0_invert));
	read((uint32_t*)(&params.motor1_invert));
	read((uint32_t*)(&params.encoder0_invert));
	read((uint32_t*)(&params.encoder1_invert));
	read((uint32_t*)(&params.encoder_exchange));

	read((uint32_t*)(&params.motor0_pos_deadband));
	read((uint32_t*)(&params.motor0_neg_deadband));
	read((uint32_t*)(&params.motor1_pos_deadband));
	read((uint32_t*)(&params.motor1_neg_deadband));

	return true;
}