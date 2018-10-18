/*
===============================================================================
 Name        : TimerDriver.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>

#include "DR_PLL.h"
#include "DR_gpio.h"
#include "DR_Timer.h"

void TimerInterrupt(uint8_t match);

int main(void)
{
	InicializarPLL();

	SetDIR(0, 22, SALIDA);
	SetPIN(0, 22, 0);

	TIMER_Init(0);
	TIMER_SetRunningFrequency(0, 100000);
	TIMER_SetMatchCallback(0, TimerInterrupt);
	TIMER_SetMatch(0, 0, 100, TIMER_MATCH_INTERRUPT | TIMER_MATCH_RESET);
	TIMER_SetMatch(0, 1, 50, TIMER_MATCH_INTERRUPT);
	TIMER_Start(0);

	while(1)
	{

	}
}

void TimerInterrupt(uint8_t match)
{
	if(match & 0x01)		//match 0
	{
		SetPIN(0, 22, 1);
	}
	else if(match & 0x02)	//match 1
	{
		SetPIN(0, 22, 0);
	}
}
