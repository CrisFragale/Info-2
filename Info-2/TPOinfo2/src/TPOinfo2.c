/*
===============================================================================
 Name        : TPOinfo2.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifndef __USE_CMSIS
#include "RegsLPC17xx.h"
#include "init.h"
#include "DR_TIPOS.h"
#endif

// para los for
uint8_t i,j,p,l;


Mde_t Mde[8];
uint8_t flag;
uint8_t init=0;
uint8_t contador, contador2;
Rtc_t rtc;
uint8_t dato;



// para mde
uint8_t estadoPS=CC;
uint8_t estadoPasaInfo=PP;
uint8_t estado=DECISION;

//timers
uint32_t AcRTC=0;
uint32_t tomarhumedad=0;
uint32_t TimerRegado[8];


// para comunicaciones serie
char auxRTC[17];
char auxPS[41];


int main(void) {



	InicializarPLL ();
	UART_Init(115200);
	RTC_Init();
	SENSOR_init();
	InitADC();

    while(1) {

    	if(flag==0)
    	{
    		RTCconfig();
    		InicializarSysTick();

    	}else{

    		for(i=1;i<9;i++)
    		{
    			if(Mde[i].Habilitado==1 && init==1)
    			{
    				MDE(Mde[i]);
    			}
    			maquinapuertoserie();
    			pasarinfo();
    		}

    	}


    }
    return 0 ;
}
