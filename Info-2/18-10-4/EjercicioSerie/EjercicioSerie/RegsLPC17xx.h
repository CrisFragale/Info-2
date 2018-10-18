/**
 	\file RegsLPC17xx.h
 	\brief Header para LPC17xx
 	\details Este archivo contiene la definicion de
 			 los registros del LPC17xx utilizados en
 			 informatica II
 	\author Pablo Irrera Condines
 	\date 2015.04.30
*/
#ifndef REGSLPC17XX_H_
#define REGSLPC17XX_H_

#define		__R			volatile const
#define		__W			volatile
#define		__RW		volatile

typedef 	unsigned int 		uint32_t;
typedef 	unsigned short 		uint16_t;
typedef 	unsigned char 		uint8_t;
typedef 	int			 		int32_t;
typedef 	short 				int16_t;
typedef 	char 				int8_t;

//!< ////////////////Registros PINSEL//////////////////////////////
//!< 0x4002C000UL : Direccion de inicio de los registros PINSEL
#define		PINSEL		( (__RW uint32_t *) 0x4002C000UL )

#define		PINSEL0		PINSEL[0]	//!< PINSEL0------>P0[15:0] 		(0x4002C000)
#define		PINSEL1		PINSEL[1]	//!< PINSEL1------>P0[31:16] 		(0x4002C004)
#define		PINSEL2		PINSEL[2]	//!< PINSEL2------>P1[15:0] 		(0x4002C008)
#define		PINSEL3		PINSEL[3]	//!< PINSEL3------>P1[31:16] 		(0x4002C00C)
#define		PINSEL4		PINSEL[4]	//!< PINSEL4------>P2[15:0] 		(0x4002C010)
#define		PINSEL5		PINSEL[5]	//!< PINSEL5------>P2[31:16] 		NOT USED
#define		PINSEL6		PINSEL[6]	//!< PINSEL6------>P3[15:0]			NOT USED
#define		PINSEL7		PINSEL[7]	//!< PINSEL7------>P3[31:16] 		(0x4002C01C)
#define		PINSEL8		PINSEL[8]	//!< PINSEL8------>P4[15:0]			NOT USED
#define		PINSEL9		PINSEL[9]	//!< PINSEL9------>P4[31:16] 		(0x4002C024)

//!< //////////////////Registros PINMODE ///////////////////////////
//!< 0x4002C040UL : Direccion de inicio de los registros de modo de los pines del GPIO
#define	PINMODE		( (__RW uint32_t *) 0x4002C040UL )

#define		PINMODE0	PINMODE[0]		//!< 0x4002C040
#define		PINMODE1	PINMODE[1]		//!< 0x4002C044
#define		PINMODE2	PINMODE[2]		//!< 0x4002C048
#define		PINMODE3	PINMODE[3]		//!< 0x4002C04C
#define		PINMODE4	PINMODE[4]		//!< 0x4002C050
#define		PINMODE5	PINMODE[5]		//!< 0x4002C054
#define		PINMODE6	PINMODE[6]		//!< 0x4002C058
#define		PINMODE7	PINMODE[7]		//!< 0x4002C05C
#define		PINMODE9	PINMODE[9]		//!< 0x4002C064

//!< ///////////////// REGISTROS PINMODE_OD ///////////////////////////
//!< 0x4002C068UL : Direccion de inicio de los registros de control del modo OPEN DRAIN
#define		PINMODE_OD		( (__RW uint32_t *) 0x4002C068UL )

#define		PINMODE_OD0		PINMODE_OD[0]
#define		PINMODE_OD1		PINMODE_OD[1]
#define		PINMODE_OD2		PINMODE_OD[2]
#define		PINMODE_OD3		PINMODE_OD[3]
#define		PINMODE_OD4		PINMODE_OD[4]

//!< ////////////////// REGISTROS GPIOs //////////////////////////////
//!< 0x2009C000UL : Direccion de inicio de los registros de GPIOs
#define	GPIOs		( (__RW uint32_t *) 0x2009C000UL )

/*	*			*
	*************************
	*	FIODIR		*	0x2009C000
	*************************
	*	RESERVED	*	0x2009C004
	*************************
	*	RESERVED	*	0x2009C008
	*************************
	*	RESERVED	*	0x2009C00C
	*************************
	*	FIOMASK		*	0x2009C010
	*************************
	*	FIOPIN		*	0x2009C014
	*************************
	*	FIOSET		*	0x2009C018
	*************************
	*	FIOCLR		*	0x2009C01C
	*************************
	*			*
	*			*
*/
#define		FIO0DIR		GPIOs[0]	//!< 0x2009C000
#define		FIO1DIR		GPIOs[8]	//!< 0x2009C020
#define		FIO2DIR		GPIOs[16]	//!< 0x2009C040
#define		FIO3DIR		GPIOs[24]	//!< 0x2009C060
#define		FIO4DIR		GPIOs[32]	//!< 0x2009C080

