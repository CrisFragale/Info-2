/**
 	\file DR_RTC.c
 	\brief Drivers del RTC
 	\details Manejo de interrupciones por incremento y alarma
 	\author Pablo Irrera Condines
 	\date 2018.09.27
*/

#include <stdio.h>
#include "DR_RTC.h"

extern uint32_t AcRTC;
extern uint8_t contador;
extern uint8_t flag;
extern uint8_t j;
extern uint8_t dato;

void RTC_Init(void)
{
	ILR = 0x00;
	CIIR = 0x00;
	AMR = 0xFF;
	CALIBRATION = 0x00;
	CCR = 0x01;
}

void RTCconfig(void)
{

	static uint8_t estadoRTC=PESOS;
	static char auxRTC[17];


	if(!Serial_PopRx (&dato))
	    	{
	    				switch (estadoRTC){

	    					case PESOS:
	    						if(dato=='$')
	    							{
	    								contador++;
	    							}else{
	    								contador=0;
	    							}
	    						if(contador==2)
	    						{
									contador=0;
									j=0;
									estadoRTC=DATOS;
	    						}
	    						break;
	    					case DATOS:
	    						if(j!=16)
	    						{
	    							auxRTC[j]=dato;
	    							j++;
	    						}else{
	    							estadoRTC=CORROBORO;
	    						}
	    						break;
	    					case CORROBORO:
	    						if(auxRTC[15]=='$'&& auxRTC[16]=='$')
	    						{
	    							Serial_PushTx(48);
	    							RTC_SetDayOfWeek(auxRTC[0]-48);
	    							RTC_SetDayOfMonth((auxRTC[1]-48)*10+(auxRTC[2]-48));
	    							RTC_SetMonth((auxRTC[3]-48)*10+(auxRTC[4]-48));
									RTC_SetYear((auxRTC[5]-48)*1000+(auxRTC[6]-48)*100+(auxRTC[7]-48)*10+(auxRTC[8]-48));
									RTC_SetSec((auxRTC[9]-48)*10+(auxRTC[10]-48));
	    							RTC_SetMin((auxRTC[11]-48)*10+(auxRTC[12]-48));
									RTC_SetHour((auxRTC[13]-48)*10+(auxRTC[14]-48));
									flag=1;

	    						}else{
	    							Serial_PushTx(49);
	    						}
	    						estadoRTC=PESOS;
	    						AcRTC=10000;
	    						break;
	    					}
	   					}
                }


