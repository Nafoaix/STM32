#include "stm32f10x.h"
#include "./LED/bsp_led.h"

void delay (uint32_t count){
	for(;count > 0;count--);
}
int main(void)
{
	LED_GPIO_Config();
	while(1)
	{
		GPIO_ResetBits(GPIOC,GPIO_Pin_2);
		delay(0xffffff);
		GPIO_SetBits(GPIOC,GPIO_Pin_2);
		delay(0xffffff);
		
		GPIO_ResetBits(GPIOC,GPIO_Pin_3);
		delay(0xffffff);
		GPIO_SetBits(GPIOC,GPIO_Pin_3);
		delay(0xffffff);
	}
}