#define		FIO0MASK	GPIOs[4]	//!< 0x2009C010
#define		FIO1MASK	GPIOs[12]	//!< 0x2009C030
#define		FIO2MASK	GPIOs[20]	//!< 0x2009C050
#define		FIO3MASK	GPIOs[28]	//!< 0x2009C070
#define		FIO4MASK	GPIOs[36]	//!< 0x2009C090

#define		FIO0PIN		GPIOs[5]	//!< 0x2009C014
#define		FIO1PIN		GPIOs[13]	//!< 0x2009C034
#define		FIO2PIN		GPIOs[21]	//!< 0x2009C054
#define		FIO3PIN		GPIOs[29]	//!< 0x2009C074
#define		FIO4PIN		GPIOs[37]	//!< 0x2009C094

#define		FIO0SET		GPIOs[6]	//!< 0x2009C018
#define		FIO1SET		GPIOs[14]	//!< 0x2009C038
#define		FIO2SET		GPIOs[22]	//!< 0x2009C058
#define		FIO3SET		GPIOs[30]	//!< 0x2009C078
#define		FIO4SET		GPIOs[38]	//!< 0x2009C098

#define		FIO0CLR		GPIOs[7]	//!< 0x2009C01C
#define		FIO1CLR		GPIOs[15]	//!< 0x2009C03C
#define		FIO2CLR		GPIOs[23]	//!< 0x2009C05C
#define		FIO3CLR		GPIOs[31]	//!< 0x2009C07C
#define		FIO4CLR		GPIOs[39]	//!< 0x2009C09C


//!< /////////////		SYSTICK		///////////////////////////
//!< Tipo de dato específico para manejar el SYSTICK
typedef struct
{
	union{
		__RW uint32_t _STCTRL;
		struct{
			__RW uint32_t _ENABLE:1;
			__RW uint32_t _TICKINT:1;
			__RW uint32_t _CLKSOURCE:1;
			__RW uint32_t _RESERVED0:12;
			__RW uint32_t _COUNTFLAG:1;
			__RW uint32_t _RESERVED1:16;
		}bits;
	};
	__RW uint32_t _STRELOAD;
	__RW uint32_t _STCURR;
	__R uint32_t  _STCALIB;
}systick_t;

//!< 0xE000E010UL: Registro de control del SysTick:
#define 	DIR_SYSTICK		( (systick_t *) 0xE000E010UL )

#define		STCTRL		DIR_SYSTICK->_STCTRL
#define		ENABLE		DIR_SYSTICK->bits._ENABLE
#define		TICKINT		DIR_SYSTICK->bits._TICKINT
#define		CLKSOURCE	DIR_SYSTICK->bits._CLKSOURCE
#define		COUNTFLAG	DIR_SYSTICK->bits._COUNTFLAG
#define		STRELOAD	DIR_SYSTICK->_STRELOAD
#define		STCURR		DIR_SYSTICK->_STCURR
#define		STCALIB		DIR_SYSTICK->_STCALIB


//!< ///////////////////   TIMERS   /////////////////////////////
//!< 0x40004000UL : Direccion de inicio de los registros del Timer0
#define		TIMER0		( (__RW uint32_t *) 0x40004000UL )
//!< 0x40008000UL : Direccion de inicio de los registros del Timer1
#define		TIMER1		( (__RW uint32_t *) 0x40008000UL )
//!< 0x40090000UL : Direccion de inicio de los registros del Timer2
#define		TIMER2		( (__RW uint32_t *) 0x40090000UL )
//!< 0x40094000UL : Direccion de inicio de los registros del Timer3
#define		TIMER3		( (__RW uint32_t *) 0x40094000UL )

//Registros de timers:

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

//!< ///////////////////   NVIC   //////////////////////////
//!< Nested Vectored Interrupt Controller (NVIC)
//!< 0xE000E100UL : Direccion de inicio de los registros de habilitación (set) de interrupciones en el NVIC:
#define		ISER		( (__RW uint32_t *) 0xE000E100UL )
//!< 0xE000E180UL : Direccion de inicio de los registros de deshabilitacion (clear) de interrupciones en el NVIC:
#define		ICER		( (__RW uint32_t *) 0xE000E180UL )

//!< Registros ISER:
#define		ISER0		ISER[0]
#define		ISER1		ISER[1]

