#include "stm32f10x.h"


void soft_delay (unsigned int count)
{
	for( ; count > 0; count-- );
}

int main (void)
{
	/* 配置RCC寄存器，使能GPIO口的时钟 */
	*(unsigned int *)0X40021018 |= ( 1<<4 );
	
	/* 配置CRL寄存器，配置为推挽输出 */
	GPIOC_CRL |= ( 1<<(4*2) );
	GPIOC_CRL |= ( 1<<(4*3) );
	/* 配置ODR寄存器，设置GPIO端口C第2位和第3位为低电平 */
	GPIOC_ODR &= ~( 1<<2 );
	GPIOC_ODR &= ~( 1<<3 );
	
	while(1)
	{
		GPIOC_ODR &= ~( 1<<2 );
		soft_delay(0xfffff);
		
		GPIOC_ODR |= ( 1<<2 );
		soft_delay(0xfffff);
	}
}

void SystemInit (void)
{
	
}
