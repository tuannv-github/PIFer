################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/application/timer/subdir.mk
-include Core/Src/application/pid/subdir.mk
-include Core/Src/application/params/subdir.mk
-include Core/Src/application/neopixel/app_rainbow/subdir.mk
-include Core/Src/application/neopixel/app_loading/subdir.mk
-include Core/Src/application/neopixel/abs/subdir.mk
-include Core/Src/application/motors/subdir.mk
-include Core/Src/application/mode/mode_run/subdir.mk
-include Core/Src/application/mode/mode_pidt/subdir.mk
-include Core/Src/application/mode/mode_imu/subdir.mk
-include Core/Src/application/mode/mode_hw/subdir.mk
-include Core/Src/application/mav/utils/circular_buffer/subdir.mk
-include Core/Src/application/mav/uart/subdir.mk
-include Core/Src/application/mav/nrf24/subdir.mk
-include Core/Src/application/mav/subdir.mk
-include Core/Src/application/imu/MPU9250/subdir.mk
-include Core/Src/application/imu/MPU6050/subdir.mk
-include Core/Src/application/imu/subdir.mk
-include Core/Src/application/encoder/subdir.mk
-include Core/Src/application/buzzer/subdir.mk
-include Core/Src/application/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

BUILD_ARTIFACT_NAME := PIFWRobot
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX := 
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME).$(BUILD_ARTIFACT_EXTENSION)

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
PIFWRobot.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
PIFWRobot.list \

OBJCOPY_BIN += \
PIFWRobot.bin \


# All Target
all: main-build

# Main-build Target
main-build: PIFWRobot.elf secondary-outputs

# Tool invocations
PIFWRobot.elf: $(OBJS) $(USER_OBJS) D:\Projects\PIFWRobot\firmware\PIFWRobot\STM32F103C8TX_FLASH.ld
	arm-none-eabi-gcc -o "PIFWRobot.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"D:\Projects\PIFWRobot\firmware\PIFWRobot\STM32F103C8TX_FLASH.ld" --specs=nosys.specs -Wl,-Map="PIFWRobot.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

PIFWRobot.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "PIFWRobot.list"
	@echo 'Finished building: $@'
	@echo ' '

PIFWRobot.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "PIFWRobot.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

fail-specified-linker-script-missing:
	@echo 'Error: Cannot find the specified linker script. Check the linker settings in the build configuration.'
	@exit 2

warn-no-linker-script-specified:
	@echo 'Warning: No linker script specified. Check the linker settings in the build configuration.'

.PHONY: all clean dependents fail-specified-linker-script-missing warn-no-linker-script-specified
.SECONDARY:

-include ../makefile.targets
