/**
 	\file FW_serie.c
 	\brief Drivers de comunicacion serie
 	\details
 	\author Pablo Irrera Condines
 	\date 2013.05.08
*/

#include "FW_UART.h"
#include "FW_GPIO.h"
#include "PR_Serial.h"

void UART_Init(uint32_t baudRate)
{
	uint32_t aux;

	//1.- Registro PCONP - bit 3 en 1 prende la UART:
	PCONP |= 0x01<<3;
	//2.- Registro PCLKSEL0 - bits 6 y 7 en 0 seleccionan que el clk de la UART0 sea 25MHz:
	PCLKSEL0 &= ~(0x03<<6);
	//3.- Registro U0LCR - transmision de 8 bits, 1 bit de stop, sin paridad, sin break cond, DLAB = 1:
	U0LCR = 0x00000083;
	//4.- Registros U0DLL y U0DLM - calculo el divisor para el baud rate:
	aux = (100000000/4)/16;
	if(aux % baudRate >= baudRate/2)	//si el resto es mayor a la mitad del divisor
		aux = aux / baudRate + 1;		//redondeo para arriba
	else
		aux = aux / baudRate;
	U0DLM = (aux>>8)&0xFF;
	U0DLL = (aux>>0)&0xFF;
	//5.- Registros PINSEL - habilitan las funciones especiales de los pines:
	SetPINSEL(0,2,PINSEL_FUNC1);
	SetPINSEL(0,3,PINSEL_FUNC1);
	//6.- Registro U0LCR, pongo DLAB en 0:
	U0LCR = 0x03;
	//7. Habilito las interrupciones (En la UART -IER- y en el NVIC -ISER)
	U0IER = 0x03;
	ISER0 |= (1<<5);
}

uint8_t UART_ReceiveByte(void)
{
	return U0RBR;
}

void UART_SendByte(uint8_t byte)
{
	U0THR = byte;
}

void UART0_IRQHandler(void)
{
	uint8_t iir;
	do
	{
		//IIR es reset por HW, una vez que lo lei se resetea.
		iir = U0IIR;
		if ( iir & 0x02 ) //THRE
		{
			Serial_TxIntHandler();
		}
		if ( iir & 0x04 ) //Data ready
		{
			Serial_RxIntHandler();
		}
	}
	while(!(iir & 0x01)); /* me fijo si cuando entre a la ISR habia otra
						     	int. pendiente de atencion: b0=1 (ocurre unicamente si dentro del mismo
								espacio temporal lleguan dos interrupciones a la vez) */
}
