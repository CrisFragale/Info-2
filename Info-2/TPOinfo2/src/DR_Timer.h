/*
 * DR_Timer.h
 *
 *  Created on: 24/11/2014
 *      Author: Pablo
 */

#ifndef DR_TIMER_H_
#define DR_TIMER_H_

#include "stdio.h"
#include"DR_TIPOS.h"


void Systick_init (void);

void SysTick_Handler (void);
void TimerRiego(void);


#endif /* DR_TIMER_H_ */
