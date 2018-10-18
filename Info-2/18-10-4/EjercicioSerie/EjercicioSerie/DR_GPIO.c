/**
 	\file FW_GPIO.c
 	\brief Drivers de GPIO para LPC17xx
 	\details
 	\author Pablo Irrera Condines
 	\date 2015.04.30
*/

#include "DR_GPIO.h"

/********************************************************************************
	\fn  void SetPINSEL(uint8_t port, uint8_t pin, uint8_t sel)
	\brief: Configuracion de funciones de los pines
	\details: Configura el registro PINSEL correspondiente para configurar el pin con la funcion requerida
	\author: Pablo Irrera Condines
 	\param 	[in] port Puerto a configurar
 	\param 	[in] pin Pin a configurar
 	\param 	[in] sel Funcion del pin. Puede ser:
 			PINSEL_GPIO
			PINSEL_FUNC1
			PINSEL_FUNC2
			PINSEL_FUNC3
	\return void
*/
void SetPINSEL(uint8_t port, uint8_t pin, uint8_t sel)
{
	port = port*2+pin/16;
	pin = (pin%16)*2;
	PINSEL[port] &= ~(0x03 << pin);
	PINSEL[port] |= sel << pin;
}

/********************************************************************************
	\fn  void SetPINMODE(uint8_t port, uint8_t pin, uint8_t mode)
	\brief: Configuracion de pull-up/pull-down
	\details: Configura el registro PINMODE correspondiente para configurar el pin requerido
	\author: Pablo Irrera Condines
 	\param 	[in] port Puerto a configurar
 	\param 	[in] pin Pin a configurar
 	\param 	[in] mode Funcion del pin. Puede ser:
 			PINMODE_PULLUP
			PINMODE_REPEAT
			PINMODE_NONE
			PINMODE_PULLDOWN
	\return void
*/
void SetPINMODE(uint8_t port, uint8_t pin, uint8_t mode)
{
	port = port*2+pin/16;
	pin = (pin%16)*2;
	PINMODE[port] &= ~(0x03 << pin);
	PINMODE[port] |= mode << pin;
}

/********************************************************************************
	\fn  void SetDIR(uint8_t port, uint8_t pin, uint8_t dir)
	\brief: Configuracion de GPIO como entrada o salida
	\details: Configura el registro FIODIR correspondiente para configurar el pin requerido
	\author: Pablo Irrera Condines
 	\param 	[in] port Puerto a configurar
 	\param 	[in] pin Pin a configurar
 	\param 	[in] dir Direccion del pin GPIO. Puede ser:
 			GPIO_INPUT
			GPIO_OUTPUT
	\return void
*/
void SetDIR(uint8_t port, uint8_t pin, uint8_t dir)
{
	dir? (GPIOs[port*8+0] |= 1<<pin) : (GPIOs[port*8+0] &= ~(1<<pin));
}

/********************************************************************************
	\fn  void SetPIN(uint8_t port, uint8_t pin, uint8_t value)
	\brief: Setear valor de pin GPIO
	\details: Escribe un valor en un pin de GPIO configurado como salida
	\author: Pablo Irrera Condines
 	\param 	[in] port Puerto a configurar
 	\param 	[in] pin Pin a configurar
 	\param 	[in] value Valor del pin GPIO. Valores posibles: 0 o 1
	\return void
*/
void SetPIN(uint8_t port, uint8_t pin, uint8_t value)
{
	value? (GPIOs[port*8+6] |= 1<<pin) : (GPIOs[port*8+7] |= 1<<pin);
}

/********************************************************************************
	\fn  uint8_t GetPIN(uint8_t port, uint8_t pin)
	\brief: Leer valor de pin GPIO
	\details: Lee el valor de un pin de GPIO presente en el registro FIOPIN correspondiente
	\author: Pablo Irrera Condines
 	\param 	[in] port Puerto a configurar
 	\param 	[in] pin Pin a configurar
	\return 0 o 1
*/
uint8_t GetPIN(uint8_t port, uint8_t pin)
{
	return (GPIOs[port*8+5] >> pin) & 0x01;
}
