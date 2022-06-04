################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ADC_prog.c \
../Src/Delay_prog.c \
../Src/ECU.c \
../Src/GPIO_prog.c \
../Src/NVIC_prog.c \
../Src/RCC_prog.c \
../Src/STK_program.c \
../Src/SunCalc.c \
../Src/TIM2.c \
../Src/app.c \
../Src/motor.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/ADC_prog.o \
./Src/Delay_prog.o \
./Src/ECU.o \
./Src/GPIO_prog.o \
./Src/NVIC_prog.o \
./Src/RCC_prog.o \
./Src/STK_program.o \
./Src/SunCalc.o \
./Src/TIM2.o \
./Src/app.o \
./Src/motor.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/ADC_prog.d \
./Src/Delay_prog.d \
./Src/ECU.d \
./Src/GPIO_prog.d \
./Src/NVIC_prog.d \
./Src/RCC_prog.d \
./Src/STK_program.d \
./Src/SunCalc.d \
./Src/TIM2.d \
./Src/app.d \
./Src/motor.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F4 -DSTM32F401VETx -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/ADC_prog.d ./Src/ADC_prog.o ./Src/ADC_prog.su ./Src/Delay_prog.d ./Src/Delay_prog.o ./Src/Delay_prog.su ./Src/ECU.d ./Src/ECU.o ./Src/ECU.su ./Src/GPIO_prog.d ./Src/GPIO_prog.o ./Src/GPIO_prog.su ./Src/NVIC_prog.d ./Src/NVIC_prog.o ./Src/NVIC_prog.su ./Src/RCC_prog.d ./Src/RCC_prog.o ./Src/RCC_prog.su ./Src/STK_program.d ./Src/STK_program.o ./Src/STK_program.su ./Src/SunCalc.d ./Src/SunCalc.o ./Src/SunCalc.su ./Src/TIM2.d ./Src/TIM2.o ./Src/TIM2.su ./Src/app.d ./Src/app.o ./Src/app.su ./Src/motor.d ./Src/motor.o ./Src/motor.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

