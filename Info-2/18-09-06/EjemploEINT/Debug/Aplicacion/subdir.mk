################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Aplicacion/EjemploEINT.c \
../Aplicacion/cr_startup_lpc175x_6x.c \
../Aplicacion/crp.c 

OBJS += \
./Aplicacion/EjemploEINT.o \
./Aplicacion/cr_startup_lpc175x_6x.o \
./Aplicacion/crp.o 

C_DEPS += \
./Aplicacion/EjemploEINT.d \
./Aplicacion/cr_startup_lpc175x_6x.d \
./Aplicacion/crp.d 


# Each subdirectory must supply rules for building sources it contributes
Aplicacion/%.o: ../Aplicacion/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -I"C:\Users\Marian\Documents\LPCXpresso_8.2.2_650\workspace\EjemploEINT\Drivers" -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


