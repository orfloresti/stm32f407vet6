################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32L4xx_HAL_Driver/Src/subdir.mk
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
hal-nucleo-l476rg-adc-triggered.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
hal-nucleo-l476rg-adc-triggered.list \

OBJCOPY_BIN += \
hal-nucleo-l476rg-adc-triggered.bin \


# All Target
all: hal-nucleo-l476rg-adc-triggered.elf secondary-outputs

# Tool invocations
hal-nucleo-l476rg-adc-triggered.elf: $(OBJS) $(USER_OBJS) /home/orlando_floresti/ARMProjects/SourceCode/stm32cubeide/nucleo-l476rg/hal-nucleo-l476rg-adc-triggered/STM32L476RGTX_FLASH.ld
	arm-none-eabi-gcc -o "hal-nucleo-l476rg-adc-triggered.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/home/orlando_floresti/ARMProjects/SourceCode/stm32cubeide/nucleo-l476rg/hal-nucleo-l476rg-adc-triggered/STM32L476RGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="hal-nucleo-l476rg-adc-triggered.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

hal-nucleo-l476rg-adc-triggered.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "hal-nucleo-l476rg-adc-triggered.list"
	@echo 'Finished building: $@'
	@echo ' '

hal-nucleo-l476rg-adc-triggered.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "hal-nucleo-l476rg-adc-triggered.bin"
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
