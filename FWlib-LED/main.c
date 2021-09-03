#include "stm32f10x.h"
#include "stm32f10x_gpio.h"

void SystemInit (void)
{
	
}

void soft_delay (unsigned int count)
{
	for( ; count > 0; count-- );
}

int main (void)
{
	/* 配置RCC寄存器，使能GPIO口的时钟 */
	*(unsigned int *)0X40021018 |= ( 1<<4 );
	
	/* GPIO初始化 */
	GPIO_InitTypeDef GPIO_InitStruct1;
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStruct1.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct1.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct1);
	
	GPIO_InitTypeDef GPIO_InitStruct2;
	GPIO_InitStruct1.GPIO_Pin = GPIO_Pin_3;
	GPIO_InitStruct2.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct2.GPIO_Speed = GPIO_Speed_10MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct1);
	/* 配置ODR寄存器，设置GPIO端口C第2位和第3位为低电平 */
	GPIO_ResetBits(GPIOC, GPIO_Pin_2);
	GPIO_ResetBits(GPIOC, GPIO_Pin_3);

	while(1)
	{
		GPIO_ResetBits(GPIOC, GPIO_Pin_3);
		soft_delay(0xfffff);
		GPIO_SetBits(GPIOC, GPIO_Pin_3);
		soft_delay(0xfffff);
	}
}

