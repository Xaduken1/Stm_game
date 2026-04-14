################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Game/game.c \
../Game/menu.c \
../Game/render.c \
../Game/snake.c 

C_DEPS += \
./Game/game.d \
./Game/menu.d \
./Game/render.d \
./Game/snake.d 

OBJS += \
./Game/game.o \
./Game/menu.o \
./Game/render.o \
./Game/snake.o 


# Each subdirectory must supply rules for building sources it contributes
Game/%.o Game/%.su Game/%.cyclo: ../Game/%.c Game/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F411xE -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/danii/STM32CubeIDE/workspace_1.19.0/game/Game" -I"C:/Users/danii/STM32CubeIDE/workspace_1.19.0/game/Drivers/BSP" -I"C:/Users/danii/STM32CubeIDE/workspace_1.19.0/game/Drivers/Utils" -I../FATFS/Target -I../FATFS/App -I../Middlewares/Third_Party/FatFs/src -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Game

clean-Game:
	-$(RM) ./Game/game.cyclo ./Game/game.d ./Game/game.o ./Game/game.su ./Game/menu.cyclo ./Game/menu.d ./Game/menu.o ./Game/menu.su ./Game/render.cyclo ./Game/render.d ./Game/render.o ./Game/render.su ./Game/snake.cyclo ./Game/snake.d ./Game/snake.o ./Game/snake.su

.PHONY: clean-Game

