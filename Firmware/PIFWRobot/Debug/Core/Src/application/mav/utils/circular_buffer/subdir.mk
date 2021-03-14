################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/application/mav/utils/circular_buffer/circular_buffer.c 

OBJS += \
./Core/Src/application/mav/utils/circular_buffer/circular_buffer.o 

C_DEPS += \
./Core/Src/application/mav/utils/circular_buffer/circular_buffer.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/application/mav/utils/circular_buffer/circular_buffer.o: ../Core/Src/application/mav/utils/circular_buffer/circular_buffer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F103xB -DDEBUG -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"D:/Projects/PIFWRobot/firmware/PIFWRobot/Core/Src" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Core/Src/application/mav/utils/circular_buffer/circular_buffer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

