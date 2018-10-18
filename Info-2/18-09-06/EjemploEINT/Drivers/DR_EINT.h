/*******************************************************************************************************************************//**
 *
 * @file		DR_EINT.c
 * @brief		Interrupciones externas
 * @date		Fecha de creacion del archivo 09-06-16
 * @author		Marcelo, Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/

#ifndef DR_EINT_H_
#define DR_EINT_H_

/***********************************************************************************************************************************
 *** INCLUDES GLOBALES
 **********************************************************************************************************************************/
#include "DR_tipos.h"
#include "DR_pinsel.h"
#include "DR_gpio.h"

/***********************************************************************************************************************************
 *** DEFINES GLOBALES
 **********************************************************************************************************************************/
#define		EINT0_PIN		PORT2,10
#define		EINT1_PIN		PORT2,11
#define		EINT2_PIN		PORT2,12
#define		EINT3_PIN		PORT2,13

#define 	EXTINT0 		0
#define 	EXTINT1 		1
#define 	EXTINT2 		2
#define 	EXTINT3 		3

#define 	EXT_NIVEL_L 	0
#define 	EXT_NIVEL_H 	1

#define 	EXT_FLANCO_F 	0
#define 	EXT_FLANCO_R 	1

#define		EXT_FLANCO_ACT	0
#define 	EXT_NIVEL_ACT	1

/***********************************************************************************************************************************
 *** MACROS GLOBALES
 **********************************************************************************************************************************/
//0xE000E100UL : Direccion de inicio de los registros de habilitación (set) de interrupciones en el NVIC:
#define		ISER		( ( uint32_t * ) 0xE000E100UL )
//0xE000E180UL : Direccion de inicio de los registros de deshabilitacion (clear) de interrupciones en el NVIC:
#define		ICER		( (  uint32_t * ) 0xE000E180UL )


//Registros ISER: Para habilitar las Interupciones Se activan con 1 Escribiendo un 0 no hace nada
#define		ISER0		ISER[0]
#define		ISER1		ISER[1]
#define		ISE_EINT3	ISER[0] |= (0x00000001 << 21)  //ISER0->bit21 pongo un 1 en el bit 21 para habilitar la INT EINT3
#define     ISE_EINT2	ISER[0] |= (0x00000001 << 20)  //ISER0->bit20 pongo un 1 en el bit 20 para habilitar la INT EINT2
#define     ISE_EINT1	ISER[0] |= (0x00000001 << 19)  //ISER0->bit19 pongo un 1 en el bit 19 para habilitar la INT EINT1
#define     ISE_EINT0	ISER[0] |= (0x00000001 << 18)  //ISER0->bit18 pongo un 1 en el bit 18 para habilitar la INT EINT1
#define		ISE_ADC		ISER[0] |= (0x00000001 << 22)

//Registros ICER: Para deshabilitar las Interupciones Se desactivan con 1 Escribiendo un 0 no hace nada
//Registros ICER:

#define		ICER0		ICER[0]
#define		ICER1		ICER[1]
#define		ICE_EINT3	ICER0 |= (0x00000001 << 21) // deshabilito a EINT3
#define		ICE_EINT2	ICER0 |= (0x00000001 << 20) // deshabilito a EINT2
#define		ICE_EINT1	ICER0 |= (0x00000001 << 19) // deshabilito a EINT1
#define		ICE_EINT0	ICER0 |= (0x00000001 << 18) // deshabilito a EINT0
#define		ICE_ADC		ICER0 |= (0x00000001 << 22)


#define		CLR_EINT3		EXTINT[0] |= 0x00000001 << 3 // bajo el flag de EINT3
#define		CLR_EINT2		EXTINT[0] |= 0x00000001 << 2 // bajo el flag de EINT2
#define		CLR_EINT1		EXTINT[0] |= 0x00000001 << 1 // bajo el flag de EINT1
#define		CLR_EINT0		EXTINT[0] |= 0x00000001      // bajo el flag de EINT0

#define		EXTINT 			( * ( (__RW uint32_t  * ) 0x400FC140UL ) ) // Reg de Flags para limpiar la ISR

// Registro EXTMODE : Para seleccionar si la ISR Externa activa por flanco ó nivel
#define		EXTMODE 		( * ( (__RW uint32_t  * ) 0x400FC148 ) )
//#define		EXTMODE3_F		EXTMODE[0] |= 0x00000001 << 3  // EINT3 por flanco
//#define		EXTMODE2_F		EXTMODE[0] |= 0x00000001 << 2  // EINT2 por flanco
//#define		EXTMODE1_F		EXTMODE[0] |= 0x00000001 << 1  // EINT1 por flanco
//#define		EXTMODE0_F		EXTMODE[0] |= 0x00000001       // EINT0 por flanco

// Registro EXTPOLAR : selecciona Polaridad del EXTMODE
#define    EXTPOLAR        	( * ( (__RW uint32_t  * ) 0x400FC14C ) )
//#define    EXTPOLAR3_P      EXTPOLAR[0] |= 0X00000001 << 3 // Flanco ó Nivel Positivo
//#define    EXTPOLAR2_P      EXTPOLAR[0] |= 0X00000001 << 2 // Flanco ó Nivel Positivo
//#define    EXTPOLAR1_P      EXTPOLAR[0] |= 0X00000001 << 1 // Flanco ó Nivel Positivo
//#define    EXTPOLAR0_P      EXTPOLAR[0] |= 0X00000001      // Flanco ó Nivel Positivo

#define NVIC_WDT			0
#define	NVIC_TIM0			1
#define	NVIC_TIM1			2
#define NVIC_TIM2			3
#define NVIC_TIM3			4
#define NVIC_UART0			5
#define NVIC_UART1			6
#define NVIC_UART2			7
#define NVIC_UART3			8
#define NVIC_PWM			9
#define NVIC_I2C0			10
#define NVIC_I2C1			11
#define NVIC_I2C2			12
#define NVIC_SPI			13
#define NVIC_SSP0			14
#define NVIC_SSP1			15
#define NVIC_PLL0			16
#define NVIC_RTC			17
#define NVIC_EINT0			18
#define	NVIC_EINT1			19
#define	NVIC_EINT2			20
#define NVIC_EINT3			21
#define NVIC_ADC			22
#define	NVIC_BOD			23
#define NVIC_USB			24
#define NVIC_CAN			25
#define NVIC_DMA			26
#define NVIC_I2S			27
#define NVIC_ENET			28
#define NVIC_RIT			29
#define NVIC_MCPWM			30
#define NVIC_QEI			31

/***********************************************************************************************************************************
 *** TIPO DE DATOS GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES
 **********************************************************************************************************************************/


/***********************************************************************************************************************************
 *** PROTOTIPOS DE FUNCIONES GLOBALES
 **********************************************************************************************************************************/
void Emergency_STOP (void);
void EXTINT_Inicializacion( uint8_t  , uint8_t  , uint8_t  );

extern uint8_t flag_IntExt;

#endif /* DR_EINT_H_ */
