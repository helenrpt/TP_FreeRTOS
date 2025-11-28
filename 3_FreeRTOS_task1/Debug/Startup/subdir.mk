################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Startup/startup_stm32f446retx.s 

OBJS += \
./Startup/startup_stm32f446retx.o 

S_DEPS += \
./Startup/startup_stm32f446retx.d 


# Each subdirectory must supply rules for building sources it contributes
Startup/%.o: ../Startup/%.s Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I"D:/RAPINAT/TPFreeRTOS/3_FreeRTOS_task1/Drivers/CMSIS/Include" -I"D:/RAPINAT/TPFreeRTOS/3_FreeRTOS_task1/Inc" -I"D:/RAPINAT/TPFreeRTOS/3_FreeRTOS_task1/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/RAPINAT/TPFreeRTOS/3_FreeRTOS_task1/ThirdParty" -I"D:/RAPINAT/TPFreeRTOS/3_FreeRTOS_task1/ThirdParty/FreeRTOS/Source/include" -I"D:/RAPINAT/TPFreeRTOS/3_FreeRTOS_task1/ThirdParty/FreeRTOS/Source/portable" -I"D:/RAPINAT/TPFreeRTOS/3_FreeRTOS_task1/ThirdParty/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"D:/RAPINAT/TPFreeRTOS/3_FreeRTOS_task1/ThirdParty/FreeRTOS/Source/portable/MemMang" -I"D:/RAPINAT/TPFreeRTOS/3_FreeRTOS_task1/ThirdParty/tracealyzer/Inc" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Startup

clean-Startup:
	-$(RM) ./Startup/startup_stm32f446retx.d ./Startup/startup_stm32f446retx.o

.PHONY: clean-Startup

