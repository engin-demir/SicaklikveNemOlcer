#include "pwm.h"
#include "gpio.h"
#include "adc.h"
#include "main.h"
void pwm_pulse(float value , int channel_number)
{
	if(channel_number == 1)
	{
	  TIM4 -> CCR3 = value;
	}
  if( channel_number == 2)
	{
	TIM4 -> CCR4 = value;
	}
//TIM_OCInitStructure.TIM_Pulse = value;	
}
