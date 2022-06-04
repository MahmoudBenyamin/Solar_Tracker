/*
 * SunCalc.h
 *
 *  Created on: Apr 28, 2022
 *      Author: Tarek
 */

#ifndef SUNCALC_H_
#define SUNCALC_H_



#define tickspersec 125
#define LATITUDE 30.0444 //cairo
#define degree   (M_PI/180)


typedef struct {
	u32 Hour;
	u32 Min;
	u32 Sec;
}sunrise,sunset;

extern sunrise*sunrise_ptr;
extern sunset* sunset_ptr;
extern sunrise rv;
extern sunset sv;

u32 SunCalc_u32SunriseTime(u32 Copy_u32DayID,sunrise*ptr);
u32 SunCalc_u32SunsetTime(u32 Copy_u32DayID,sunset*ptr);


#endif /* SUNCALC_H_ */
