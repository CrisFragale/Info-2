#ifndef __USE_CMSIS
#include "RegsLPC17xx.h"
#include "init.h"
#include "DR_TIPOS.h"
#include "DR_GPIO.h"
#endif

extern uint32_t tomarhumedad;

void ElectroValvula(uint8_t sector, uint8_t modo)
{
	if(modo==1)
	{
		if(sector==1)SetPIN(VALVULA1,1);
		if(sector==2)SetPIN(VALVULA2,1);
		if(sector==3)SetPIN(VALVULA3,1);
		if(sector==4)SetPIN(VALVULA4,1);
		return;
	}else{
		if(sector==1)SetPIN(VALVULA1,0);
		if(sector==2)SetPIN(VALVULA2,0);
		if(sector==3)SetPIN(VALVULA3,0);
		if(sector==4)SetPIN(VALVULA4,0);	}
}


void SENSOR_init(void)
{
	tomarhumedad=10000;
	return;

}
