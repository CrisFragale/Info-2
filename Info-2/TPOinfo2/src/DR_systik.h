
#ifndef DR_SYSTICK_H_
#define DR_SYSTICK_H_

#include "DR_TIPOS.h"

#define 	SYSTICK		( (systick_t *) 0xE000E010UL )

#define		STCTRL		SYSTICK->_STCTRL

	#define	ENABLE			SYSTICK->bits._ENABLE
	#define	TICKINT			SYSTICK->bits._TICKINT
	#define	CLKSOURCE		SYSTICK->bits._CLKSOURCE
	#define	COUNTFLAG		SYSTICK->bits._COUNTFLAG

#define		STRELOAD	SYSTICK->_STRELOAD
#define		STCURR		SYSTICK->_STCURR
#define		STCALIB		SYSTICK->_STCALIB


typedef struct
{
	union{
		__RW uint32_t _STCTRL;
		struct{
			__RW uint32_t _ENABLE:1;
			__RW uint32_t _TICKINT:1;
			__RW uint32_t _CLKSOURCE:1;
			__RW uint32_t _RESERVED0:13;
			__RW uint32_t _COUNTFLAG:1;
			__RW uint32_t _RESERVED1:15;
		}bits;
	};
	__RW uint32_t _STRELOAD;
	__RW uint32_t _STCURR;
	__R uint32_t  _STCALIB;
}systick_t;


void InicializarSysTick ( void );

#endif /* DR_SYSTICK_H_ */
