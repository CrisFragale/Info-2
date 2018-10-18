/*
 * DR_Timer.c
 *
 *  Created on: 24/11/2014
 *      Author: Pablo
 */

#include "stdio.h"
#include "DR_Timer.h"
#include "DR_pinsel.h"
#include "DR_PLL.h"
#include "DR_NVIC.h"

static TimerMatchCallback g_matchCallback[4] = {NULL, NULL, NULL, NULL};
uint32_t g_runningFreq[4];
uint32_t g_capturePulseCounter[4][2] = {{0}};
uint8_t g_captureState[4][2] = {{0}};

void TIMER_Init(uint8_t timerNumber)
{
	volatile uint32_t *pTimer = 0;
	uint8_t i;

	if(timerNumber > 3)
		return;
	if(timerNumber == 0)
	{
		PCONP |= 1 << PCTIM0;
		PCLKSEL0 &= ~(0x03 << PCLK_TIMER0);

		pTimer = TIMER0;
		ICER0 |= 1 << 1;
	}
	else if(timerNumber == 1)
	{
		PCONP |= 1 << PCTIM1;
		PCLKSEL0 &= ~(0x03 << PCLK_TIMER1);

		pTimer = TIMER1;
		ICER0 |= 1 << 2;
	}
	else if(timerNumber == 2)
	{
		PCONP |= 1 << PCTIM2;
		PCLKSEL1 &= ~(0x03 << PCLK_TIMER2);

		pTimer = TIMER2;
		ICER0 |= 1 << 3;
	}
	else if(timerNumber == 3)
	{
		PCONP |= 1 << PCTIM2;
		PCLKSEL1 &= ~(0x03 << PCLK_TIMER3);

		pTimer = TIMER3;
		ICER0 |= 1 << 4;
	}

	for(i=0; i<4; i++)
	{
		g_runningFreq[i] = 100000000 >> 2;	//prescaler = 0
		g_capturePulseCounter[i][0] = 0;
		g_capturePulseCounter[i][1] = 0;
		g_captureState[i][0] = 0;
		g_captureState[i][1] = 0;
	}

	TnMR0(pTimer) = 0;
	TnMR1(pTimer) = 0;
	TnMR2(pTimer) = 0;
	TnMR3(pTimer) = 0;
	TnIR(pTimer) = 0;
	TnTC(pTimer) = 0;
	TnMCR(pTimer) = 0;
	TnPR(pTimer) = 0;
	TnCTCR(pTimer) = 0;
	TnTCR(pTimer) = 0;
	TnCCR(pTimer) = 0;
	TnCR0(pTimer) = 0;
	TnCR1(pTimer) = 0;
	TnEMR(pTimer) = 0;
}

void TIMER_SetRunningFrequency(uint8_t timerNumber, uint32_t freq)
{
	g_runningFreq[timerNumber] = freq;
	if((100000000 >> 2) % freq > freq / 2)
		freq = (100000000) / freq + 1;
	else
		freq = (100000000) / freq;

	if(timerNumber == 0)
		T0PR = freq;
	else if(timerNumber == 1)
		T1PR = freq;
	else if(timerNumber == 2)
		T2PR = freq;
	else if(timerNumber == 3)
		T3PR = freq;
}

void TIMER_DeInit(uint8_t timerNumber)
{
	volatile uint32_t *pTimer = 0;

	if(timerNumber > 3)
		return;
	if(timerNumber == 0)
	{
		PCONP &= ~(1 << PCTIM0);
		pTimer = TIMER0;
		ICER0 |= 1 << 1;
	}
	else if(timerNumber == 1)
	{
		PCONP &= ~(1 << PCTIM1);
		pTimer = TIMER1;
		ICER0 |= 1 << 2;
	}
	else if(timerNumber == 2)
	{
		PCONP &= ~(1 << PCTIM2);
		pTimer = TIMER2;
		ICER0 |= 1 << 3;
	}
	else if(timerNumber == 3)
	{
		PCONP &= ~(1 << PCTIM3);
		pTimer = TIMER3;
		ICER0 |= 1 << 4;
	}

	TnMR0(pTimer) = 0;
	TnMR1(pTimer) = 0;
	TnMR2(pTimer) = 0;
	TnMR3(pTimer) = 0;
	TnIR(pTimer) = 0;
	TnTC(pTimer) = 0;
	TnMCR(pTimer) = 0;
	TnPR(pTimer) = 0;
	TnCTCR(pTimer) = 0;
	TnTCR(pTimer) = 0;
	TnCCR(pTimer) = 0;
	TnCR0(pTimer) = 0;
	TnCR1(pTimer) = 0;
	TnEMR(pTimer) = 0;
}

