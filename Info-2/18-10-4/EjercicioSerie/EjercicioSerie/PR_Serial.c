/**
 	\file PR_serie.c
 	\brief Primitiva de comunicación serie
 	\details buffers de RX y TX protegidos
 	\author Pablo Irrera Condines
 	\date 2013.05.08
*/

#include "PR_Serial.h"
#include <stdio.h>

// Buffer de Transmision
uint8_t g_txBuffer[TXBUFFER_SIZE];
// Buffer de Recepcion
uint8_t g_rxBuffer[RXBUFFER_SIZE];

//Indices de Transmision
uint8_t g_txIn,g_txOut;
//Indices de Recepcion
uint8_t g_rxIn,g_rxOut;
//Espacio utilizado en los buffers
uint8_t g_txBufferCount = 0, g_rxBufferCount = 0;

//Flag de transmision en proceso
static uint8_t g_txStart = 0;

static uint8_t PushRx(uint8_t data);
static uint8_t PopTx(uint8_t *data);

static uint8_t PushRx(uint8_t data)
{
	if(g_rxBufferCount == RXBUFFER_SIZE)
		return 1;

	g_rxBuffer[g_rxIn] = data;
	g_rxIn++;
	g_rxIn %= RXBUFFER_SIZE;
	g_rxBufferCount++;

	return 0;	//dato agregado al buffer
}

static uint8_t PopTx(uint8_t *data)
{
	if(g_txBufferCount == 0)
		return 1;

	*data = (uint8_t) g_txBuffer[g_txOut];
	g_txOut++;
	g_txOut %= TXBUFFER_SIZE;
	g_txBufferCount--;

	return 0;	//dato sacado del buffer
}


void Serial_RxIntHandler(void)
{
	uint8_t byte;
	byte = UART_ReceiveByte();
	PushRx(byte);
}

void Serial_TxIntHandler(void)
{
	uint8_t byte;
	if(!PopTx(&byte))
		UART_SendByte(byte);
	else
	{
		g_txStart = 0;
	}
}

uint8_t Serial_PopRx(uint8_t *data)
{
	if(g_rxBufferCount == 0)
		return 1;

	*data = (uint8_t) g_rxBuffer[g_rxOut];
	g_rxOut++;
	g_rxOut %= RXBUFFER_SIZE;
	g_rxBufferCount--;

	return 0;	//dato sacado del buffer
}

uint8_t Serial_PushTx(uint8_t data)
{
	if(g_txBufferCount == TXBUFFER_SIZE)
		return 1;

	g_txBuffer[g_txIn] = data;
	g_txIn++;
	g_txIn %= TXBUFFER_SIZE;
	g_txBufferCount++;

	if (g_txStart == 0)
	{
		g_txStart = 1;
		Serial_TxIntHandler();
	}
	return 0;	//dato agregado al buffer
}

uint8_t Serial_Send(const uint8_t *buffer, uint8_t count)
{
	uint8_t i;
	if((TXBUFFER_SIZE - g_txBufferCount) < count)
		return 1;

	for(i = 0; i < count; i++)
	{
		g_txBuffer[g_txIn] = buffer[i];
		g_txIn++;
		g_txIn %= TXBUFFER_SIZE;
	}
	g_txBufferCount += count;

	if (g_txStart == 0)
	{
		g_txStart = 1;
		Serial_TxIntHandler();
	}
	return 0;
}
