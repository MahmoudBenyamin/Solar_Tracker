/*=======================================================================================
============================   - ADC_program.c				 ============================
============================   - Created: 24/4/2022			 ============================
============================   - Author: Mahmoud_Benyamin    ============================
============================   - Version : _1_				 ============================
============================   - Note :  
									     *-
									     *-
=======================================================================================*/ 


/*=======================================================================================
============================   The Foundation Of Function   ============================= 
=========================================================================================*/

/*===========   INCLUDE LIB   ===========*/
		 #include "STD_TYPES.h"
		 #include "BIT_MATH.h"
		 #include "Delay_interface.h"
/*======================================*/	 
/*===========  INCLUDE MCAL  ===========*/
		#include "ADC_interface.h"
		#include "ADC_private.h"
		#include "ADC_config.h"
/*======================================*/	
/*===========  INCLUDE HAL   ===========*/
			

/*======================================*/	

/*===========  INCLUDEAPP   ===========*/

/*=====================================*/	
void MADC_vInit(void)
{
	// set the prescaler
	ADC_COMM_REG &= ~ ( 0b11 << 16);
	ADC_COMM_REG |= (ADC_PRESCALER << 16);

	//set ADC Resolution
	ADC -> CR1.RES =ADC_RESOLUTION;
	//Discontinuous mode
	ADC -> CR1.DISCEN = ADC_DISC_MODE;
	ADC -> CR1.JDISCEN= ADC_JDISC_MODE;
	ADC -> CR1.DISCNUM= ADC_DISC_CHANN_NUM;
	// scan mode
	ADC -> CR1.SCAN = ADC_SCAN_MODE;
	// EOCIE and JEOCIE MODE
	ADC -> CR1.EOCIE = ADC_EOCIE_MODE;
	ADC -> CR1.JEOCIE = ADC_JEOCIE_MODE;
	// setting external trigger mode and event
	ADC -> CR2.EXTEN = ADC_EXTERNAL_TRIGGER;
	ADC -> CR2.JEXTEN =ADC_JEXTERNAL_TRIGGER;
	ADC -> CR2.EXTSEL = ADC_EXT_EVENT;
	ADC -> CR2.JEXTSEL =ADC_JEXT_EVENT;
	// choosing data alignment
	ADC -> CR2.ALIGN  = ADC_DATA_ALIGNMENT;
	// CHOOSING DMA , DDS , ECOS
	ADC -> CR2.DMA  = ADC_DMA_MODE;
	ADC -> CR2.DDS  = ADC_DDS_MODE;
	ADC -> CR2.EOCS  = ADC_EOCS_MODE;
	ADC -> CR2.CONT  = ADC_CONVERSION_MODE;
	//choosing auto mode for injected channels
	ADC -> CR1.JAUTO = ADC_JAUTO_MODE;
	#if (ADC_USE_REGULAR_MODE == ENABLE)
		//setting number of channels in the sequencer
		ADC -> SQR1 |= (ADC_NUM_CHANNELS_USED << 20);
		//setting the sequencer channels
		ADC ->SQR3 |= (ADC_CHANNEL_1<<0);  // SEQ1 for Channel 1
		ADC ->SQR3 |= (ADC_CHANNEL_2<<5);  // SEQ2 for CHannel 2
		ADC ->SQR3 |= (ADC_CHANNEL_3<<10); // SEQ1 for Channel 3
		ADC ->SQR3 |= (ADC_CHANNEL_4<<15); // SEQ2 for CHannel 4
	#elif	(ADC_USE_INJECTED_MODE == ENABLE)
		/* making all offset registers = 0 */
		ADC ->JOFR1 = 0;
		ADC ->JOFR2 = 0;
		ADC ->JOFR3 = 0;
		ADC ->JOFR4 = 0;
		/* setting the sequence */
		ADC ->JSQR |= (ADC_NUM_CHANNELS_USED << 20);
		ADC ->JSQR |= (ADC_CHANNEL_1<<0);  // SEQ1 for Channel 1
		ADC ->JSQR |= (ADC_CHANNEL_2<<5);  // SEQ2 for CHannel 2
		ADC ->JSQR |= (ADC_CHANNEL_3<<10); // SEQ1 for Channel 3
		ADC ->JSQR |= (ADC_CHANNEL_4<<15); // SEQ2 for CHannel 4
	#else
		/*error*/
	#endif
		// Choosing sampling time for ADC channels */
	ADC ->SMPR2 |= (ADC_CHANNEL_1_SAMPLING<<0); // Sampling for Channel 1
	ADC ->SMPR2 |= (ADC_CHANNEL_2_SAMPLING<<3); // Sampling for CHannel 2
	ADC ->SMPR2 |= (ADC_CHANNEL_3_SAMPLING<<6); // Sampling for Channel 3
	ADC ->SMPR2 |= (ADC_CHANNEL_4_SAMPLING<<9); // Sampling for CHannel 4
}
void MADC_vEnable(void)
{
	ADC -> CR2.ADON = 1;
	Delay_vUsIn16MHzint(10);
}
void MADC_vStartConversion(void)
{
	ADC->SR = 0;
	ADC -> CR2.JSWSTART = 1;
	ADC -> CR2.SWSTART  = 1;
}
u16 MADC_u16GetValue(void)
{
	u16 L_u16Temp = 0;
	while (GET_BIT(ADC -> SR,1) == 0);
	L_u16Temp = ADC -> DR;
	L_u16Temp = (L_u16Temp * 5 ) / 4096;
	return L_u16Temp;
}
void MADC_vGetArray(u16* p)
{
	for (int var = 0; var < (ADC_NUM_CHANNELS_USED+1); var++) {
		p[var] = MADC_u16GetValue();
	}
}
void MADC_vJGetArray(f32* p)
{
	while (GET_BIT(ADC -> SR,2) == 0);
	for (u8 var = 0; var < (ADC_NUM_CHANNELS_USED+1); var++) {
		p[var] = ADC ->JDR[var];
		p[var] = (p[var] * 5.0 ) / (f32) 4096;
	}
}
void MADC_vStopADC(void)
{
	ADC -> CR2.JSWSTART = 0;
	ADC -> CR2.SWSTART  = 0;
	ADC -> CR2.ADON     = 0;
	Delay_vUsIn16MHzint(10);
}
void ADC1_IRQHandler(void)
{


}
