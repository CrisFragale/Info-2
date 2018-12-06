#ifndef MDE_T
#define MDE_T

#include "DR_UART.h"
#include "DR_TIPOS.h"
#include "PR_Serial.h"
#include "init.h"
#include "DR_Timer.h"
#endif

extern uint8_t dato;
extern uint8_t estado;
extern uint8_t j;
extern uint8_t i;
extern Mde_t Mde[8];
extern Rtc_t rtc;






void MDE(Mde_t MdE)
{

	if(!Serial_PopRx (&dato))
	 {
		switch (estado){

			case DECISION:

				if(MdE.Humedad>=MdE.HumedadCriticaMAX)
				{
					estado=DECISION;
				}else {
					if(MdE.Humedad<=MdE.HumedadCriticaMIN)
							{

						estado=RIEGO;
							}else {
								if(MdE.DRiego[rtc.dia]==1 && MdE.HRiego[rtc.hora]==1 && MdE.Regado[rtc.hora]==0 ) //comaparo la hora.
								{
									estado=RIEGO;

								}else
								{
									estado=DECISION;
								}
							}
				}
				break;

			case RIEGO:

					MdE.Regado[rtc.hora]=1;
					TimerRiego();
					ElectroValvula(MdE.Sector,ON);
					estado=DECISION;
				break;
		}
	 }
}
