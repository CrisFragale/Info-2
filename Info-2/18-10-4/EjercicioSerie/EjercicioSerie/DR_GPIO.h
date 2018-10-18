/**
 	\file FW_GPIO.h
 	\brief Header de GPIO para LPC17xx
 	\details
 	\author Pablo Irrera Condines
 	\date 2015.04.30
*/

#ifndef FW_GPIO_H_
#define FW_GPIO_H_

#include "RegsLPC17xx.h"

#define PORT0	0
#define PORT1	1
#define PORT2	2
#define PORT3	3
#define PORT4	4

#define GPIO_INPUT	0
#define GPIO_OUTPUT	1

#define	PINSEL_GPIO			0
#define	PINSEL_FUNC1		1
#define	PINSEL_FUNC2		2
#define	PINSEL_FUNC3		3

#define	PINMODE_PULLUP 		0
#define	PINMODE_REPEAT 		1
#define	PINMODE_NONE 		2
#define	PINMODE_PULLDOWN 	3

void SetPINSEL(uint8_t port, uint8_t pin, uint8_t sel);
void SetPINMODE(uint8_t port, uint8_t pin, uint8_t mode);
void SetDIR(uint8_t port, uint8_t pin, uint8_t dir);
void SetPIN(uint8_t port, uint8_t pin, uint8_t value);
uint8_t GetPIN(uint8_t port, uint8_t pin);

#endif /* FW_GPIO_H_ */
