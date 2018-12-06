/**
 	\file FW_GPIO.c
 	\brief Drivers de GPIO para LPC17xx
 	\details
 	\author Pablo Irrera Condines
 	\date 2015.04.30
*/

#include "DR_GPIO.h"

void SetPINSEL(uint8_t port, uint8_t pin, uint8_t sel)
{
	port = port*2+pin/16;
	pin = (pin%16)*2;
	PINSEL[port] &= ~(0x03 << pin);
	PINSEL[port] |= sel << pin;
}


void SetPINMODE(uint8_t port, uint8_t pin, uint8_t mode)
{
	port = port*2+pin/16;
	pin = (pin%16)*2;
	PINMODE[port] &= ~(0x03 << pin);
	PINMODE[port] |= mode << pin;
}


void SetDIR(uint8_t port, uint8_t pin, uint8_t dir)
{
	dir? (GPIOs[port*8+0] |= 1<<pin) : (GPIOs[port*8+0] &= ~(1<<pin));
}


void SetPIN(uint8_t port, uint8_t pin, uint8_t value)
{
	value? (GPIOs[port*8+6] |= 1<<pin) : (GPIOs[port*8+7] |= 1<<pin);
}



uint8_t GetPIN(uint8_t port, uint8_t pin)
{
	return (GPIOs[port*8+5] >> pin) & 0x01;
}
