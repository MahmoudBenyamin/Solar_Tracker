/************************************************************************************
* main.c                                                                            *
*																					*
*  Created on: Apr 29, 2022															*
*      Author: Tarek Fouad															*
*     Version: 1.2																	*
* Description:																		*
*																					*
************************************************************************************/
/************************************************************************************
                                 File Includes
************************************************************************************/
#include <math.h>
#include "STD_TYPES.h"
#include "SunCalc.h"

/************************************************************************************
                                   Functions
************************************************************************************/


		/**************************************************************
        * Function Name		   : SunCalc_u32SunriseTime
        * Function Arguments   : 1. Day Count from the 1th of Jan
        * 					     2. sunrise structure pointer
        * Function Description : Calculates
        *
		***************************************************************/


u32 SunCalc_u32SunriseTime(u32 Copy_u32DayID, sunrise *ptr) {
	f32 local_f32DeclinationAngle;
	f32 local_f32SunriseAngle;
	f32 local_f32SunriseHour;
	f32 local_f32Value;
	u32 result;
	local_f32DeclinationAngle = 23.45
			* sin(degree * ((284 + Copy_u32DayID) * ((f32) 360 / 365)));
	local_f32SunriseAngle = (-acos(
			-tan(degree * LATITUDE) * tan(degree * local_f32DeclinationAngle))
			/ (degree));
	local_f32SunriseHour = (12 + ((f32) local_f32SunriseAngle / 15));

	local_f32Value = local_f32SunriseHour; //5.3
	ptr->Hour = (u32) local_f32Value; //5
	local_f32Value -= (f32) ptr->Hour; //0.3
	local_f32Value *= 60; //0.3*60
	ptr->Min = (u32) local_f32Value;
	local_f32Value -= (f32) ptr->Min;
	local_f32Value *= 60;
	ptr->Sec = (u32) local_f32Value;

	result = (ptr->Hour) * 60 * 60 + (ptr->Min) * 60 + ptr->Sec;
	return result * tickspersec;
}

u32 SunCalc_u32SunsetTime(u32 Copy_u32DayID, sunset *ptr) {
	f32 local_f32DeclinationAngle;
	f32 local_f32SunsetAngle;
	f32 local_f32SunsetHour;
	f32 local_f32Value;
	u32 result;

	local_f32DeclinationAngle = 23.45
			* sin(degree * ((284 + Copy_u32DayID) * ((f32) 360 / 365)));
	local_f32SunsetAngle = (acos(
			-tan(degree * LATITUDE) * tan(degree * local_f32DeclinationAngle))
			/ (degree));
	local_f32SunsetHour = (12 + ((f32) local_f32SunsetAngle / 15));

	local_f32Value = local_f32SunsetHour;
	ptr->Hour = (u32) local_f32Value;
	local_f32Value -= (f32) ptr->Hour;
	local_f32Value *= 60;
	ptr->Min = (u32) local_f32Value;
	local_f32Value -= (f32) ptr->Min;
	local_f32Value *= 60;
	ptr->Sec = (u32) local_f32Value;

	result = (ptr->Hour) * 60 * 60 + (ptr->Min) * 60 + ptr->Sec;
	return result * tickspersec;
}

