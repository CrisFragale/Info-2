/**
 	\file PR_serial.c
 	\brief Primitiva de comunicación serie
 	\details buffers de RX y TX protegidos
 	\author Pablo Irrera Condines
 	\date 2013.05.08
*/

#include "PR_Serial.h"


uint8_t g_txBuffer[TXBUFFER_SIZE];

uint8_t g_rxBuffer[RXBUFFER_SIZE];

uint8_t g_txIn,g_txOut;
uint8_t g_rxIn,g_rxOut;

uint8_t g_txBufferCount = 0, g_rxBufferCount = 0;

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

		return 0;

}

static uint8_t PopTx(uint8_t *data)
{
	if(g_txBufferCount == 0)
			return 1;

		*data = (uint8_t) g_txBuffer[g_txOut];
		g_txOut++;
		g_txOut %= TXBUFFER_SIZE;
		g_txBufferCount--;

		return 0;
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

		return 0;
}

uint8_t Serial_PushTx(uint8_t data)
{
	if(g_txBufferCount == TXBUFFER_SIZE)
			return 1;

		g_txBuffer[g_txIn] = data;
		g_txIn++;
		g_txIn %= TXBUFFER_SIZE; // SI LO SOBREPASA TE DEVUELVE 0. // yo evalua la diferencia entre este indice y el del otro que esta reciviendo.
		g_txBufferCount++;

		if (g_txStart == 0)
		{
			g_txStart = 1;
			Serial_TxIntHandler();
		}
		return 0;

}
