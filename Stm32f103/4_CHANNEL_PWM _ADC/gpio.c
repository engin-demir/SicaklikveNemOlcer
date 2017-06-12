#include "gpio.h"
#include "adc.h"
void gpio_set(void) 
{
  GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;
	ADC_InitTypeDef ADC_InitStructure;
	// enable clock
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4 , ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1 | RCC_APB2Periph_ADC2 | RCC_APB2Periph_ADC3, ENABLE);
   
	GPIO_InitStructure.GPIO_Mode =  GPIO_Mode_AF_PP; //GPIO_Mode_Out_PP
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8 | GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitStructure);
	
	// ADC Input Congif
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5| GPIO_Pin_6 | GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);	
	
	// ADC Config 12 bitlik ceviri yapiyor
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	ADC_InitStructure.ADC_ScanConvMode = DISABLE;
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;
	ADC_InitStructure.ADC_ExternalTrigConv  =   ADC_ExternalTrigConv_None;
	ADC_InitStructure.ADC_DataAlign  = ADC_DataAlign_Right;
	ADC_InitStructure.ADC_NbrOfChannel  = 15;
	ADC_Init(ADC1 , &ADC_InitStructure);
	ADC_Cmd(ADC1 , ENABLE );
	ADC_Init(ADC2 , &ADC_InitStructure);
	ADC_Cmd(ADC2 , ENABLE );
	//ADC_Init(ADC3 , &ADC_InitStructure);
	//ADC_Cmd(ADC3 , ENABLE );
	
	
	// 1s lik Timer 
	TIM_TimeBaseInitStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitStructure.TIM_Period = 4000;
	TIM_TimeBaseInitStructure.TIM_Prescaler = 18000;
	TIM_TimeBaseInitStructure.TIM_RepetitionCounter = 1;
	TIM_TimeBaseInit(TIM4,&TIM_TimeBaseInitStructure);
	
	
	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	
	//channel 3
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 2; //% 25 duty 
	TIM_OC3Init(TIM4,&TIM_OCInitStructure); //OC3 = CCR3
	TIM_OC3PreloadConfig(TIM4,TIM_OCPreload_Enable);
	
	//channel 4
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 4; //% 75 duty 
	TIM_OC4Init(TIM4,&TIM_OCInitStructure);
	TIM_OC4PreloadConfig(TIM4,TIM_OCPreload_Enable);
	
	
	TIM_ARRPreloadConfig(TIM4 , ENABLE );
	TIM_Cmd(TIM4, ENABLE);
	

}