/*
 * RCC_program.c
 *
 *  Created on: Sep 11, 2022
 *      Author: selim
 */
/*******************************************************************************************/
/* Author   :   SELIM MUHAMMED                                                             */
/* Date     :   2 SEP 2022                                                                 */
/* Version  :   V01                                                                        */
/*******************************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidInitSysClock(void)
{
     #if RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	     RCC->CR = 0X00010000; /*Enable HSE with No Bypass*/
	     RCC->CFGR = 0X00000001;

     #elif RCC_CLOCK_TYPE == RCC_HSE_RC
	     RCC->CR = 0X00050000; /*Enable HSE with Bypass*/
	     RCC->CFGR = 0X00000001;

     #elif RCC_CLOCK_TYPE == RCC_HSI
	     RCC->CR = 0X00000081; /*Enable HSI + Trimming = 0*/
	     RCC->CFGR = 0X00000000;

     #elif RCC_CLOCK_TYPE == RCC_PLL
	     RCC->CR=   0x01000000;

	     		#if RCC_CLOCK_PLL_INPUT == RCC_PLL_HSI
	     		    RCC->PLLCFGR= //0 on bit 22
	     		#elif RCC_CLOCK_PLL_INPUT == RCC_PLL_HSE
	     		    RCC->PLLCFGR= //1 on bit 22
	     		#else
	     		    #error "WRONG INPUT"
	     		#endif
    #else

	#endif
}
void RCC_voidEnableClock(u8 Copy_u8PerId)
{
	if(Copy_u8PerId <=127)
	{
		switch (Copy_u8PerId)
		{
		case RCC_GPIOA:
		case RCC_GPIOB:
		case RCC_GPIOC:
		case RCC_GPIOD:
		case RCC_GPIOE:
		case RCC_GPIOH:
		case RCC_CRC:
		case RCC_DMA1:
		case RCC_DMA2:
		SET_BIT(RCC->AHB1ENR, Copy_u8PerId);break;

		case RCC_OTGFS: SET_BIT(RCC->AHB2ENR, (Copy_u8PerId % 32));break;

		case RCC_TIM2:
		case RCC_TIM3:
		case RCC_TIM4:
		case RCC_TIM5:
		case RCC_WWDG:
		case RCC_SPI2:
		case RCC_SPI3:
		case RCC_USART_2:
		case RCC_I2C1:
		case RCC_I2C2:
		case RCC_I2C3:
		case RCC_PWR:
		SET_BIT(RCC->APB1ENR, (Copy_u8PerId % 64));break;

		case RCC_TIM1:
		case RCC_USART1:
		case RCC_USART6:
		case RCC_ADC1:
		case RCC_SDIO:
		case RCC_SPI1:
		case RCC_SPI4:
		case RCC_SYSCFG:
		case RCC_TIM9:
		case RCC_TIM10:
		case RCC_TIM11:
		SET_BIT(RCC->APB2ENR, (Copy_u8PerId % 96));break;
		default:
		        #if DET_INIT==1
			DET_ReportError(RCC_MODULE_ID, InvalidBusId, RCC_EnablePeripheralClockFunctionId);
                #endif
		break;
		}

	}

}
void RCC_voidDisableClock(u8 Copy_u8PerId)
{
	if(Copy_u8PerId <=127)
		{
			switch (Copy_u8PerId)
			{
			case RCC_GPIOA:
			case RCC_GPIOB:
			case RCC_GPIOC:
			case RCC_GPIOD:
			case RCC_GPIOE:
			case RCC_GPIOH:
			case RCC_CRC:
			case RCC_DMA1:
			case RCC_DMA2:
			CLR_BIT(RCC->AHB1ENR, Copy_u8PerId);break;

			case RCC_OTGFS: CLR_BIT(RCC->AHB2ENR, (Copy_u8PerId % 32));break;

			case RCC_TIM2:
			case RCC_TIM3:
			case RCC_TIM4:
			case RCC_TIM5:
			case RCC_WWDG:
			case RCC_SPI2:
			case RCC_SPI3:
			case RCC_USART_2:
			case RCC_I2C1:
			case RCC_I2C2:
			case RCC_I2C3:
			case RCC_PWR:
			CLR_BIT(RCC->APB1ENR, (Copy_u8PerId % 64));break;

			case RCC_TIM1:
			case RCC_USART1:
			case RCC_USART6:
			case RCC_ADC1:
			case RCC_SDIO:
			case RCC_SPI1:
			case RCC_SPI4:
			case RCC_SYSCFG:
			case RCC_TIM9:
			case RCC_TIM10:
			case RCC_TIM11:
			CLR_BIT(RCC->APB2ENR, (Copy_u8PerId % 96));break;
			default:
			        #if DET_INIT==1
				DET_ReportError(RCC_MODULE_ID, InvalidBusId, RCC_EnablePeripheralClockFunctionId);
	                #endif
			break;
			}

		}

}




