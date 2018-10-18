/*
===============================================================================
 Name        : EjemploEINT.c
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

// TODO: insert other include files here
#include "DR_gpio.h"
#include "DR_EINT.h"
#include "DR_inicializacion.h"

void ledStick( uint8_t estado );

// TODO: insert other definitions and declarations here

uint8_t led = OFF;

int main(void) {
	Inicializacion();

    while(1) {
    	if( flag_IntExt )
    	{
			if( led )
			{
				ledStick( OFF );
				led = OFF;
			}
			else
			{
				ledStick( ON );
				led = ON;
			}
			flag_IntExt = 0;
    	}
    }
    return 0 ;
}


void ledStick( uint8_t estado )
{
	SetPIN(LED_STICK, estado );
}
