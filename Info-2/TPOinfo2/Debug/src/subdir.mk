################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/ADCinit.c \
../src/DR_GPIO.c \
../src/DR_PLL.c \
../src/DR_RTC.c \
../src/DR_Timer.c \
../src/DR_UART.c \
../src/FuncionesPuertoSerie.c \
../src/Mde1.c \
../src/PR_Serial.c \
../src/TPOinfo2.c \
../src/cr_startup_lpc175x_6x.c \
../src/crp.c \
../src/funciones.c 

OBJS += \
./src/ADCinit.o \
./src/DR_GPIO.o \
./src/DR_PLL.o \
./src/DR_RTC.o \
./src/DR_Timer.o \
./src/DR_UART.o \
./src/FuncionesPuertoSerie.o \
./src/Mde1.o \
./src/PR_Serial.o \
./src/TPOinfo2.o \
./src/cr_startup_lpc175x_6x.o \
./src/crp.o \
./src/funciones.o 

C_DEPS += \
./src/ADCinit.d \
./src/DR_GPIO.d \
./src/DR_PLL.d \
./src/DR_RTC.d \
./src/DR_Timer.d \
./src/DR_UART.d \
./src/FuncionesPuertoSerie.d \
./src/Mde1.d \
./src/PR_Serial.d \
./src/TPOinfo2.d \
./src/cr_startup_lpc175x_6x.d \
./src/crp.d \
./src/funciones.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__LPC17XX__ -D__REDLIB__ -O0 -fno-common -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