//!< Registros ICER:
#define		ICER0		ICER[0]
#define		ICER1		ICER[1]


//!< ///////////////////   PCONP   //////////////////////////
//!<  Power Control for Peripherals register (PCONP - 0x400F C0C4) [pag. 62 user manual LPC1769]
//!< 0x400FC0C4UL : Direccion de inicio del registro de habilitación de dispositivos:
#define 	PCONP	(* ( (__RW uint32_t *) 0x400FC0C4UL ))


//!< //////////   INTERRUPCIONES EXTERNAS   /////////////////
//!< 0x400FC140UL : Direccion de inicio de los registros de configuracion de las interrupciones externas:
#define		EXT		( (__RW uint32_t *) 0x400FC140UL )

#define		EXTINT		EXT[0]
#define		EXTMODE		EXT[2]
#define		EXTPOLAR	EXT[3]


//!< ///////////////////   PCLKSEL   //////////////////////////
//!< Peripheral Clock Selection registers 0 and 1 (PCLKSEL0 -0x400F C1A8 and PCLKSEL1 - 0x400F C1AC) [pag. 56 user manual]
//!< 0x400FC1A8UL : Direccion de inicio de los registros de seleccion de los CLKs de los dispositivos:
#define		PCLKSEL		( (__RW uint32_t *) 0x400FC1A8UL )

//!< Registros PCLKSEL
#define		PCLKSEL0	PCLKSEL[0]
#define		PCLKSEL1	PCLKSEL[1]


//!< ///////////////////   UART0   //////////////////////////
//!< 0x4000C000UL : Registro de control de la UART0:
#define		UART0	( (__RW uint32_t *) 0x4000C000UL )

//!< Registros de la UART0:
#define		U0THR		UART0[0]
#define		U0RBR		UART0[0]
#define		U0DLL		UART0[0]

#define		U0DLM		UART0[1]
#define		U0IER		UART0[1]

#define		U0IIR		((__R uint32_t *)UART0)[2]
#define		U0FCR		((__W uint32_t *)UART0)[2]

#define		U0LCR		UART0[3]
//!< posición 4 no definida [consultar pag. 300 user manual LPC1769]
#define		U0LSR		UART0[5]
//!< posición 6 no definida [consultar pag. 300 user manual LPC1769]
#define		U0SCR		UART0[7]

//!< ///////////////////   UART1   //////////////////////////
//!< 0x40010000UL : Registro de control de la UART1:
#define		UART1	( (__RW uint32_t *) 0x40010000UL )

//!< Registros de la UART1:
#define		U1THR		UART1[0]
#define		U1RBR		UART1[0]
#define		U1DLL		UART1[0]

#define		U1DLM		UART1[1]
#define		U1IER		UART1[1]

#define		U1IIR		UART1[2]
#define		U1FCR		UART1[2]

#define		U1LCR		UART1[3]
#define		U1MCR		UART1[4]
#define		U1LSR		UART1[5]
#define		U1MSR		UART1[6]
#define		U1SCR		UART1[7]

//!< //////////BITS DE ANALISIS para todas las UARTs   ////////////////////
#define 	IER_RBR		0x01
#define 	IER_THRE	0x02
#define 	IER_RLS		0x04

#define 	IIR_PEND	0x01
#define 	IIR_RLS		0x06
#define 	IIR_RDA		0x04
#define 	IIR_CTI		0x0C
#define 	IIR_THRE	0x02

#define 	LSR_RDR		0x01
#define 	LSR_OE		0x02
#define 	LSR_PE		0x04
#define 	LSR_FE		0x08
#define 	LSR_BI		0x10
#define 	LSR_THRE	0x20
#define 	LSR_TEMT	0x40
#define 	LSR_RXFE	0x80

//!< macros útiles para UARTs
#define		U0RDR		(U0LSR & LSR_RDR)
#define		U0THRE		((U0LSR & LSR_THRE) >>5)
#define		U1RDR		(U1LSR & LSR_RDR)
#define		U1THRE		((U1LSR & LSR_THRE) >>5)


//!< ///////////////////   DAC /////////////////////////////
//!< 0x4008C000UL : Registro de conversion del DAC:
#define		DACR		(* ( (__RW uint32_t *) 0x4008C000UL ))
//!< 0x4008C004UL : Registro de control del DAC:
#define		DACCTRL		(* ( (__RW uint32_t *) 0x4008C004UL ))
//!< 0x4008C008UL : Registro de contador del DAC:
#define		DACCNTVAL 	(* ( (__RW uint32_t *) 0x4008C008UL ))


