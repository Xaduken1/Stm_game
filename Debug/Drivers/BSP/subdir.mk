################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/BSP/display.c \
../Drivers/BSP/joystick.c \
../Drivers/BSP/storage.c 

C_DEPS += \
./Drivers/BSP/display.d \
./Drivers/BSP/joystick.d \
./Drivers/BSP/storage.d 

OBJS += \
./Drivers/BSP/display.o \
./Drivers/BSP/joystick.o \
./Drivers/BSP/storage.o 


# Each subdirectory must supply rules for building sources it contributes
Drivers/BSP/%.o Drivers/BSP/%.su Drivers/BSP/%.cyclo: ../Drivers/BSP/%.c Drivers/BSP/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/danii/STM32CubeIDE/workspace_1.19.0/game/Game" -I"C:/Users/danii/STM32CubeIDE/workspace_1.19.0/game/Drivers/BSP" -I"C:/Users/danii/STM32CubeIDE/workspace_1.19.0/game/Drivers/Utils" -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-BSP

clean-Drivers-2f-BSP:
	-$(RM) ./Drivers/BSP/display.cyclo ./Drivers/BSP/display.d ./Drivers/BSP/display.o ./Drivers/BSP/display.su ./Drivers/BSP/joystick.cyclo ./Drivers/BSP/joystick.d ./Drivers/BSP/joystick.o ./Drivers/BSP/joystick.su ./Drivers/BSP/storage.cyclo ./Drivers/BSP/storage.d ./Drivers/BSP/storage.o ./Drivers/BSP/storage.su

.PHONY: clean-Drivers-2f-BSP

