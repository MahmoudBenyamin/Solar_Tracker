/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "STD_TYPES.h"
#include  "BIT_MATH.h"
#include  "ECU.h"
#include  "Delay_interface.h"
#include  "RCC_interface.h"
#include  "GPIO_interface.h"
#include  "NVIC_interface.h"
#include  "ADC_interface.h"
#include  "ADC_config.h"
#include  "STK_interface.h"
#include  "motor_interface.h"
#include  "SunCalc.h"
#include  "TIM_interface.h"
// global variables
f32 Temp[4] = {0};
u32 DayCounter = 120 , SunRiseTicks = 0 , SunSetTicks =0;
sunrise*sunrise_ptr = NULL_PTR;
sunset* sunset_ptr = NULL_PTR;
sunrise rv;
sunset sv;
u8 Flag = 0;
void ECU_start(void)
{
		//ECU_vCompareLDR();
}
void SysInit(void)
{
	// start system clock 8MHz as per our calculations
	MRCC_vInitSystemCLK_Systick(AHB_Pre2);
	// Enable interrupts for timers
	MNVIC_vEnableINT(28);
	MNVIC_vEnableINT(29);
	MNVIC_vEnableINT(50);
	//enable clock for peripherals used
	MRCC_vEnableClock(AHB1_BUS, _PERIPHERAL_EN_GPIOA);
	MRCC_vEnableClock(APB2_BUS, PERIPHERAL_EN_ADC1);
	MRCC_vEnableClock(APB1_BUS, PERIPHERAL_EN_TIM2);
	MRCC_vEnableClock(APB1_BUS, PERIPHERAL_EN_TIM3);
	MRCC_vEnableClock(APB1_BUS, PERIPHERAL_EN_TIM5);
	//init and enable modules
	MADC_vInit();
	EnableFPU();
	TIM2_vInit();
	TIM3_vInit();
	TIM5_vInit();
	TIM2_vEnableCount(ARR_DAY);
	//set pins as we need
	SetPins();
	sunrise_ptr=&rv;
	sunset_ptr=&sv;
}
void SetPins(void)
{
	// set ADC pins as analog
	MGPIO_vSetPinMode(ADC_PORT , ADC_CHANNEL_1 , ANALOG);
	MGPIO_vSetPinPullType(GPIOA , ADC_CHANNEL_1 , NO_PULL);
	MGPIO_vSetPinMode(ADC_PORT , ADC_CHANNEL_2 , ANALOG);
	MGPIO_vSetPinPullType(GPIOA , ADC_CHANNEL_2 , NO_PULL);
	MGPIO_vSetPinMode(ADC_PORT , ADC_CHANNEL_3 , ANALOG);
	MGPIO_vSetPinPullType(GPIOA , ADC_CHANNEL_3 , NO_PULL);
	MGPIO_vSetPinMode(ADC_PORT , ADC_CHANNEL_4 , ANALOG);
	MGPIO_vSetPinPullType(GPIOA , ADC_CHANNEL_4 , NO_PULL);
	//set pins 8-16 as output for motors
	for(u8 i =8 ; i<16 ;i++)
	{
	MGPIO_vSetPinMode(GPIOA , i , GPOUPUT);
	MGPIO_vSetPinOutputType(GPIOA , i , PUSH_PULL);
	MGPIO_vSetPinOutputSpeed(GPIOA , i , LOW_SPEED);
	MGPIO_vSetPinPullType(GPIOA , i , NO_PULL);
	}
}
void BlinkPin(u8 PIN)
{
	MGPIO_vSetPinValueDirect(GPIOA , PIN ,SET);
	Delay_vUsIn16MHzint(1000);
	MGPIO_vSetPinValueDirect(GPIOA , PIN ,RESET);
	Delay_vUsIn16MHzint(1000);
}
void EnableFPU(void)
{
	//; CPACR is located at address 0xE000ED88
	asm("LDR.W R0, =0xE000ED88");
	//; Read CPACR
	asm("LDR R1, [R0]");
	//; Set bits 20-23 to enable CP10 and CP11 coprocessors
	asm("ORR R1, R1, #(0xF << 20)");
	//; Write back the modified value to the CPACR
	asm("STR R1, [R0]");
	//; wait for store to complete
	asm("DSB");
	//;reset pipeline now the FPU is enabled
	asm("ISB");
}
void ECU_vCompareLDR(void)
{
	MADC_vEnable();
    /* Loop forever */
	MADC_vStartConversion();
	MSTK_voidSetBusyWait( 5000);
	MADC_vJGetArray(Temp);
	if (Temp[0] > Temp[1])
	{
		MOTOR_vSetXPostion (1);
		MOTOR_vSetYPostion(4);
		MSTK_voidSetBusyWait( 1000);
	}
	else
	{
		MOTOR_vSetXPostion (2);
		MOTOR_vSetYPostion(3);
		MSTK_voidSetBusyWait( 1000);
	}
	if (Temp[2] > Temp[3])
	{
		MOTOR_vSetXPostion (3);
		MOTOR_vSetYPostion(2);
		MSTK_voidSetBusyWait( 1000);
	}
	else
	{
		MOTOR_vSetXPostion (4);
		MOTOR_vSetYPostion (1);
		MSTK_voidSetBusyWait( 1000);
	}
	MADC_vStopADC();
	MSTK_voidSetBusyWait( 5000);
}
void TIM2_vFunc(void)
{
	DayCounter++;
	SunRiseTicks =  SunCalc_u32SunriseTime(DayCounter,sunrise_ptr);
	SunSetTicks  =  SunCalc_u32SunsetTime(DayCounter,sunset_ptr);
	TIM5_vEnableCount(SunRiseTicks);
}
void TIM3_vFunc(void)
{
	ECU_vCompareLDR();
}
void TIM5_vFunc(void)
{
	//if (Flag == 0)
	//{
		TIM3_vEnableCount(STEP_ARR);
		//Flag++;
	//}
	/*else
	{
		TIM3_vDisableCount();
		Flag--;
	}*/
	//TIM5_vDisableCount();
	//TIM5_vEnableCount(SunSetTicks - SunRiseTicks);
}
void setCallBacks(void)
{
	TIM2_vSetCallBack(TIM2_vFunc);
	TIM3_vSetCallBack(TIM3_vFunc);
	TIM5_vSetCallBack(TIM5_vFunc);
}