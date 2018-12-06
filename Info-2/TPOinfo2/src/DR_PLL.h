#ifndef KITINIC_H_
#define KITINIC_H_
#include"DR_TIPOS.h"

	#define 	PCONP	(* ( ( __RW uint32_t  * ) 0x400FC0C4UL ))
	#define 	PCADC	12
	#define		PCLKSEL		( ( __RW uint32_t  * ) 0x400FC1A8UL )
	#define		PCLKSEL0	PCLKSEL[0]
	#define		PCLKSEL1	PCLKSEL[1]

#define		DIR_SCS			( (uint32_t *) 0x400FC1A0UL)
#define		DIR_CCLKCFG		( (uint32_t *) 0x400FC104UL)
#define		DIR_CLKSRCSEL	( (uint32_t *) 0x400FC10CUL)
#define		DIR_CLKOUTCFG	( (uint32_t *) 0x400FC1C8UL)
#define		DIR_FLASHCFG	( (uint32_t *) 0x400FC000UL)

#define		DIR_PLL0CON		( (uint32_t *) 0x400FC080UL)
#define		DIR_PLL0CFG		( (uint32_t *) 0x400FC084UL)
#define		DIR_PLL0STAT	( (uint32_t *) 0x400FC088UL)
#define		DIR_PLL0FEED	( (uint32_t *) 0x400FC08CUL)
#define		DIR_PLL1CON		( (uint32_t *) 0x400FC0A0UL)
#define		DIR_PLL1CFG		( (uint32_t *) 0x400FC0A4UL)
#define		DIR_PLL1STAT	( (uint32_t *) 0x400FC0A8UL)
#define		DIR_PLL1FEED	( (uint32_t *) 0x400FC0ACUL)

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
