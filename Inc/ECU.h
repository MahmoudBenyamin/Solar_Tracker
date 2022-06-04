/*
 * ECU.h
 *
 *  Created on: Apr 28, 2022
 *      Author: mahmo
 */
#include "STD_TYPES.h"
#ifndef ECU_H_
#define ECU_H_
extern u32 DayCounter , SunRiseTicks , SunSetTicks;
extern u8 Flag;
void SysInit(void);
void SetPins(void);
void BlinkPin(u8 PIN);
void EnableFPU(void);
void ECU_start(void);
void ECU_vCompareLDR(void);
void TIM2_vFunc(void);
void TIM3_vFunc(void);
void TIM5_vFunc(void);
void setCallBacks(void);
#endif /* ECU_H_ */
