################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Utils/fonts.c \
../Drivers/Utils/framebuffer.c \
../Drivers/Utils/random.c \
../Drivers/Utils/timer.c 

C_DEPS += \
./Drivers/Utils/fonts.d \
./Drivers/Utils/framebuffer.d \
./Drivers/Utils/random.d \
./Drivers/Utils/timer.d 

OBJS += \
./Drivers/Utils/fonts.o \
./Drivers/Utils/framebuffer.o \
./Drivers/Utils/random.o \
./Drivers/Utils/timer.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Utils/%.o Drivers/Utils/%.su Drivers/Utils/%.cyclo: ../Drivers/Utils/%.c Drivers/Utils/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/danii/STM32CubeIDE/workspace_1.19.0/game/Game" -I"C:/Users/danii/STM32CubeIDE/workspace_1.19.0/game/Drivers/BSP" -I"C:/Users/danii/STM32CubeIDE/workspace_1.19.0/game/Drivers/Utils" -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-Utils

clean-Drivers-2f-Utils:
	-$(RM) ./Drivers/Utils/fonts.cyclo ./Drivers/Utils/fonts.d ./Drivers/Utils/fonts.o ./Drivers/Utils/fonts.su ./Drivers/Utils/framebuffer.cyclo ./Drivers/Utils/framebuffer.d ./Drivers/Utils/framebuffer.o ./Drivers/Utils/framebuffer.su ./Drivers/Utils/random.cyclo ./Drivers/Utils/random.d ./Drivers/Utils/random.o ./Drivers/Utils/random.su ./Drivers/Utils/timer.cyclo ./Drivers/Utils/timer.d ./Drivers/Utils/timer.o ./Drivers/Utils/timer.su

.PHONY: clean-Drivers-2f-Utils

