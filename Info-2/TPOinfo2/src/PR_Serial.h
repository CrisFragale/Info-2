/*
 * PR_Serial.h
 *
 *  Created on: 09/07/2013
 *      Author: Pablo
 */

#ifndef PR_SERIE_H_
#define PR_SERIE_H_

#include "DR_UART.h"

#define TXBUFFER_SIZE	128
#define RXBUFFER_SIZE	128

uint8_t Serial_PushTx(uint8_t dato);
uint8_t Serial_PopRx(uint8_t *dato);
void Serial_RxIntHandler(void);
void Serial_TxIntHandler(void);
void pasarinfo (void);
void maquinapuertoserie (void);



#endif /* PR_SERIE_H_ */
