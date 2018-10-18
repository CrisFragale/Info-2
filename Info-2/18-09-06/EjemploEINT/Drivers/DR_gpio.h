/*******************************************************************************************************************************//**
 *
 * @file		Infotronic.h
 * @brief		Macros, tipos , prototipos, de la aplicacion
 * @date		23-03-16
 * @author		Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/

#ifndef DR_GPIO_H_
#define DR_GPIO_H_
/***********************************************************************************************************************************
 *** INCLUDES GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** DEFINES GLOBALES
 **********************************************************************************************************************************/
#include "DR_tipos.h"

/***********************************************************************************************************************************
 *** MACROS GLOBALES
 **********************************************************************************************************************************/
#define		PORT0					0
#define		PORT1					1
#define		PORT2					2
#define		PORT3					3
#define		PORT4					4

//!< Entradas - Salidas
#define	 GPIO  ( ( __RW uint32_t * )  0x2009C000 )

#define	 FIO0DIR	GPIO[ 0 ]
#define	 FIO0MASK	GPIO[ 4 ]
#define	 FIO0PIN	GPIO[ 5 ]
#define	 FIO0SET	GPIO[ 6 ]
#define	 FIO0CLR	GPIO[ 7 ]
#define	 FIO1DIR	GPIO[ 8 ]
#define	 FIO1MASK	GPIO[ 12 ]
#define	 FIO1PIN	GPIO[ 13 ]
#define	 FIO1SET	GPIO[ 14 ]
#define	 FIO1CLR	GPIO[ 15 ]
#define	 FIO2DIR	GPIO[ 16 ]
#define	 FIO2MASK	GPIO[ 20 ]
#define	 FIO2PIN	GPIO[ 21 ]
#define	 FIO2SET	GPIO[ 22 ]
#define	 FIO2CLR	GPIO[ 23 ]
#define	 FIO3DIR	GPIO[ 24 ]
#define	 FIO3MASK	GPIO[ 28 ]
#define	 FIO3PIN	GPIO[ 29 ]
#define	 FIO3SET	GPIO[ 30 ]
#define	 FIO3CLR	GPIO[ 31 ]
#define	 FIO4DIR	GPIO[ 32 ]
#define	 FIO4MASK	GPIO[ 36 ]
#define	 FIO4PIN	GPIO[ 37 ]
#define	 FIO4SET	GPIO[ 38 ]
#define	 FIO4CLR	GPIO[ 39 ]

//!< Registros de modo de funcionamiento las gpio
#define	 PINMODE  		( ( __RW uint32_t * )  0x4002C040 )

#define	 PINMODE0	PINMODE[0]
#define	 PINMODE1	PINMODE[1]
#define	 PINMODE2	PINMODE[2]
#define	 PINMODE3	PINMODE[3]
#define	 PINMODE4	PINMODE[4]
#define	 PINMODE5	PINMODE[5]		//!< No esta en uso
#define	 PINMODE6	PINMODE[6]		//!< No esta en uso
#define	 PINMODE7	PINMODE[7]
#define	 PINMODE8	PINMODE[8]		//!< No esta en uso
#define	 PINMODE9	PINMODE[9]

#define	 PINMODE_OD		( ( __RW uint32_t * )  0x4002C068 )

#define	 PINMODE_OD0	PINMODE_OD[0]
#define	 PINMODE_OD1	PINMODE_OD[1]
#define	 PINMODE_OD2	PINMODE_OD[2]
#define	 PINMODE_OD3	PINMODE_OD[3]
#define	 PINMODE_OD4	PINMODE_OD[4]


#define 	ALTO	1
#define 	BAJO	0
#define 	SALIDA	1
#define 	ENTRADA	0

#define 	FUNCION_GPIO		0
#define 	FUNCION_1			1
#define 	FUNCION_2			2
#define 	FUNCION_3			3

#define 	PULLUP				0
#define 	REPEATER			1
#define 	NONE				2
#define 	PULLDOWN			3

/***********************************************************************************************************************************
 *** TIPO DE DATOS GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** PROTOTIPOS DE FUNCIONES GLOBALES
 **********************************************************************************************************************************/
void SetDIR ( uint8_t puerto , uint8_t bit , uint8_t dir );
void SetMODE ( uint8_t puerto , uint8_t bit , uint8_t modo );
void SetPIN ( uint8_t puerto , uint8_t bit , uint8_t estado );
uint8_t GetPIN( uint8_t puerto , uint8_t bit , uint8_t actividad );

#endif /* DR_GPIO_H_ */
