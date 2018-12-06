/*
 * FW_RTC.h
 *
 *  Created on: 14/03/2012
 *      Author: Pablo
 */

#ifndef DR_RTC_H_
#define DR_RTC_H_

#include "RegsLPC17xx.h"


#define PESOS    0
#define DATOS    1
#define CORROBORO 2

// Definiciones RTC
#define RTC_INT_SEG			0x01
#define RTC_INT_MIN			0x02
#define RTC_INT_HOUR		0x04
#define RTC_INT_DAYMONTH	0x08
#define RTC_INT_DAYWEEK		0x10
#define RTC_INT_DAYYEAR		0x20
#define RTC_INT_MONTH		0x40
#define RTC_INT_YEAR		0x80

#define RTC_AL_SEG			0x01
#define RTC_AL_MIN			0x02
#define RTC_AL_HOUR			0x04
#define RTC_AL_DAYMONTH		0x08
#define RTC_AL_DAYWEEK		0x10
#define RTC_AL_DAYYEAR		0x20
#define RTC_AL_MONTH		0x40
#define RTC_AL_YEAR			0x80

//Macros
#define RTC_SetHour(hour)		(HOUR = hour)
#define RTC_SetMin(min)			(MIN = min)
#define RTC_SetSec(sec)			(SEC = sec)
#define RTC_SetYear(year)		(YEAR = year)
#define RTC_SetMonth(month)		(MONTH = month)
#define RTC_SetDayOfMonth(day)	(DOM = day)
#define RTC_SetDayOfWeek(day)	(DOW = day)
#define RTC_SetDayOfYear(day)	(DOY = day)

#define RTC_GetHour(hour)		(HOUR)
#define RTC_GetMin(min)			(MIN)
#define RTC_GetSec(sec)			(SEC)
#define RTC_GetYear(year)		(YEAR)
#define RTC_GetMonth(month)		(MONTH)
#define RTC_GetDayOfMonth(day)	(DOM)
#define RTC_GetDayOfWeek(day)	(DOW)
#define RTC_GetDayOfYear(day)	(DOY)

void RTC_Init(void);

#endif /* DR_RTC_H_ */
