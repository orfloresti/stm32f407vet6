################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Startup/subdir.mk
-include Src/subdir.mk
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
bm-nucleo-l476rg-hsi-measurements.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
bm-nucleo-l476rg-hsi-measurements.list \

OBJCOPY_BIN += \
bm-nucleo-l476rg-hsi-measurements.bin \


# All Target
all: bm-nucleo-l476rg-hsi-measurements.elf secondary-outputs

# Tool invocations
bm-nucleo-l476rg-hsi-measurements.elf: $(OBJS) $(USER_OBJS) /home/orlando_floresti/ARMProjects/SourceCode/stm32cubeide/nucleo-l476rg/bm-nucleo-l476rg-hsi-measurements/STM32L476RGTX_FLASH.ld
	arm-none-eabi-gcc -o "bm-nucleo-l476rg-hsi-measurements.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m4 -T"/home/orlando_floresti/ARMProjects/SourceCode/stm32cubeide/nucleo-l476rg/bm-nucleo-l476rg-hsi-measurements/STM32L476RGTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="bm-nucleo-l476rg-hsi-measurements.map" -Wl,--gc-sections -static --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

bm-nucleo-l476rg-hsi-measurements.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "bm-nucleo-l476rg-hsi-measurements.list"
	@echo 'Finished building: $@'
	@echo ' '

bm-nucleo-l476rg-hsi-measurements.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "bm-nucleo-l476rg-hsi-measurements.bin"
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
