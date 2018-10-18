/*
 * DR_inicializacion.c
 *
 *  Created on: 5 de set. de 2018
 *      Author: Marian
 */
#include "DR_EINT.h"
#include "DR_PLL.h"
#include "DR_gpio.h"
#include "DR_inicializacion.h"

void Inicializacion(void)
{
	InicializarPLL ( );
	EXTINT_Inicializacion( EXTINT3 , EXT_FLANCO_ACT , EXT_FLANCO_F );
	SetPIN( LED_STICK, OFF );
}
