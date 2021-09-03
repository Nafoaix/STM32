#include "./RCC/bsp_clkcfg.h"

void HSE_SetSysClk(uint32_t RCC_PLLMul)
{
	__IO uint32_t StartUpCounter = 0, HSEStatus = 0;
	/* reset RCC register to default */
	RCC_DeInit();
	
	/* Enable HSE */
	RCC_HSEConfig(RCC_HSE_ON);
	
	/* wait till HSE is ready */
	HSEStatus = RCC_WaitForHSEStartUp();
	
	/* HSE is ready */
	if( HSEStatus == SUCCESS )
	{
/*-------------------------------------------------------------*/
	/* Enable Prefetch Buffer */
    FLASH->ACR |= FLASH_ACR_PRFTBE;
	
  /* Flash 2 wait state 48Mhz<SYSCLK<72Mhz 010 2 wait state*/
    FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
    FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_2;    
/*-------------------------------------------------------------*/		
		/* HCLK = SYSCLK = 72M */
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
		/* PCLK1 = HCLK DIV2 = 36M */
		RCC_PCLK1Config(RCC_HCLK_Div2);
		/* PCLK = HCLK = 72M */
		RCC_PCLK2Config(RCC_HCLK_Div1);
		
		/* PLL configuration : chose PLL = HSE * 9 = 72MHz */
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1, RCC_PLLMul);
		
		/* Enable PLL */
		RCC_PLLCmd(ENABLE);
		
		/* wait till PLL is ready */
		while( RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET );
		
		/* Select PLL as system clock source */
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		
		/* wait till PLL is used as system clock source */
		while (RCC_GetSYSCLKSource() != 0x08);
		
	} else {
		/* If HSE fails to start-up , the application will have wrong clock configuration .
			 User can add here some code to deal with this error.
		*/
	}
	
}

void HSI_SetSysClk(uint32_t RCC_PLLMul)
{
	__IO uint32_t StartUpCounter = 0, HSIStatus = 0;
	
	/* reset RCC register to default */
	RCC_DeInit();
	
	/* Enable HSI */
	RCC_HSICmd(ENABLE);
	
	/* wait till HSI is ready */
	HSIStatus = RCC->CR & RCC_CR_HSIRDY;
	
	/* HSE is ready */
	if( HSIStatus == RCC_CR_HSIRDY )
	{
/*-------------------------------------------------------------*/
	/* Enable Prefetch Buffer */
    FLASH->ACR |= FLASH_ACR_PRFTBE;
	
  /* Flash 2 wait state 48Mhz<SYSCLK<72Mhz 010 2 wait state*/
    FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
    FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_2;    
/*-------------------------------------------------------------*/		
		/* HCLK = SYSCLK = 72M */
		RCC_HCLKConfig(RCC_SYSCLK_Div1);
		/* PCLK1 = HCLK DIV2 = 36M */
		RCC_PCLK1Config(RCC_HCLK_Div2);
		/* PCLK = HCLK = 72M */
		RCC_PCLK2Config(RCC_HCLK_Div1);
		
		/* PLL configuration : chose PLL = HSE * 9 = 72MHz */
		RCC_PLLConfig(RCC_PLLSource_HSI_Div2, RCC_PLLMul);
		
		/* Enable PLL */
		RCC_PLLCmd(ENABLE);
		
		/* wait till PLL is ready */
		while( RCC_GetFlagStatus(RCC_FLAG_PLLRDY) == RESET );
		
		/* Select PLL as system clock source */
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		
		/* wait till PLL is used as system clock source */
		while (RCC_GetSYSCLKSource() != 0x08);
		
	} else {
		/* If HSE fails to start-up , the application will have wrong clock configuration .
			 User can add here some code to deal with this error.
		*/
	}
	
}


void MCO_GPIO_CFG(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	
	/* 第一步：打开外设时钟 */
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	
	/* 第二步：配置外设初始化结构体 */
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	
	/* 第三步：调用外设初始化函数，把配置好的结构体成员写到寄存器里面 */
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
}

