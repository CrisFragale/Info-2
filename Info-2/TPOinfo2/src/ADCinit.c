/*
 * ADCinit.c

 *
 *  Created on: 5 de dic. de 2018
 *      Author: cristian
 */
#include "ADC.h"

void InitADC(void)
{
	PCONP |= 1<<12;
	//2.- Configuro los pines del ADC0
	//ADC0.5 (pote) : P1[31]->PINSEL3: 30:31
	SetPINSEL(1,31,PINSEL_FUNC3);
	//3.- Activo interrupcion del canal 5:
	AD0INTEN = 0x20;
	//4.- Selecciono que voy a tomar muestras del canal AD0.5:
    AD0CR |= 0x20;
	//5.- Configuro la velocidad de muestreo en 10kHz:
	AD0CR |= (0xFF<<8); // Frecuencia del ADC mínima (1.5 KHz)
	//6.- Selecciono que el ADC muestree solo, con BURST = 1 y START = 000:
	AD0CR &= ~(0x0F<<24);
	AD0CR |= 1<<16;
	//7.- Activo interrupcion en el NVIC:
	ISER0 |= (1<<22);
	//8.- Activo el ADC (PDN = 1):
	AD0CR |= 1<<21;
}
