#include "stm32f10x.h"
#include "./LED/bsp_led.h"
#include "./KEY/bsp_key.h"

void delay (uint32_t count){
	for(;count > 0;count--);
}
int main(void)
{
	LED_GPIO_Config();
	KEY_GPIO_Config();
	
	while(1)
	{
		if(KEY_Scan(KEY1_GPIO_PORT,KEY1_GPIO_PIN) == KEY_ON)
		{ 
			LED1_TOGGLE
		}
		if(KEY_Scan(KEY2_GPIO_PORT,KEY2_GPIO_PIN) == KEY_ON)
		{
			LED2_TOGGLE
		}
	}
}
