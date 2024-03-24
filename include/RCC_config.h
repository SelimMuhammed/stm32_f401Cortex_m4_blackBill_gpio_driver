/*
 * RCC_config.h
 *
 *  Created on: Sep 2, 2022
 *      Author: selim
 */
/*******************************************************************************************/
/* Author   :   SELIM MUHAMMED                                                             */
/* Date     :   2 SEP 2022                                                                 */
/* Version  :   V01                                                                        */
/*******************************************************************************************/
#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

/* Options:
 *          RCC_HSE_CRYSTAL
	        RCC_HSE_RC
            RCC_HSI
	        RCC_PLL      */
#define  RCC_CLOCK_TYPE    RCC_HSE_CRYSTAL


/* Options:
 *          RCC_PLL_IN_HSI_DIV_2
 *          RCC_PLL_IN_HSE_DIV_2
 *          RCC_PLL_IN_HSE
	                       */
/* Note: Select value only if you have PLL as input Clock source*/
#if     RCC_CLOCK_TYPE  ==  RCC_PLL
#define  RCC_PLL_INPUT    RCC_HSE_CRYSTAL
#endif


/* Note: Select value only if you have PLL as input Clock source*/
#if     RCC_CLOCK_TYPE  ==  RCC_PLL
#define  RCC_PLL_MUL_VAL
#endif

#endif /* RCC_CONFIG_H_ */