void TIMER_SetMatch(uint8_t timerNumber, uint32_t matchNumber, uint32_t matchValue, uint8_t matchAction)
{
	volatile uint32_t *pTimer;

	if(timerNumber > 3 || matchNumber > 4)
		return;

	if(timerNumber == 0)
	{
		pTimer = TIMER0;
		ISER0 |= 1 << 1;
	}
	else if(timerNumber == 1)
	{
		pTimer = TIMER1;
		ISER0 |= 1 << 2;
	}
	else if(timerNumber == 1)
	{
		pTimer = TIMER2;
		ISER0 |= 1 << 3;
	}
	else if(timerNumber == 1)
	{
		pTimer = TIMER3;
		ISER0 |= 1 << 4;
	}

	TnMCR(pTimer) &= ~(0x07 << (matchNumber * 3));
	TnMCR(pTimer) |= matchAction << (matchNumber * 3);

	if(matchNumber == 0)
		TnMR0(pTimer) = matchValue;
	else if(matchNumber == 1)
		TnMR1(pTimer) = matchValue;
	else if(matchNumber == 2)
		TnMR2(pTimer) = matchValue;
	else if(matchNumber == 3)
		TnMR3(pTimer) = matchValue;
}

void TIMER_SetMatchCallback(uint8_t timerNumber, TimerMatchCallback callback)
{
	if(timerNumber > 4)
		return;
	g_matchCallback[timerNumber] = callback;
}

void TIMER_Start(uint8_t timerNumber)
{
	if(timerNumber > 3)
		return;

	if(timerNumber == 0)
		T0TCR |= 0x01;
	else if(timerNumber == 1)
		T1TCR |= 0x01;
	else if(timerNumber == 2)
		T2TCR |= 0x01;
	else if(timerNumber == 3)
		T3TCR |= 0x01;
}

void TIMER_Stop(uint8_t timerNumber)
{
	if(timerNumber > 3)
		return;

	if(timerNumber == 0)
		T0TCR &= ~(0x01);
	else if(timerNumber == 1)
		T1TCR &= ~(0x01);
	else if(timerNumber == 2)
		T2TCR &= ~(0x01);
	else if(timerNumber == 3)
		T3TCR &= ~(0x01);
}

void TIMER_Reset(uint8_t timerNumber)
{
	if(timerNumber > 3)
		return;

	if(timerNumber == 0)
	{
		T0TCR |= 0x02;
		T0TCR &= ~(0x02);
	}
	else if(timerNumber == 1)
	{
		T1TCR |= 0x02;
		T1TCR &= ~(0x02);
	}
	else if(timerNumber == 2)
	{
		T2TCR |= 0x02;
		T2TCR &= ~(0x02);
	}
	else if(timerNumber == 3)
	{
		T3TCR |= 0x02;
		T3TCR &= ~(0x02);
	}
}

void TIMER_ConfigureCaptureChannel(uint8_t timerNumber, uint8_t channel, uint8_t edges)
{
	if(timerNumber > 3 || channel > 2)
		return;

	if(timerNumber == 0)
	{
		if(channel == 0)
			SetPINSEL(TIMER0_CAPTURE_PORT, TIMER0_CAPTURE0_PIN, TIMER0_CAPTURE_PINFUNC);
		else
			SetPINSEL(TIMER0_CAPTURE_PORT, TIMER0_CAPTURE1_PIN, TIMER0_CAPTURE_PINFUNC);
		ISER0 |= 1 << 1;
		T0CCR &= (~0x07) << (channel * 3);
		T0CCR = edges << (channel * 3) | 0x04 << (channel * 3);
	}
	else if(timerNumber == 1)
	{
		if(channel == 0)
			SetPINSEL(TIMER1_CAPTURE_PORT, TIMER1_CAPTURE0_PIN, TIMER1_CAPTURE_PINFUNC);
		else
			SetPINSEL(TIMER1_CAPTURE_PORT, TIMER1_CAPTURE1_PIN, TIMER1_CAPTURE_PINFUNC);
		ISER0 |= 1 << 2;
		T1CCR &= (~0x07) << (channel * 3);
		T1CCR = edges << (channel * 3) | 0x04 << (channel * 3);
	}
	else if(timerNumber == 2)
	{
		if(channel == 0)
			SetPINSEL(TIMER2_CAPTURE_PORT, TIMER2_CAPTURE0_PIN, TIMER2_CAPTURE_PINFUNC);
		else
			SetPINSEL(TIMER2_CAPTURE_PORT, TIMER2_CAPTURE1_PIN, TIMER2_CAPTURE_PINFUNC);
		ISER0 |= 1 << 3;
		T2CCR &= (~0x07) << (channel * 3);
		T2CCR = edges << (channel * 3) | 0x04 << (channel * 3);
	}
	else if(timerNumber == 3)
	{
		if(channel == 0)
			SetPINSEL(TIMER3_CAPTURE_PORT, TIMER3_CAPTURE0_PIN, TIMER3_CAPTURE_PINFUNC);
		else
			SetPINSEL(TIMER3_CAPTURE_PORT, TIMER3_CAPTURE1_PIN, TIMER3_CAPTURE_PINFUNC);
		ISER0 |= 1 << 4;
		T3CCR &= (~0x07) << (channel * 3);
		T3CCR = edges << (channel * 3) | 0x04 << (channel * 3);
	}
}

