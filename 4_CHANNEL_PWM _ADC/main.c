#include "stm32f10x.h"                  // Device header
#include "gpio.h"
#include "adc.h"
#include "pwm.h"
#include "delay.h"

float ADC1_value , ADC2_value , ADC3_value;
void gpio_set(void) ;

int main() 
{
gpio_set();
while(1)
{
	ADC1_value=1212*0.000805*ADC1_read();
  pwm_pulse(ADC1_value,1);
	ADC2_value=1212*0.000805*ADC2_read();
  pwm_pulse(ADC2_value,2);
//	ADC3_value=ADC3_read()/1000;
 // pwm_pulse(ADC3_value);
	
}	
}

