/*
 * DR_EINT.c
 *
 *  Created on: 5 de set. de 2018
 *      Author: Marian
 */


 /***********************************************************************************************************************************
  *** INCLUDES
  **********************************************************************************************************************************/
#include "DR_EINT.h"


uint8_t flag_IntExt = 0;

void EXTINT_Inicializacion( uint8_t extint , uint8_t nivel , uint8_t flanco )
{
	 switch ( extint )
	 {
		 case EXTINT0 :
			  SetPINSEL( EINT0_PIN , PINSEL_FUNC1 );
			  break;
		 case EXTINT1 :
			  SetPINSEL( EINT1_PIN , PINSEL_FUNC1 );
			  break;
		 case EXTINT2 :
			  SetPINSEL( EINT2_PIN , PINSEL_FUNC1 );
			  break;
		 case EXTINT3 :
			  SetPINSEL( EINT3_PIN , PINSEL_FUNC1 );
			  break;
	 }

	 if ( nivel ) //Si es nivel 1
		 EXTMODE |= 1 << extint;
	 else //Si es flanco
		 EXTMODE &= ~( 1 << extint );

	 if ( flanco ) //Flanco ascendente o nivel 1
		 EXTPOLAR |= 1 << extint;
	 else //Flanco descendente o ninel 0
		 EXTPOLAR &= ~( 1 << extint );

	 ISER0 |= 1 << (18 + extint );
}

void EINT3_IRQHandler(void)
{
	EXTINT |= (1 << 3);

	flag_IntExt = 1;

}
