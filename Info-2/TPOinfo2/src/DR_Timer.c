/*
 * DR_Timer.c
 *
 *  Created on: 24/11/2014
 *      Author: Pablo
 */

#include "DR_Timer.h"
#include "DR_systik.h"
#include "init.h"
#include "DR_RTC.h"

extern uint32_t AcRTC;
extern uint8_t i;

extern Mde_t Mde[8];
extern uint32_t TimerRegado[8];
extern Rtc_t rtc;
extern uint8_t l;
extern uint32_t tomarhumedad;



void InicializarSysTick ( void )
{
	STRELOAD= (STCALIB/4)-1;
	STCURR=0;
	ENABLE=1;
	TICKINT=1;
	CLKSOURCE=1;
	return;
}

void TimerRiego(void)
{
	TimerRegado[i]=(Mde[i].TiempoDeRiego)/2.5*1000; // le cargo a la variable regan
	Mde[i].Regado[i]=1;
	return;
}


void SysTick_Handler (void)
{
	//entro cada 2.5ms
	if(AcRTC)
	{
		AcRTC--;
	}else{
		AcRTC=10000;
		rtc.hora= RTC_GetHour();
		rtc.dia= RTC_GetDayOfWeek();
		rtc.minutos=RTC_GetMin();
		if(rtc.minutos==59)
		{
			for(l=1;l<9;l++)
			{
				Mde[l].Regado[rtc.hora]=0;
			}
		}
	}
	for(l=1;l<9;l++)
	{
		if(TimerRegado[l])
			{
				TimerRegado[l]--;
				if(TimerRegado[l]==0)
				{
					ElectroValvula(l,OFF);
				}
			}
	}
	if(tomarhumedad)
		{
			tomarhumedad--;
		}else{
			tomarhumedad=10000;
			for(l=1;l<9;l++)
				{
					// uso el adc y tomo la humedad.
				}

	return;
	// TAMBIEN PONER UN TIMER PARA LOS ARCHIVOS DE LA SSD.
	// poner un timer para tomar la humedad.
	}

}
