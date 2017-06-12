#include "adc.h"

uint16_t ADC1_read(void)
 {
  ADC_RegularChannelConfig( ADC1 , ADC_Channel_1 , 1 , ADC_SampleTime_28Cycles5);
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);
	 while( ADC_GetFlagStatus (ADC1 , ADC_FLAG_EOC ) == RESET );
	 return ADC_GetConversionValue(ADC1);
 }
 
 uint16_t ADC2_read(void)
 {
  ADC_RegularChannelConfig( ADC2 , ADC_Channel_2 , 1 , ADC_SampleTime_28Cycles5);
	ADC_SoftwareStartConvCmd(ADC2, ENABLE);
	 while( ADC_GetFlagStatus (ADC2 , ADC_FLAG_EOC ) == RESET );
	 return ADC_GetConversionValue(ADC2);
 }
 
// uint16_t ADC3_read(void)
// {
//  ADC_RegularChannelConfig( ADC3 , ADC_Channel_1 , 1 , ADC_SampleTime_28Cycles5);
//	ADC_SoftwareStartConvCmd(ADC3, ENABLE);
//	 while( ADC_GetFlagStatus (ADC3 , ADC_FLAG_EOC ) == RESET );
//	 return ADC_GetConversionValue(ADC3);
// }