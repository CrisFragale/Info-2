/*
 * DR_Timer.h
 *
 *  Created on: 24/11/2014
 *      Author: Pablo
 */

#ifndef DR_TIMER_H_
#define DR_TIMER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "DR_tipos.h"

//!< ///////////////////   TIMERS   /////////////////////////////
//!< 0x40004000UL : Direccion de inicio de los registros del Timer0
#define		TIMER0		( (__RW uint32_t *) 0x40004000UL )
//!< 0x40008000UL : Direccion de inicio de los registros del Timer1
#define		TIMER1		( (__RW uint32_t *) 0x40008000UL )
//!< 0x40090000UL : Direccion de inicio de los registros del Timer2
#define		TIMER2		( (__RW uint32_t *) 0x40090000UL )
//!< 0x40094000UL : Direccion de inicio de los registros del Timer3
#define		TIMER3		( (__RW uint32_t *) 0x40094000UL )

//Definicion de registros de timers:
#define		TnIR(dir)	(dir)[0]
#define		TnTCR(dir)	(dir)[1]
#define		TnTC(dir)	(dir)[2]
#define		TnPR(dir)	(dir)[3]
#define		TnPC(dir)	(dir)[4]
#define		TnMCR(dir)	(dir)[5]
#define		TnMR0(dir)	(dir)[6]
#define		TnMR1(dir)	(dir)[7]
#define		TnMR2(dir)	(dir)[8]
#define		TnMR3(dir)	(dir)[9]
#define		TnCCR(dir)	(dir)[10]
#define		TnCR0(dir)	(dir)[11]
#define		TnCR1(dir)	(dir)[12]
#define		TnEMR(dir)	(dir)[15]
#define		TnCTCR(dir)	(dir)[28]

#define		T0IR		TIMER0[0]
#define		T0TCR		TIMER0[1]
#define		T0TC		TIMER0[2]
#define		T0PR		TIMER0[3]
#define		T0PC		TIMER0[4]
#define		T0MCR		TIMER0[5]
#define		T0MR0		TIMER0[6]
#define		T0MR1		TIMER0[7]
#define		T0MR2		TIMER0[8]
#define		T0MR3		TIMER0[9]
#define		T0CCR		TIMER0[10]
#define		T0CR0		TIMER0[11]
#define		T0CR1		TIMER0[12]
#define		T0EMR		TIMER0[15]
#define		T0CTCR		TIMER0[28]

#define		T1IR		TIMER1[0]
#define		T1TCR		TIMER1[1]
#define		T1TC		TIMER1[2]
#define		T1PR		TIMER1[3]
#define		T1PC		TIMER1[4]
#define		T1MCR		TIMER1[5]
#define		T1MR0		TIMER1[6]
#define		T1MR1		TIMER1[7]
#define		T1MR2		TIMER1[8]
#define		T1MR3		TIMER1[9]
#define		T1CCR		TIMER1[10]
#define		T1CR0		TIMER1[11]
#define		T1CR1		TIMER1[12]
#define		T1EMR		TIMER1[15]
#define		T1CTCR		TIMER1[28]

#define		T2IR		TIMER2[0]
#define		T2TCR		TIMER2[1]
#define		T2TC		TIMER2[2]
#define		T2PR		TIMER2[3]
#define		T2PC		TIMER2[4]
#define		T2MCR		TIMER2[5]
#define		T2MR0		TIMER2[6]
#define		T2MR1		TIMER2[7]
#define		T2MR2		TIMER2[8]
#define		T2MR3		TIMER2[9]
#define		T2CCR		TIMER2[10]
#define		T2CR0		TIMER2[11]
#define		T2CR1		TIMER2[12]
#define		T2EMR		TIMER2[15]
#define		T2CTCR		TIMER2[28]

#define		T3IR		TIMER3[0]
#define		T3TCR		TIMER3[1]
#define		T3TC		TIMER3[2]
#define		T3PR		TIMER3[3]
#define		T3PC		TIMER3[4]
#define		T3MCR		TIMER3[5]
#define		T3MR0		TIMER3[6]
#define		T3MR1		TIMER3[7]
#define		T3MR2		TIMER3[8]
#define		T3MR3		TIMER3[9]
#define		T3CCR		TIMER3[10]
#define		T3CR0		TIMER3[11]
#define		T3CR1		TIMER3[12]
#define		T3EMR		TIMER3[15]
#define		T3CTCR		TIMER3[28]

//Acciones de match
#define TIMER_MATCH_INTERRUPT		0x01
#define TIMER_MATCH_RESET			0x02
#define TIMER_MATCH_STOP			0x04

//Flancos de captura
#define TIMER_CAPTURE_NONE			0x00
#define TIMER_CAPTURE_RISING		0x01
#define TIMER_CAPTURE_FALLING		0x02
#define TIMER_CAPTURE_BOTH			0x04

//Configuracion de pines de timers
#define TIMER0_CAPTURE_PORT			1
#define TIMER0_CAPTURE0_PIN			26
#define TIMER0_CAPTURE1_PIN			27
#define TIMER0_CAPTURE_PINFUNC		3

#define TIMER1_CAPTURE_PORT			0
#define TIMER1_CAPTURE0_PIN			28
#define TIMER1_CAPTURE1_PIN			29
#define TIMER1_CAPTURE_PINFUNC		2

#define TIMER2_CAPTURE_PORT			0
#define TIMER2_CAPTURE0_PIN			4
#define TIMER2_CAPTURE1_PIN			5
#define TIMER2_CAPTURE_PINFUNC		3

#define TIMER3_CAPTURE_PORT			0
#define TIMER3_CAPTURE0_PIN			23
#define TIMER3_CAPTURE1_PIN			24
#define TIMER3_CAPTURE_PINFUNC		3

typedef void (*TimerMatchCallback)(uint8_t);

//Prototipos de funciones
void TIMER_Init(uint8_t timerNumber);
void TIMER_DeInit(uint8_t timerNumber);
void TIMER_SetRunningFrequency(uint8_t timerNumber, uint32_t freq);
void TIMER_SetMatch(uint8_t timerNumber, uint32_t matchNumber, uint32_t matchValue, uint8_t matchAction);
void TIMER_SetMatchCallback(uint8_t timerNumber, TimerMatchCallback callback);
void TIMER_Start(uint8_t timerNumber);
void TIMER_Stop(uint8_t timerNumber);
void TIMER_Reset(uint8_t timerNumber);
uint32_t TIMER_GetCounterValue(uint8_t timerNumber);
void TIMER_ConfigureCaptureChannel(uint8_t timerNumber, uint8_t channel, uint8_t edges);
uint32_t TIMER_GetCaptureState(uint8_t timerNumber, uint8_t channel);
uint32_t TIMER_GetCaptureCount(uint8_t timerNumber, uint8_t channel);
void TIMER_ResetCaptureCount(uint8_t timerNumber, uint8_t channel);
uint32_t TIMER_GetLastCaptureValue(uint8_t timerNumber, uint8_t channel);

#ifdef __cplusplus
}
#endif

#endif /* DR_TIMER_H_ */
