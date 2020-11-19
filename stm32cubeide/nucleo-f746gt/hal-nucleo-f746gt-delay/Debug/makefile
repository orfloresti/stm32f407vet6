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
bm-stm32f746gt-delay.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
bm-stm32f746gt-delay.list \

OBJCOPY_BIN += \
bm-stm32f746gt-delay.bin \


# All Target
all: bm-stm32f746gt-delay.elf secondary-outputs

# Tool invocations
bm-stm32f746gt-delay.elf: $(OBJS) $(USER_OBJS) D:\STM32Projects\bm-stm32f746gt-delay\STM32F746ZGTX_FLASH.ld
	arm-none-eabi-gcc -o "bm-stm32f746gt-delay.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m7 -T"D:\STM32Projects\bm-stm32f746gt-delay\STM32F746ZGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="bm-stm32f746gt-delay.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv5-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

bm-stm32f746gt-delay.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "bm-stm32f746gt-delay.list"
	@echo 'Finished building: $@'
	@echo ' '

bm-stm32f746gt-delay.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "bm-stm32f746gt-delay.bin"
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
