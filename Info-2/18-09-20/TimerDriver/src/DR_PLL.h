#ifndef KITINIC_H_
#define KITINIC_H_
#include"DR_tipos.h"

//!< ///////////////////   PCONP   //////////////////////////
//!<  Power Control for Peripherals register (PCONP - 0x400F C0C4) [pag. 62 user manual LPC1769]
//!< 0x400FC0C4UL : Direccion de inicio del registro de habilitación de dispositivos:
#define 	PCONP	(* ( ( __RW uint32_t  * ) 0x400FC0C4UL ))

#define		PCTIM0		1
#define		PCTIM1		2
#define		PCUART0		3
#define		PCUART1		4
#define		PCPWM1		6
#define		PCI2C0		7
#define		PCSPI		8
#define		PCRTC		9
#define		PCSSP1		10
#define		PCADC		12
#define		PCCAN1		13
#define		PCCAN2		14
#define		PCGPIO		15
#define		PCRIT		16
#define		PCMCPWM		17
#define		PCQEI		18
#define		PCI2C1		19
#define		PCSSP0		21
#define		PCTIM2		22
#define		PCTIM3		23
#define		PCUART2		24
#define		PCUART3		25
#define		PCI2C2		26
#define		PCI2S		27
#define		PCGPDMA		29
#define		PCENET		30
#define		PCUSB		31

//!< ///////////////////   PCLKSEL   //////////////////////////
//!< Peripheral Clock Selection registers 0 and 1 (PCLKSEL0 -0x400F C1A8 and PCLKSEL1 - 0x400F C1AC) [pag. 56 user manual]
//!< 0x400FC1A8UL : Direccion de inicio de los registros de seleccion de los CLKs de los dispositivos:
#define		PCLKSEL		( ( __RW uint32_t  * ) 0x400FC1A8UL )
//!< Registros PCLKSEL
#define		PCLKSEL0	PCLKSEL[0]
#define		PCLKSEL1	PCLKSEL[1]

#define		PCLK_WDT		0
#define		PCLK_TIMER0		2
#define		PCLK_TIMER1		4
#define		PCLK_UART0		6
#define		PCLK_UART1		8
#define		PCLK_PWM1		12
#define		PCLK_I2C0		14
#define		PCLK_SPI		16
#define		PCLK_SSP1		20
#define		PCLK_DAC		22
#define		PCLK_ADC		24
#define		PCLK_CAN1		26
#define		PCLK_CAN2		28
#define		PCLK_ACF		30
#define		PCLK_QEI		0
#define		PCLK_GPIOINT	2
#define		PCLK_PCB		4
#define		PCLK_I2C1		6
#define		PCLK_SSP0		10
#define		PCLK_TIMER2		12
#define		PCLK_TIMER3		14
#define		PCLK_UART2		16
#define		PCLK_UART3		18
#define		PCLK_I2C2		20
#define		PCLK_I2S		22
#define		PCLK_RIT		26
#define		PCLK_SYSCON		28
#define		PCLK_MC			30

//////////////Registros del CLOCK y de sistema/////////////////
//0x400FC1A0UL: Registro de control de sistema y registro de status:
#define		DIR_SCS			( (__RW uint32_t *) 0x400FC1A0UL)
//0x400FC104UL: Registro de configuracion del clock:
#define		DIR_CCLKCFG		( (__RW uint32_t *) 0x400FC104UL)
//0x400FC10CUL: Registro de seleccion del clock:
#define		DIR_CLKSRCSEL	( (__RW uint32_t *) 0x400FC10CUL)
//0x400FC1C8UL: Clock Output Config register:
#define		DIR_CLKOUTCFG	( ( __RW uint32_t *) 0x400FC1C8UL)
//0x400FC000UL: Flash access configuration:
#define		DIR_FLASHCFG	( (__RW uint32_t *) 0x400FC000UL)

/////////////////Registros de los PLL///////////////////////////
//0x400FC080UL: Registro de control del PLL0:
#define		DIR_PLL0CON		( (__RW uint32_t *) 0x400FC080UL)
//0x400FC084UL: Registro de configuracion del PLL0:
#define		DIR_PLL0CFG		( (__RW uint32_t *) 0x400FC084UL)
//0x400FC088UL: Registro de estado del PLL0:
#define		DIR_PLL0STAT	( (__RW uint32_t *) 0x400FC088UL)
//0x400FC08CUL: Registro de control del PLL0:
#define		DIR_PLL0FEED	( (__RW uint32_t *) 0x400FC08CUL)
//0x400FC0A0UL: Registro de control del PLL1:
#define		DIR_PLL1CON		( (__RW uint32_t *) 0x400FC0A0UL)
//0x400FC0A4UL: Registro de configuracion del PLL1:
#define		DIR_PLL1CFG		( (__RW uint32_t *) 0x400FC0A4UL)
//0x400FC0A8UL: Registro de estado del PLL1:
#define		DIR_PLL1STAT	( (__RW uint32_t *) 0x400FC0A8UL)
//0x400FC0ACUL: Registro de control del PLL1:
#define		DIR_PLL1FEED	( (__RW uint32_t *) 0x400FC0ACUL)

//Registro de status y configuracion del sistema:
#define		SCS			DIR_SCS[0]
#define 	FLASHCFG	DIR_FLASHCFG[0]

//Registros de control del CLOCK:
#define		CCLKCFG		DIR_CCLKCFG[0]
#define		CLKSRCSEL	DIR_CLKSRCSEL[0]
#define		CLKOUTCFG	DIR_CLKOUTCFG[0]

//PLL0:
#define		PLL0CON		DIR_PLL0CON[0]
#define		PLL0CFG		DIR_PLL0CFG[0]
#define		PLL0STAT	DIR_PLL0STAT[0]
#define		PLL0FEED	DIR_PLL0FEED[0]

//PLL1:
#define		PLL1CON		DIR_PLL1CON[0]
#define		PLL1CFG		DIR_PLL1CFG[0]
#define		PLL1STAT	DIR_PLL1STAT[0]
#define		PLL1FEED	DIR_PLL1FEED[0]

//Valores para configuracion del PLL:
#define CLOCK_SETUP_Value 	    1
#define SCS_Value				0x00000020
#define CLKSRCSEL_Value         0x00000001
#define PLL0_SETUP_Value        1
#define PLL0CFG_Value           0x00050063
#define PLL1_SETUP_Value        1
#define PLL1CFG_Value           0x00000023
#define CCLKCFG_Value           0x00000003
#define USBCLKCFG_Value         0x00000000
#define PCLKSEL0_Value          0x00000000
#define PCLKSEL1_Value          0x00000000
#define PCONP_Value             0x042887DE
#define CLKOUTCFG_Value         0x00000000
#define FLASHCFG_Value			0x00004000

void InicializarPLL	(void);
void InitGPIOs (void);

#endif /* KITINIC_H_ */
