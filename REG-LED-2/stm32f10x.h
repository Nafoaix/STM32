/* 用于存放寄存器映射的代码 */

/* 定义外设基地址 */
#define PERIPH_BASE ((unsigned int)0X40000000)

/* 总线基地址 */
#define APB1PERIPH_BASE PERIPH_BASE
#define APB2PERIPH_BASE (PERIPH_BASE + 0X00010000)
#define AHBPERIPH_BASE (PERIPH_BASE + 0X00018000)

/* GPIO外设基地址 */
#define GPIOA_BASE (APB2PERIPH_BASE + 0x0800)
#define GPIOB_BASE (APB2PERIPH_BASE + 0x0C00)
#define GPIOC_BASE (APB2PERIPH_BASE + 0x1000)
#define GPIOD_BASE (APB2PERIPH_BASE + 0x1400)

/* GPIOC端口寄存器基地址 */
#define GPIOC_CRL *(unsigned int *)(GPIOC_BASE + 0x00)
#define GPIOC_CRH *(unsigned int *)GPIOC_BASE + 0x04)
#define GPIOC_IDR *(unsigned int *)(GPIOC_BASE + 0x08)
#define GPIOC_ODR *(unsigned int *)(GPIOC_BASE + 0x0C)
#define GPIOC_BSRR *(unsigned int *)(GPIOC_BASE + 0x10)
#define GPIOC_BRR *(unsigned int *)(GPIOC_BASE + 0x14)
#define GPIOC_LCKR *(unsigned int *)(GPIOC_BASE + 0x18)


