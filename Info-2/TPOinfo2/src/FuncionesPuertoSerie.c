#ifndef FUN_SERIES
#define FUN_SERIES

#include "DR_UART.h"
#include "DR_TIPOS.h"
#include "PR_Serial.h"
#include "init.h"
#endif

extern uint8_t dato;
extern uint8_t estadoPS;
extern uint8_t estadoPasaInfo;
extern uint8_t contador;
extern uint8_t contador2;
extern uint8_t j;
extern char auxPS[41];
extern uint8_t init;
extern Mde_t Mde[8];



void maquinapuertoserie (void)
{
	if(!Serial_PopRx (&dato))
		    	{

					switch (estadoPS){

						case CC:
							if(dato=='C')
							{
								contador2++;
							}else{
								contador2=0;
							}
							if(contador2==2)
							{
								contador2=0;
								estadoPS=TOMODATOS;
								j=0;
							}
							break;
						case TOMODATOS:
							if(j!=50)
							{
								auxPS[j]=dato;
								j++;
							}else{
								estadoPS=CARGADATOS;
							}
							break;
						case CARGADATOS:
							if(auxPS[48]=='C'&& auxPS[49]=='C')
							{
							Serial_PushTx(48);
							Mde[auxPS[1]-48].Sector=auxPS[1]-48;
							Mde[auxPS[1]-48].Habilitado=(auxPS[0]-48);
							Mde[auxPS[1]-48].HumedadCriticaMAX= ((auxPS[2]-48)*10+(auxPS[3]-48));
							Mde[auxPS[1]-48].HumedadCriticaMIN= ((auxPS[4]-48)*10+(auxPS[5]-48));
							Mde[auxPS[1]-48].TiempoDeRiego= ((auxPS[6]-48)*10+(auxPS[7]-48));
							for	(j=0;j<24;j++)
								{
								Mde[auxPS[1]-48].HRiego[j]=(auxPS[8+j]-48);
								}
							for	(j=0;j<24;j++)
								{
									Mde[auxPS[1]-48].DRiego[j]=(auxPS[32+j]-48);
								}
							init=1;
							}else {
								Serial_PushTx(49);
							}
							estadoPS=CC;
							break;
					}
		    	}
}

void pasarinfo (void)
{
	if(!Serial_PopRx (&dato))
		    	{

					switch (estadoPasaInfo){


					case PP:
						if(dato=='P')
						{
							contador2++;
						}else{
							contador2=0;
						}
						if(contador2==2)
						{
							contador2=0;
							estadoPS=PASOINFO;
							j=0;
						}
						break;
					case PASOINFO:
						break;
					}

		    	}

}
