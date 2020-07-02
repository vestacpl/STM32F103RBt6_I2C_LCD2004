################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Drivers/STM32F1xx_HAL_Driver/Src/subdir.mk
-include Core/Startup/subdir.mk
-include Core/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXECUTABLES += \
STM32F103RBt_Tamplate.elf \

SIZE_OUTPUT += \
default.size.stdout \

OBJDUMP_LIST += \
STM32F103RBt_Tamplate.list \

OBJCOPY_BIN += \
STM32F103RBt_Tamplate.bin \


# All Target
all: STM32F103RBt_Tamplate.elf secondary-outputs

# Tool invocations
STM32F103RBt_Tamplate.elf: $(OBJS) $(USER_OBJS) C:\IDE\ Projects\Cube\ IDE\STM32F103RBt_Tamplate\STM32F103RBTX_FLASH.ld
	arm-none-eabi-gcc -o "STM32F103RBt_Tamplate.elf" @"objects.list" $(USER_OBJS) $(LIBS) -mcpu=cortex-m3 -T"C:\IDE Projects\Cube IDE\STM32F103RBt_Tamplate\STM32F103RBTX_FLASH.ld" --specs=nosys.specs -Wl,-Map="STM32F103RBt_Tamplate.map" -Wl,--gc-sections -static --specs=nano.specs -mfloat-abi=soft -mthumb -Wl,--start-group -lc -lm -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

default.size.stdout: $(EXECUTABLES)
	arm-none-eabi-size  $(EXECUTABLES)
	@echo 'Finished building: $@'
	@echo ' '

STM32F103RBt_Tamplate.list: $(EXECUTABLES)
	arm-none-eabi-objdump -h -S $(EXECUTABLES) > "STM32F103RBt_Tamplate.list"
	@echo 'Finished building: $@'
	@echo ' '

STM32F103RBt_Tamplate.bin: $(EXECUTABLES)
	arm-none-eabi-objcopy  -O binary $(EXECUTABLES) "STM32F103RBt_Tamplate.bin"
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
