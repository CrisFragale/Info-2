
#ifndef DRIVERS_LPC_INC_DR_ADC_H_
#define DRIVERS_LPC_INC_DR_ADC_H_
#include "DR_TIPOS.h"
#include "DR_GPIO.h"

/***********************************************************************************************************************************
 *** INCLUDES GLOBALES
 **********************************************************************************************************************************/
//0x4008C000UL : Registro de conversion del DAC:
#define		DIR_DACR	( ( uint32_t  * ) 0x4008C000UL )
//0x4008C004UL : Registro de control del DAC:
#define		DIR_DACCTRL	( ( uint32_t  * ) 0x4008C004UL )
//0x4008C008UL : Registro de contador del DAC:
#define		DIR_DACCNTVAL ( ( uint32_t  * ) 0x4008C008UL )


//0x40034000UL: Registro de control del ADC:
#define		DIR_AD0CR	( ( uint32_t  * ) 0x40034000UL )
//0x40034004UL: Registro de estado del ADC:
#define		DIR_AD0GDR	( ( uint32_t  * ) 0x40034004UL )
//0x4003400CUL: Registro de interrupcion del ADC
#define		DIR_AD0INTEN ( ( uint32_t  * ) 0x4003400CUL )
//0x40034010UL: Registros de estado de los ADCx


#define		AD0DR0		AD0DR[0]
#define		AD0DR1		AD0DR[1]
#define		AD0DR2		AD0DR[2]
#define		AD0DR3		AD0DR[3]
#define		AD0DR4		AD0DR[4]
#define		AD0DR5		AD0DR[5]
#define		AD0DR6		AD0DR[6]
#define		AD0DR7		AD0DR[7]

#define	ADC_VAL(reg)	((reg>>04)&0x00000FFF)
#define	ADC_DONE(reg)	((reg>>31)&0x00000001)
#define	ADC_CHAN(reg)	((reg>>24)&0x00000007)

#define	ADC0_VAL		ADC_VAL(AD0DR0)
#define	ADC1_VAL		ADC_VAL(AD0DR1)
#define	ADC2_VAL		ADC_VAL(AD0DR2)
#define	ADC3_VAL		ADC_VAL(AD0DR3)
#define	ADC4_VAL		ADC_VAL(AD0DR4)
#define	ADC5_VAL		ADC_VAL(AD0DR5)
#define	ADC6_VAL		ADC_VAL(AD0DR6)
#define	ADC7_VAL		ADC_VAL(AD0DR7)

//ADC y DAC:
#define DAC0		PORT0,26
#define	ADC0_0      PORT0,23
#define	ADC0_1      PORT0,24
#define	ADC0_2 	   	PORT0,25
#define	ADC0_3      PORT0,26
#define	ADC0_4      PORT1,30
#define	ADC0_5      PORT1,31
#define	ADC0_6      PORT0,3
#define	ADC0_7      PORT0,2

#define AD0_CH0 		0
#define AD0_CH1 		1			// LPCxpreso
#define AD0_CH2 		2			// LPCxpreso
#define AD0_CH3 		3
#define AD0_CH4 		4
#define AD0_CH5 		5			// LPCxpreso
#define AD0_CH6 		6
#define AD0_CH7 		7

#define MAX_MUESTRAS	128
/***********************************************************************************************************************************
 *** DEFINES GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MACROS GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TIPO DE DATOS GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES
 **********************************************************************************************************************************/
extern volatile uint32_t valorADC1[ MAX_MUESTRAS ];
extern volatile uint32_t valorADC2[ MAX_MUESTRAS ];
extern volatile uint32_t valorADC5[ MAX_MUESTRAS ];

/***********************************************************************************************************************************
 *** PROTOTIPOS DE FUNCIONES GLOBALES
 **********************************************************************************************************************************/
void InicializarADC ( void );

#endif /* DRIVERS_LPC_INC_DR_ADC_H_ */