//!< ///////////////////   ADC   /////////////////////////////
//!< 0x40034000UL: Registro de control del ADC:
#define		AD0CR		(* ( (__RW uint32_t *) 0x40034000UL ))
//!< 0x40034004UL: Registro de estado del ADC:
#define		AD0GDR		(* ( (__RW uint32_t *) 0x40034004UL ))
//!< 0x4003400CUL: Registro de interrupcion del ADC
#define		AD0INTEN 	(* ( (__RW uint32_t *) 0x4003400CUL ))

//!< 0x40034010UL: Dirección de comienzo de los registros de estado de los ADCx
#define		AD0DR			( (__RW uint32_t *) 0x40034010UL )

//!< Registros de los estados de cada canal del ADC:
#define		AD0DR0		AD0DR[0]
#define		AD0DR1		AD0DR[1]
#define		AD0DR2		AD0DR[2]
#define		AD0DR3		AD0DR[3]
#define		AD0DR4		AD0DR[4]
#define		AD0DR5		AD0DR[5]
#define		AD0DR6		AD0DR[6]
#define		AD0DR7		AD0DR[7]


//!< ///////////////////   RTC   /////////////////////////////
//!< 0x40034000UL: Registro de configuracion y estado del RTC y registros de backup:
#define		RTC 			( (__RW uint32_t *) 0x40024000UL )

//!< Miscellaneous registers
#define		ILR			RTC[0]
#define		CCR			RTC[2]
#define		CIIR		RTC[3]
#define		AMR			RTC[4]
#define		RTC_AUX		RTC[23]
#define		RTC_AUXEN	RTC[22]
#define		CTIME0		RTC[5]
#define		CTIME1		RTC[6]
#define		CTIME2		RTC[7]

//!< Time counter registers
#define		SEC			RTC[8]
#define		MIN			RTC[9]
#define		HOUR		RTC[10]
#define		DOM			RTC[11]
#define		DOW			RTC[12]
#define		DOY			RTC[13]
#define		MONTH		RTC[14]
#define		YEAR		RTC[15]
#define		CALIBRATION	RTC[16]

//!< General purpose registers
#define		GPREG0		RTC[17]
#define		GPREG1		RTC[18]
#define		GPREG2		RTC[19]
#define		GPREG3		RTC[20]
#define		GPREG4		RTC[21]

//!< Alarm register group
#define		ALSEC		RTC[24]
#define		ALMIN		RTC[25]
#define		ALHOUR		RTC[26]
#define		ALDOM		RTC[27]
#define		ALDOW		RTC[28]
#define		ALDOY		RTC[29]
#define		ALMON		RTC[30]
#define		ALYEAR		RTC[31]

//////////////Registros del CLOCK y de sistema/////////////////
//0x400FC1A0UL: Registro de control de sistema y registro de status:
#define		SCS			(*((__RW uint32_t *)0x400FC1A0UL))
//0x400FC104UL: Registro de configuracion del clock:
#define		CCLKCFG		(*((__RW uint32_t *) 0x400FC104UL))
//0x400FC10CUL: Registro de seleccion del clock:
#define		CLKSRCSEL	(*((__RW uint32_t *) 0x400FC10CUL))
//0x400FC1C8UL: Clock Output Config register:
#define		CLKOUTCFG	(*((__RW uint32_t *) 0x400FC1C8UL))
//0x400FC000UL: Flash access configuration:
#define		FLASHCFG	(*((__RW uint32_t *) 0x400FC000UL))

/////////////////Registros de los PLL///////////////////////////
//0x400FC080UL: Registro de control del PLL0:
#define		PLL0CON		(*((__RW uint32_t *) 0x400FC080UL))
//0x400FC084UL: Registro de configuracion del PLL0:
#define		PLL0CFG		(*((__RW uint32_t *) 0x400FC084UL))
//0x400FC088UL: Registro de estado del PLL0:
#define		PLL0STAT	(*((__RW uint32_t *) 0x400FC088UL))
//0x400FC08CUL: Registro de control del PLL0:
#define		PLL0FEED	(*((__RW uint32_t *) 0x400FC08CUL))
//0x400FC0A0UL: Registro de control del PLL1:
#define		PLL1CON		(*((__RW uint32_t *) 0x400FC0A0UL))
//0x400FC0A4UL: Registro de configuracion del PLL1:
#define		PLL1CFG		(*((__RW uint32_t *) 0x400FC0A4UL))
//0x400FC0A8UL: Registro de estado del PLL1:
#define		PLL1STAT	(*((__RW uint32_t *) 0x400FC0A8UL))
//0x400FC0ACUL: Registro de control del PLL1:
#define		PLL1FEED	(*((__RW uint32_t *) 0x400FC0ACUL))

#endif /* REGSLPC17XX_H_ */
