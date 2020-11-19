################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F7xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
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

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
hal-stm32f746gt-blink.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
hal-stm32f746gt-blink.list \

OBJCOPY_BIN += \
hal-stm32f746gt-blink.bin \


# All Target
all: hal-stm32f746gt-blink.elf secondary-outputs

# Tool invocations
hal-stm32f746gt-blink.elf: $(OBJS) $(USER_OBJS) D:\STM32Projects\hal-stm32f746gt\STM32F746ZGTX_FLASH.ld
	arm-none-eabi-gcc -o "hal-stm32f746gt-blink.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"D:\STM32Projects\hal-stm32f746gt\STM32F746ZGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="hal-stm32f746gt-blink.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

hal-stm32f746gt-blink.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "hal-stm32f746gt-blink.list"
	@echo 'Finished building: $@'
	@echo ' '

hal-stm32f746gt-blink.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "hal-stm32f746gt-blink.bin"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

secondary-outputs: $(SIZE_OUTPUT) $(OBJDUMP_LIST) $(OBJCOPY_BIN)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
