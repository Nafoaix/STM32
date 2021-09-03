#include "./LED/bsp_led.h"
// bsp board support package 板级支持包

void LED_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* 第一步：打开外设时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	/* 第二步：配置外设初始化结构体 */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_2;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_10MHz;
	
	/* 第三步：调用外设初始化函数，把配置好的结构体成员写到寄存器里面 */
	GPIO_Init(GPIOC, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3;
	GPIO_Init(GPIOC, &GPIO_InitStruct);
}
