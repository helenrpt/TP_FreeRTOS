################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ThirdParty/FreeRTOS/Source/portable/MemMang/heap_4.c 

OBJS += \
./ThirdParty/FreeRTOS/Source/portable/MemMang/heap_4.o 

C_DEPS += \
./ThirdParty/FreeRTOS/Source/portable/MemMang/heap_4.d 


# Each subdirectory must supply rules for building sources it contributes
ThirdParty/FreeRTOS/Source/portable/MemMang/%.o ThirdParty/FreeRTOS/Source/portable/MemMang/%.su ThirdParty/FreeRTOS/Source/portable/MemMang/%.cyclo: ../ThirdParty/FreeRTOS/Source/portable/MemMang/%.c ThirdParty/FreeRTOS/Source/portable/MemMang/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F446RETx -c -I../Inc -I"D:/RAPINAT/TPFreeRTOS/2_FreeRTOS2/Drivers/CMSIS/Include" -I"D:/RAPINAT/TPFreeRTOS/2_FreeRTOS2/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"D:/RAPINAT/TPFreeRTOS/2_FreeRTOS2/ThirdParty" -I"D:/RAPINAT/TPFreeRTOS/2_FreeRTOS2/ThirdParty/FreeRTOS/Source/include" -I"D:/RAPINAT/TPFreeRTOS/2_FreeRTOS2/ThirdParty/FreeRTOS/Source/portable" -I"D:/RAPINAT/TPFreeRTOS/2_FreeRTOS2/ThirdParty/FreeRTOS/Source/portable/GCC/ARM_CM4F" -I"D:/RAPINAT/TPFreeRTOS/2_FreeRTOS2/ThirdParty/FreeRTOS/Source/portable/MemMang" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-ThirdParty-2f-FreeRTOS-2f-Source-2f-portable-2f-MemMang

clean-ThirdParty-2f-FreeRTOS-2f-Source-2f-portable-2f-MemMang:
	-$(RM) ./ThirdParty/FreeRTOS/Source/portable/MemMang/heap_4.cyclo ./ThirdParty/FreeRTOS/Source/portable/MemMang/heap_4.d ./ThirdParty/FreeRTOS/Source/portable/MemMang/heap_4.o ./ThirdParty/FreeRTOS/Source/portable/MemMang/heap_4.su

.PHONY: clean-ThirdParty-2f-FreeRTOS-2f-Source-2f-portable-2f-MemMang

