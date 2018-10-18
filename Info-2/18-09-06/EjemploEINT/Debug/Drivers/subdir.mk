################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/DR_EINT.c \
../Drivers/DR_PLL.c \
../Drivers/DR_gpio.c \
../Drivers/DR_inicializacion.c \
../Drivers/DR_pinsel.c 

OBJS += \
./Drivers/DR_EINT.o \
./Drivers/DR_PLL.o \
./Drivers/DR_gpio.o \
./Drivers/DR_inicializacion.o \
./Drivers/DR_pinsel.o 

C_DEPS += \
./Drivers/DR_EINT.d \
./Drivers/DR_PLL.d \
./Drivers/DR_gpio.d \
./Drivers/DR_inicializacion.d \
./Drivers/DR_pinsel.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/%.o: ../Drivers/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"C:\Users\Marian\Documents\LPCXpresso_8.2.2_650\workspace\EjemploEINT\Drivers" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


