#include "stm32f10x.h" 

void gpio_set(void);
 // MACROS
# define RED_LED_ON()    GPIO_SetBits(GPIOB,GPIO_Pin_8)
# define RED_LED_OFF()   GPIO_ResetBits(GPIOB,GPIO_Pin_8)
# define BLUE_LED_ON()    GPIO_SetBits(GPIOB,GPIO_Pin_9)
# define BLUE_LED_OFF()   GPIO_ResetBits(GPIOB,GPIO_Pin_9)