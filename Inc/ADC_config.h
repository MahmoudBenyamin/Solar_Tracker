/*======================================================================================
========================    - ADC_config.h					 ===========================
========================    - Created: 24/4/2022			     ===========================
========================    - Author: Mahmoud_Benyamin       ===========================
========================    - Version : _1_				     ===========================
========================    - Note :
									*-
									*-
=======================================================================================*/ 


/*====================================================================================
	- The Optiones Which Developer Choose From Which What Is Appropriate To App
=====================================================================================*/

/*=======================================================================================
=====================     guard of file will call on time in .c  	=====================
=========================================================================================*/
#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H
/*choose ADC prescaler options :
								-ADC_PRE_DIV_2
								-ADC_PRE_DIV_4
								-ADC_PRE_DIV_6
								-ADC_PRE_DIV_8 
								*/
#define ADC_PRESCALER 		ADC_PRE_DIV_2
/***************************************************/
/*choose ADC resolution options :
								-ADC_RESOLUTION_12_BIT
								-ADC_RESOLUTION_10_BIT
								-ADC_RESOLUTION_08_BIT
								-ADC_RESOLUTION_06_BIT 
								*/

#define ADC_RESOLUTION  	ADC_RESOLUTION_12_BIT
/***************************************************/
/*choose ADC scan mode options :
								-ENABLE
								-DISABLE
								*/
#define ADC_SCAN_MODE           ENABLE
/***************************************************/
/*Enable end of conversion interrupt :
								-ENABLE
								-DISABLE
								*/
#define ADC_EOCIE_MODE           DISABLE
#define ADC_JEOCIE_MODE			 DISABLE
/***************************************************/
/*choose ADC external event select for regular group options :
								-MADC_EXT_TIMER1_CC1_EVENT
								-MADC_EXT_TIMER1_CC2_EVENT
								-MADC_EXT_TIMER1_CC3_EVENT
								-MADC_EXT_TIMER2_CC2_EVENT
								-MADC_EXT_TIMER2_CC3_EVENT
								-MADC_EXT_TIMER2_CC4_EVENT
								-MADC_EXT_TIMER2_TRGO_EVEN
								-MADC_EXT_TIMER3_CC1_EVENT
								-MADC_EXT_TIMER3_TRGO_EVEN
								-MADC_EXT_TIMER4_CC4_EVENT
								-MADC_EXT_TIMER5_CC1_EVENT
								-MADC_EXT_TIMER5_CC2_EVENT
								-MADC_EXT_TIMER5_CC3_EVENT
								-MADC_EXT_EXTI_lINE11     
								*/
#define ADC_EXT_EVENT  			MADC_EXT_TIMER1_CC1_EVENT
/***************************************************/
/*Enable external trigger for regular and injected channels options:
								-MADC_EXT_TRIGGER_DETECTION_DISABLED
								-MADC_EXT_TRIGGER_DETECTION_RISING  
								-MADC_EXT_TRIGGER_DETECTION_FALLING 
								-MADC_EXT_TRIGGER_DETECTION_BOTH    
								-MADC_EXT_TIMER2_CC3_EVENT    
								*/

#define ADC_EXTERNAL_TRIGGER     MADC_EXT_TRIGGER_DETECTION_DISABLED
#define ADC_JEXTERNAL_TRIGGER    MADC_EXT_TRIGGER_DETECTION_DISABLED
/***************************************************/
/*data alignment options:
								-MADC_RIGHT_ALIGNED
								-MADC_LEFT_ALIGNED     
								*/
#define ADC_DATA_ALIGNMENT       MADC_RIGHT_ALIGNED
/***************************************************/
/*DMA mode options :
								-ENABLE
								-DISABLE
								*/
#define ADC_DMA_MODE            ENABLE
/***************************************************/

/*DDS mode options :
								-ENABLE
								-DISABLE
								*/
#define ADC_DDS_MODE            ENABLE
/***************************************************/
/*EOCS mode options :
								-ENABLE
								-DISABLE
								*/
#define ADC_EOCS_MODE            DISABLE
/***************************************************/
/***************************************************/
/*Discontinuous mode options :
								-ENABLE
								-DISABLE
								*/
#define ADC_DISC_MODE            DISABLE
#define ADC_JDISC_MODE           DISABLE
/*number of discontinous channels min0 max 7*/

#define ADC_DISC_CHANN_NUM		0U
/***************************************************/
/*Conversion mode options :
								-MADC_SINGLE_CONVERSION   
								-MADC_CONTINOUS_CONVERSION
								*/
#define ADC_CONVERSION_MODE      MADC_SINGLE_CONVERSION
/***************************************************/
/* Number of channels used min 1 max 18*/
#define ADC_NUM_CHANNELS_USED 		3U
/*  channels used min 1 max 16*/
#define ADC_PORT		GPIOA
#define ADC_CHANNEL_1	0U
#define ADC_CHANNEL_2	1U
#define ADC_CHANNEL_3	2U
#define ADC_CHANNEL_4	3U
/***************************************************/
/* setting sampling time for chanells options 
								-MADC_SAMPLING_3_CYCLES   
								-MADC_SAMPLING_15_CYCLES  
								-MADC_SAMPLING_28_CYCLES  
								-MADC_SAMPLING_56_CYCLES  
								-MADC_SAMPLING_84_CYCLES  
								-MADC_SAMPLING_112_CYCLES 
								-MADC_SAMPLING_144_CYCLES 
								-MADC_SAMPLING_480_CYCLES
								*/
#define ADC_CHANNEL_1_SAMPLING   MADC_SAMPLING_3_CYCLES
#define ADC_CHANNEL_2_SAMPLING   MADC_SAMPLING_3_CYCLES
#define ADC_CHANNEL_3_SAMPLING   MADC_SAMPLING_3_CYCLES
#define ADC_CHANNEL_4_SAMPLING   MADC_SAMPLING_3_CYCLES
/****************************************************/
/* ADC injected auto mode    */
#define ADC_JAUTO_MODE			ENABLE
/*choose ADC injected external event select for regular group options :
								-MADC_JEXT_TIMER_1_CC4_EVENT
								-MADC_JEXT_TIMER_1_TRGO_EVENT
								-MADC_JEXT_TIMER_2_CC1_EVENT
								-MADC_JEXT_TIMER_2_TRGO_EVENT
								-MADC_JEXT_TIMER_3_CC2_EVENT
								-MADC_JEXT_TIMER_3_CC4_EVENT
								-MADC_JEXT_TIMER_4_CC1_EVENT
								-MADC_JEXT_TIMER_4_CC2_EVENT
								-MADC_JEXT_TIMER_4_CC3_EVENT
								-MADC_JEXT_TIMER_4_TRGO_EVENT
								-MADC_JEXT_TIMER_5_CC4_EVENT
								-MADC_JEXT_TIMER_5_TRGO_EVENT
								-MADC_JEXT_EXTI_LINE15
								*/
#define ADC_JEXT_EVENT  			MADC_JEXT_TIMER_1_TRGO_EVENT


#define ADC_USE_REGULAR_MODE	DISABLE
#define ADC_USE_INJECTED_MODE   ENABLE






#endif
