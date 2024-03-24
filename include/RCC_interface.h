/*
 * RCC_interface.h
 *
 *  Created on: Sep 2, 2022
 *      Author: selim
 */
/*******************************************************************************************/
/* Author   :   SELIM MUHAMMED                                                             */
/* Date     :   2 SEP 2022                                                                 */
/* Version  :   V01                                                                        */
/*******************************************************************************************/
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_
#include "STD_TYPES.h"

/*DET RCC ERROR ID*/
typedef enum
{
	InvalidBusId,
	InvalidPeripheralId,
}RCC_errorId_E;

/*DET RCC FUNCTIONS IDs  */
typedef enum
{
	RCC_initFunctionId,
	RCC_EnablePeripheralClockFunctionId,
	RCC_DisablePeripheralClockFunctionId,
}RCC_functionId_E;



typedef enum
{
	RCC_GPIOA,
	RCC_GPIOB,
	RCC_GPIOC,
	RCC_GPIOD,
	RCC_GPIOE,
	RCC_unused_5,
	RCC_unused_6,
	RCC_GPIOH,
	RCC_unused_8,
	RCC_unused_9,
	RCC_unused_10,
	RCC_unused_11,
	RCC_CRC,
	RCC_unused_13,
    RCC_unused_14,
    RCC_unused_15,
    RCC_unused_16,
	RCC_unused_17,
	RCC_unused_18,
	RCC_unused_19,
	RCC_unused_20,
	RCC_DMA1,
	RCC_DMA2,
	RCC_unused_23,
	RCC_unused_24,
	RCC_unused_25,
	RCC_unused_26,
	RCC_unused_27,
	RCC_unused_28,
	RCC_unused_29,
	RCC_unused_30,
	RCC_unused_31,
	RCC_unused_32,
    RCC_unused_33,
    RCC_unused_34,
    RCC_unused_35,
    RCC_unused_36,
	RCC_unused_37,
	RCC_unused_38,
	RCC_OTGFS,
	RCC_unused_40,
	RCC_unused_41,
	RCC_unused_42,
	RCC_unused_43,
	RCC_unused_44,
	RCC_unused_45,
	RCC_unused_46,
	RCC_unused_47,
	RCC_unused_48,
	RCC_unused_49,
    RCC_unused_50,
	RCC_unused_51,
	RCC_unused_52,
	RCC_unused_53,
	RCC_unused_54,
	RCC_unused_55,
	RCC_unused_56,
	RCC_unused_57,
	RCC_unused_58,
	RCC_unused_59,
	RCC_unused_60,
	RCC_unused_61,
	RCC_unused_62,
	RCC_unused_63,
	RCC_TIM2,
	RCC_TIM3,
	RCC_TIM4,
	RCC_TIM5,
	RCC_unused_68,
	RCC_unused_69,
	RCC_unused_70,
	RCC_unused_71,
	RCC_unused_72,
	RCC_unused_73,
	RCC_unused_74,
	RCC_WWDG,
	RCC_unused_76,
	RCC_unused_77,
	RCC_SPI2,
	RCC_SPI3,
	RCC_unused_80,
	RCC_USART_2,
	RCC_unused_82,
	RCC_unused_83,
	RCC_unused_84,
	RCC_I2C1,
	RCC_I2C2,
	RCC_I2C3,
	RCC_unused_88,
	RCC_unused_89,
	RCC_unused_90,
	RCC_unused_91,
	RCC_PWR,
	RCC_unused_93,
	RCC_unused_94,
	RCC_unused_95,
	RCC_TIM1,
	RCC_unused_97,
	RCC_unused_98,
	RCC_unused_99,
	RCC_USART1,
	RCC_USART6,
	RCC_unused_102,
	RCC_unused_103,
	RCC_ADC1,
	RCC_unused_105,
	RCC_unused_106,
	RCC_SDIO,
	RCC_SPI1,
	RCC_SPI4,
	RCC_SYSCFG,
    RCC_unused_111,
	RCC_TIM9,
	RCC_TIM10,
	RCC_TIM11,
}RCC_PeripheralID;


void RCC_voidInitSysClock(void);
void RCC_voidEnableClock(u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8PerId);

#endif /* RCC_INTERFACE_H_ */
