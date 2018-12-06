/*
 * FW_Serie.h
 *
 *  Created on: 09/07/2013
 *      Author: Pablo
 */

#ifndef FW_UART_H_
#define FW_UART_H_

#include "RegsLPC17xx.h"

void UART_Init(uint32_t baudRate);
uint8_t UART_ReceiveByte(void);
void UART_SendByte(uint8_t byte);

#endif /* FW_UART_H_ */
