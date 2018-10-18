/*
 * GENERATED FILE - DO NOT EDIT
 * (c) Code Red Technologies Ltd, 2008-2013
 * (c) NXP Semiconductors 2013-2018
 * Generated linker script file for LPC1769
 * Created from memory.ldt by FMCreateLinkMemory
 * Using Freemarker v2.3.23
 * LPCXpresso v8.2.2 [Build 650] [2016-09-09]  on 05/09/2018 22:40:25
 */

MEMORY
{
  /* Define each memory region */
  MFlash512 (rx) : ORIGIN = 0x0, LENGTH = 0x80000 /* 512K bytes (alias Flash) */  
  RamLoc32 (rwx) : ORIGIN = 0x10000000, LENGTH = 0x8000 /* 32K bytes (alias RAM) */  
}

  /* Define a symbol for the top of each memory region */
  __base_MFlash512 = 0x0  ; /* MFlash512 */  
  __base_Flash = 0x0 ; /* Flash */  
  __top_MFlash512 = 0x0 + 0x80000 ; /* 512K bytes */  
  __top_Flash = 0x0 + 0x80000 ; /* 512K bytes */  
  __base_RamLoc32 = 0x10000000  ; /* RamLoc32 */  
  __base_RAM = 0x10000000 ; /* RAM */  
  __top_RamLoc32 = 0x10000000 + 0x8000 ; /* 32K bytes */  
  __top_RAM = 0x10000000 + 0x8000 ; /* 32K bytes */  
