/*
 * RCC_private.h
 *
 *  Created on: Sep 2, 2022
 *      Author: selim
 */
/*******************************************************************************************/
/* Author   :   SELIM MUHAMMED                                                             */
/* Date     :   2 SEP 2022                                                                 */
/* Version  :   V01                                                                        */
/*******************************************************************************************/
#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_

/*Register Definitions*/


typedef struct
{
u32 CR;
u32 PLLCFGR;
u32 CFGR;
u32 CIR;
u32 AHB1RSTR;
u32 AHB2RSTR;
u32 RESERVED_0;
u32 RESERVED_1;
u32 APB1RSTR;
u32 APB2RSTR;
u32 RESERVED_2;
u32 RESERVED_3;
u32 AHB1ENR;
u32 AHB2ENR;
u32 RESERVED_4;
u32 RESERVED_5;
u32 APB1ENR;
u32 APB2ENR;
u32 RESERVED_6;
u32 RESERVED_7;
u32 AHB1LPENR;
u32 AHB2LPENR;
u32 RESERVED_8;
u32 RESERVED_9;
u32 APB1LPENR;
u32 APB2LPENR;
u32 RESERVED_10;
u32 RESERVED_11;
u32 BDCR;
u32 CSR;
u32 RESERVED_12;
u32 RESERVED_13;
u32 SSCGR;
u32 PLLI2SCFGR;
u32 RESERVED_14;
u32 DCKCFGR;
}RCC_t;

#define     RCC                ((RCC_t*)0x40023800)
/*Clock Types*/
#define 	RCC_HSE_CRYSTAL     0
#define 	RCC_HSE_RC          1
#define     RCC_HSI             2
#define 	RCC_PLL             3


/*PLL Options*/
#define RCC_PLL_HSI      0
#define RCC_PLL_HSE      1

#endif /* RCC_PRIVATE_H_ */
