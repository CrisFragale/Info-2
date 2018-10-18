/*
 * DR_NVIC.h
 *
 *  Created on: 24/11/2014
 *      Author: Pablo
 */

#ifndef DR_NVIC_H_
#define DR_NVIC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "DR_tipos.h"

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



#ifdef __cplusplus
}
#endif

#endif /* DR_NVIC_H_ */
