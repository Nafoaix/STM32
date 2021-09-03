#ifndef __BSP_CLKCFG_H
#define __BSP_CLKCFG_H

#include "stm32f10x.h"

void HSE_SetSysClk(uint32_t RCC_PLLMul);
void MCO_GPIO_CFG(void);
void HSI_SetSysClk(uint32_t RCC_PLLMul);

#endif /* __BSP_CLKCFG_H */

