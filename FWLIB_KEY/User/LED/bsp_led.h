#ifndef __BSP_LED_H
#define __BSP_LED_H

#include "stm32f10x.h"

#define digitalTOGGLE(p,i)  {p->ODR ^= i;}
#define LED1_TOGGLE         digitalTOGGLE(GPIOC,GPIO_Pin_2)
#define LED2_TOGGLE         digitalTOGGLE(GPIOC,GPIO_Pin_3)

void LED_GPIO_Config(void);

#endif /* __BSP_LED_H */
