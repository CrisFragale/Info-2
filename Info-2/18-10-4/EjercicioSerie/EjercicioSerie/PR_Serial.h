/*
 * PR_Serie.h
 *
 *  Created on: 09/07/2013
 *      Author: Pablo
 */

#ifndef PR_SERIE_H_
#define PR_SERIE_H_

#include "FW_UART.h"

#define TXBUFFER_SIZE	128
#define RXBUFFER_SIZE	128

uint8_t Serial_PushTx(uint8_t dato);
uint8_t Serial_PopRx(uint8_t *dato);
uint8_t Serial_Send(const uint8_t *buffer, uint8_t count);
void Serial_RxIntHandler(void);
void Serial_TxIntHandler(void);

#endif /* PR_SERIE_H_ */
