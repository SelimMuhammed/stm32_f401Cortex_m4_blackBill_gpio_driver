#ifndef GPIO_INTERFACE
#define GPIO_INTERFACE
#include "GPIO_config.h"
#define NOT_USED   255


typedef struct
{
	u8 PORT;
	u8 PIN;
	u8 MODE;
	u8 TYPE;
	u8 SPEED;
	u8 PULL_UP_DOWN;
	u8 AF_MODE;
}pinInfo;

pinInfo ARRAY_OF_PINS[NUMBER_OF_USED_PINS];

typedef enum
{
    PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
	PIN_8,
	PIN_9,
	PIN_10,
	PIN_11,
	PIN_12,
	PIN_13,
	PIN_14,
	PIN_15
}GPIO_PINS;

typedef enum
{
    AF_0_SYSTEM,
	AF_1_TIM1_TIM2,
	AF_2_TIM3_4_5,
	AF_3_TIM9_10_11,
	AF_4_I2C1,
	AF_5_SPI1_2_4,
	AF_6_SPI3,
	AF_7_USART1_2,
	AF_8_USART6,
	AF_9_I2C2_3,
	AF_10_OTG_FS,
	AF_11,
	AF_12_SDIO,
	AF_13,
	AF_14,
	AF_15_EVENTOUT
}AF_Modes;

typedef enum
{
	INPUT,
	OUTPUT,
	AF,
	ANALOG
}MODES_E;

typedef enum
{
	PUSH_PULL,
	OPEN_DRAIN
}OTYPE_E;

typedef enum
{
	LOW_SPEED,
	MEDIUM_SPEED,
	HIGH_SPEED,
	VERY_HIGH_SPEED,
}OSPEED_E;

typedef enum
{
	FLOATING,
	PULL_UP,
	PULL_DOWN
}ITYPE_E;

typedef enum
{
	GPIO_LOW,
	GPIO_HIGH
}OSTATE_E;

typedef enum
{
	PORT_A,
	PORT_B,
	PORT_C
}PORT_ID_E;

void GPIO_voidSetPinsMode(void);
u8 GPIO_u8GetPinValue (u8 Local_u8Port, u8 Local_u8Pin);
void GPIO_VoidSet_LCD_Value_ODR(u8 Local_u8Port, u8 Local_u8Data);
void GPIO_voidSetPinValue_BSRR(u8 Local_u8Port,
		u8 Local_u8Pin,
		u8 Local_u8State);
void GPIO_voidSetPinValue_ODR(u8 Local_u8Port,
		u8 Local_u8Pin,
		u8 Local_u8State);

#endif
