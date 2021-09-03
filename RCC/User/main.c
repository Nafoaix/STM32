#include "stm32f10x.h"
#include "./LED/bsp_led.h"
#include "./RCC/bsp_clkcfg.h"

void delay (uint32_t count){
	for(;count > 0;count--);
}

int main(void)
{
	HSE_SetSysClk( RCC_PLLMul_9 );
	//HSI_SetSysClk( RCC_PLLMul_16 );
	
	LED_GPIO_Config();
	
	/* MCO clock output configuration */
	MCO_GPIO_CFG();
	RCC_MCOConfig(RCC_MCO_SYSCLK);
	
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
