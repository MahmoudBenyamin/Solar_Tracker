/*======================================================================================
===========================   - ADC_interface.h			     ===========================
===========================   - Created: 24/4/2022			 ===========================
===========================   - Author: Mahmoud_Benyamin     ===========================
===========================   - Version : _1_				 ===========================
===========================   - Note :
									  *-
									  *-
 ======================================================================================*/ 

/*=====================================================================================
		* What i sell To Customer
		*  The Archictect Give The API	
						- The Name Of Function 
						- What is The Input 
						- What Is The Output
						- Macro 
						 
======================================================================================*/ 

/*===================================================================================
===============     guard of file will call on time in .c		   ==================
=====================================================================================*/
#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

void MADC_vInit(void);
void MADC_vEnable(void);
void MADC_vStartConversion(void);
u16 MADC_u16GetValue(void);
void MADC_vGetArray(u16* p);
void MADC_vJGetArray(f32* p);
void MADC_vStopADC(void);
/* ADC prescaler options */
/***************************************************/
#define ADC_PRE_DIV_2		0b00
#define ADC_PRE_DIV_4		0b01
#define ADC_PRE_DIV_6		0b10
#define ADC_PRE_DIV_8		0b11
/***************************************************/


/*  ADC resoltion options */
/***************************************************/
#define ADC_RESOLUTION_12_BIT	0b00
#define ADC_RESOLUTION_10_BIT	0b01
#define ADC_RESOLUTION_08_BIT	0b10
#define ADC_RESOLUTION_06_BIT	0b11
/***************************************************/

#define ENABLE        1U
#define DISABLE       0U
/****************************************************/
/* External event select for regular group */
#define MADC_EXT_TIMER1_CC1_EVENT    0b0000   
#define MADC_EXT_TIMER1_CC2_EVENT    0b0001   
#define MADC_EXT_TIMER1_CC3_EVENT    0b0010   
#define MADC_EXT_TIMER2_CC2_EVENT    0b0011   
#define MADC_EXT_TIMER2_CC3_EVENT    0b0100   
#define MADC_EXT_TIMER2_CC4_EVENT    0b0101   
#define MADC_EXT_TIMER2_TRGO_EVENT   0b0110        
#define MADC_EXT_TIMER3_CC1_EVENT    0b0111   
#define MADC_EXT_TIMER3_TRGO_EVENT   0b1000       
#define MADC_EXT_TIMER4_CC4_EVENT    0b1001   
#define MADC_EXT_TIMER5_CC1_EVENT    0b1010   
#define MADC_EXT_TIMER5_CC2_EVENT    0b1011   
#define MADC_EXT_TIMER5_CC3_EVENT    0b1100                  
#define MADC_EXT_EXTI_lINE11         0b1111   

/***************************************************/
/* External trigger enable for regular channels */
#define MADC_EXT_TRIGGER_DETECTION_DISABLED    0b00
#define MADC_EXT_TRIGGER_DETECTION_RISING      0b01    
#define MADC_EXT_TRIGGER_DETECTION_FALLING     0b10     
#define MADC_EXT_TRIGGER_DETECTION_BOTH        0b11    
/***************************************************/
/* alignment in data register */
#define MADC_RIGHT_ALIGNED       0U
#define MADC_LEFT_ALIGNED        1U
/***************************************************/
/* Choosing conversion mode */
#define MADC_SINGLE_CONVERSION         0U
#define MADC_CONTINOUS_CONVERSION      1U
/***************************************************/
/* sampling options : */
#define MADC_SAMPLING_3_CYCLES         0b000
#define MADC_SAMPLING_15_CYCLES        0b001
#define MADC_SAMPLING_28_CYCLES        0b010
#define MADC_SAMPLING_56_CYCLES        0b011
#define MADC_SAMPLING_84_CYCLES        0b100
#define MADC_SAMPLING_112_CYCLES       0b101
#define MADC_SAMPLING_144_CYCLES       0b110
#define MADC_SAMPLING_480_CYCLES       0b111
/***************************************************/
#define MADC_JEXT_TIMER_1_CC4_EVENT 			  (0b0000)
#define MADC_JEXT_TIMER_1_TRGO_EVENT			  (0b0001)
#define MADC_JEXT_TIMER_2_CC1_EVENT 			  (0b0010)
#define MADC_JEXT_TIMER_2_TRGO_EVENT			  (0b0011)
#define MADC_JEXT_TIMER_3_CC2_EVENT 			  (0b0100)
#define MADC_JEXT_TIMER_3_CC4_EVENT 			  (0b0101)
#define MADC_JEXT_TIMER_4_CC1_EVENT 			  (0b0110)
#define MADC_JEXT_TIMER_4_CC2_EVENT 			  (0b0111)
#define MADC_JEXT_TIMER_4_CC3_EVENT 			  (0b1000)
#define MADC_JEXT_TIMER_4_TRGO_EVENT			  (0b1001)
#define MADC_JEXT_TIMER_5_CC4_EVENT 			  (0b1010)
#define MADC_JEXT_TIMER_5_TRGO_EVENT			  (0b1011)
#define MADC_JEXT_EXTI_LINE15					  (0b1111)









#endif