uint32_t TIMER_GetCounterValue(uint8_t timerNumber)
{
	if(timerNumber > 3)
		return 0;

	if(timerNumber == 0)
		return T0TC;
	else if(timerNumber == 1)
		return T1TC;
	else if(timerNumber == 2)
		return T2TC;
	else if(timerNumber == 3)
		return T3TC;

	return 0;	//por el warning
}

uint32_t TIMER_GetCaptureState(uint8_t timerNumber, uint8_t channel)
{
	uint8_t retVal;
	if(timerNumber > 3 || channel > 1)
		return 0;

	retVal = g_captureState[timerNumber][channel];
	g_captureState[timerNumber][channel] = 0;

	return retVal;
}

uint32_t TIMER_GetCaptureCount(uint8_t timerNumber, uint8_t channel)
{
	if(timerNumber > 3 || channel > 1)
		return 0;

	return g_capturePulseCounter[timerNumber][channel];
}

void TIMER_ResetCaptureCount(uint8_t timerNumber, uint8_t channel)
{
	if(timerNumber > 3 || channel > 1)
		return;

	g_capturePulseCounter[timerNumber][channel] = 0;
}

uint32_t TIMER_GetLastCaptureValue(uint8_t timerNumber, uint8_t channel)
{
	if(timerNumber > 3 || channel > 1)
		return 0;

	if(timerNumber == 0)
	{
		if(channel == 0)
			return T0CR0;
		else if(channel == 1)
			return T0CR1;
	}
	else if(timerNumber == 1)
	{
		if(channel == 0)
			return T1CR0;
		else if(channel == 1)
			return T1CR1;
	}
	else if(timerNumber == 2)
	{
		if(channel == 0)
			return T2CR0;
		else if(channel == 1)
			return T2CR1;
	}
	else if(timerNumber == 3)
	{
		if(channel == 0)
			return T3CR0;
		else if(channel == 1)
			return T3CR1;
	}

	return 0;
}

void TIMER0_IRQHandler(void)
{
	if(T0IR & 0x10)
	{
		g_capturePulseCounter[0][0]++;
		g_captureState[0][0] = 0;
		T0IR = 0x10;
	}
	if(T0IR & 0x20)
	{
		g_capturePulseCounter[0][1]++;
		g_captureState[0][1] = 0;
		T0IR = 0x20;
	}
	if(T0IR & 0x0F)
	{
		if(g_matchCallback[0])
			g_matchCallback[0](T0IR & 0x0F);
		T0IR = 0x0F;
	}
}

void TIMER1_IRQHandler(void)
{
	if(T1IR & 0x10)
	{
		g_capturePulseCounter[1][0]++;
		g_captureState[1][0] = 0;
		T1IR = 0x10;
	}
	if(T1IR & 0x20)
	{
		g_capturePulseCounter[1][1]++;
		g_captureState[1][1] = 0;
		T1IR = 0x20;
	}
	if(T1IR & 0x0F)
	{
		if(g_matchCallback[1])
			g_matchCallback[1](T1IR & 0x0F);
		T1IR = 0x0F;
	}
}

void TIMER2_IRQHandler(void)
{
	if(T2IR & 0x10)
	{
		g_capturePulseCounter[2][0]++;
		g_captureState[1][0] = 0;
		T2IR = 0x10;
	}
	if(T2IR & 0x20)
	{
		g_capturePulseCounter[2][1]++;
		g_captureState[2][1] = 0;
		T2IR = 0x20;
	}
	if(T2IR & 0x0F)
	{
		if(g_matchCallback[2])
			g_matchCallback[2](T2IR & 0x0F);
		T2IR = 0x0F;
	}
}

void TIMER3_IRQHandler(void)
{
	if(T3IR & 0x10)
	{
		g_capturePulseCounter[3][0]++;
		g_captureState[3][0] = 0;
		T3IR = 0x10;
	}
	if(T3IR & 0x20)
	{
		g_capturePulseCounter[3][1]++;
		g_captureState[3][1] = 0;
		T3IR = 0x20;
	}
	if(T3IR & 0x0F)
	{
		if(g_matchCallback[3])
			g_matchCallback[3](T3IR & 0x0F);
		T3IR = 0x0F;
	}
}
