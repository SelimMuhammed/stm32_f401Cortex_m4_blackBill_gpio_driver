#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_config.h"
#include "GPIO_interface.h"
#include "GPIO_private.h"

/*
   PORT

     PIN
      MODE
      TYPE; //OPEN
      SPEED
      PULL_UP_DOWN*/  


void GPIO_voidSetPinsMode(void)
{
	u8 local_u8PinsCounter;
	for(local_u8PinsCounter=0; local_u8PinsCounter<NUMBER_OF_USED_PINS; local_u8PinsCounter++)
	{
		switch(ARRAY_OF_PINS[local_u8PinsCounter].PORT)
		{
		case PORT_A:
			if(ARRAY_OF_PINS[local_u8PinsCounter].MODE == AF)
			{
				// CLEAR THE LOCATION OF PIN
				GPIOA -> MODER &= ~((0b11) <<((ARRAY_OF_PINS[local_u8PinsCounter].PIN) * 2));

				// SELECT MODE"INPUT OR OUTPUT ,AF,ADC"BY NUM OF PIN*2 AND MAKING OR WITH GPIOMODER THIS DETERMINE THE MODE
				GPIOA -> MODER |=  ((ARRAY_OF_PINS[local_u8PinsCounter].MODE)<<((ARRAY_OF_PINS[local_u8PinsCounter].PIN) * 2));

				if((ARRAY_OF_PINS[local_u8PinsCounter].PIN)/8==0)
				{
					GPIOA -> AFRL |=((ARRAY_OF_PINS[local_u8PinsCounter].AF_MODE)<<(4*ARRAY_OF_PINS[local_u8PinsCounter].PIN)); // CONFIG AF0 OR AF1				CLR_BIT(GPIOA -> OTYPER,configPin[itr].PIN*2);

				}
				else if((ARRAY_OF_PINS[local_u8PinsCounter].PIN)/8==1)
				{

					GPIOA -> AFRH |=((ARRAY_OF_PINS[local_u8PinsCounter].AF_MODE)<<(4*((ARRAY_OF_PINS[local_u8PinsCounter].PIN)%8))); // CONFIG AF0 OR AF1				CLR_BIT(GPIOA -> OTYPER,configPin[itr].PIN*2);
				}

				else
				{};
			}
			else{
				// CLEAR THE LOCATION OF PIN
				GPIOA -> MODER &= ~((0b11) <<((ARRAY_OF_PINS[local_u8PinsCounter].PIN) * 2));

				// SELECT MODE"INPUT OR OUTPUT ,AF,ADC"BY NUM OF PIN*2 AND MAKING OR WITH GPIOMODER THIS DETERMINE THE MODE
				GPIOA -> MODER |=  ((ARRAY_OF_PINS[local_u8PinsCounter].MODE)<<((ARRAY_OF_PINS[local_u8PinsCounter].PIN) * 2));

				if(ARRAY_OF_PINS[local_u8PinsCounter].TYPE!=NOT_USED)
				{
					CLR_BIT(GPIOA -> OTYPER,ARRAY_OF_PINS[local_u8PinsCounter].PIN*2);
					// this determine open_drain or push pull
					GPIOA -> OTYPER |=  ((ARRAY_OF_PINS[local_u8PinsCounter].TYPE)<<((ARRAY_OF_PINS[local_u8PinsCounter].PIN)));
					//CLEAR THE LOCATION
					GPIOA -> OSPEEDR &= ~((0b11) <<((ARRAY_OF_PINS[local_u8PinsCounter].PIN)));
					// DETERMINE THE SPEED HIGH OR LOW OR MIDUM OR VERY HIGH
					GPIOA -> OSPEEDR |=  ((ARRAY_OF_PINS[local_u8PinsCounter].SPEED)<<((ARRAY_OF_PINS[local_u8PinsCounter].PIN) * 2));
					//GPIOA -> PUPDR &= ~((0b11) <<((configPin[itr].PIN) * 2)); // CLEAR LOCATION
					//GPIOA -> PUPDR |=  ((configPin[itr].PULL_UP_DOWN)<<((configPin[itr].PIN) * 2)); // SELECT PULL UP OR DOWN
				}
				else if(ARRAY_OF_PINS[local_u8PinsCounter].PULL_UP_DOWN != NOT_USED)
				{       // CLEAR LOCATION
					GPIOA -> PUPDR &= ~((0b11) <<((ARRAY_OF_PINS[local_u8PinsCounter].PIN) * 2)); // CLEAR LOCATION
					// SELECT PULL UP OR DOWN
					GPIOA -> PUPDR |=  ((ARRAY_OF_PINS[local_u8PinsCounter].PULL_UP_DOWN)<<((ARRAY_OF_PINS[local_u8PinsCounter].PIN) * 2)); // SELECT PULL UP OR DOWN
				}
				else{};
			}
			break;
			//********************************************** PORTB

		case PORT_B:
			if(ARRAY_OF_PINS[local_u8PinsCounter].MODE == AF)
			{
				// CLEAR THE LOCATION OF PIN
				GPIOB -> MODER &= ~((0b11) <<((ARRAY_OF_PINS[local_u8PinsCounter].PIN) * 2));

				// SELECT MODE"INPUT OR OUTPUT ,AF,ADC"BY NUM OF PIN*2 AND MAKING OR WITH GPIOMODER THIS DETERMINE THE MODE
				GPIOB -> MODER |=  ((ARRAY_OF_PINS[local_u8PinsCounter].MODE)<<((ARRAY_OF_PINS[local_u8PinsCounter].PIN) * 2));

				if((ARRAY_OF_PINS[local_u8PinsCounter].PIN)/8==0)
				{
					GPIOB -> AFRL |=((ARRAY_OF_PINS[local_u8PinsCounter].AF_MODE)<<(4*ARRAY_OF_PINS[local_u8PinsCounter].PIN)); // CONFIG AF0 OR AF1				CLR_BIT(GPIOA -> OTYPER,configPin[itr].PIN*2);

				}
				else if((ARRAY_OF_PINS[local_u8PinsCounter].PIN)/8==1)
				{

					GPIOB -> AFRH |=((ARRAY_OF_PINS[local_u8PinsCounter].AF_MODE)<<(4*((ARRAY_OF_PINS[local_u8PinsCounter].PIN)%8))); // CONFIG AF0 OR AF1				CLR_BIT(GPIOA -> OTYPER,configPin[itr].PIN*2);
				}

				else
				{};
			}
			else{
				// CLEAR THE LOCATION OF PIN
				GPIOB -> MODER &= ~((0b11) <<((ARRAY_OF_PINS[local_u8PinsCounter].PIN) * 2));

				// SELECT MODE"INPUT OR OUTPUT ,AF,ADC"BY NUM OF PIN*2 AND MAKING OR WITH GPIOMODER THIS DETERMINE THE MODE
				GPIOB -> MODER |=  ((ARRAY_OF_PINS[local_u8PinsCounter].MODE)<<((ARRAY_OF_PINS[local_u8PinsCounter].PIN) * 2));

				if(ARRAY_OF_PINS[local_u8PinsCounter].TYPE!=NOT_USED)
				{
					CLR_BIT(GPIOB -> OTYPER,ARRAY_OF_PINS[local_u8PinsCounter].PIN*2);
					// this determine open_drain or push pull
					GPIOB -> OTYPER |=  ((ARRAY_OF_PINS[local_u8PinsCounter].TYPE)<<((ARRAY_OF_PINS[local_u8PinsCounter].PIN)));
					//CLEAR THE LOCATION
					GPIOB -> OSPEEDR &= ~((0b11) <<((ARRAY_OF_PINS[local_u8PinsCounter].PIN)));
					// DETERMINE THE SPEED HIGH OR LOW OR MIDUM OR VERY HIGH
					GPIOB -> OSPEEDR |=  ((ARRAY_OF_PINS[local_u8PinsCounter].SPEED)<<((ARRAY_OF_PINS[local_u8PinsCounter].PIN) * 2));
					//GPIOA -> PUPDR &= ~((0b11) <<((configPin[itr].PIN) * 2)); // CLEAR LOCATION
					//GPIOA -> PUPDR |=  ((configPin[itr].PULL_UP_DOWN)<<((configPin[itr].PIN) * 2)); // SELECT PULL UP OR DOWN
				}
				else if(ARRAY_OF_PINS[local_u8PinsCounter].PULL_UP_DOWN != NOT_USED)
				{       // CLEAR LOCATION
					GPIOB -> PUPDR &= ~((0b11) <<((ARRAY_OF_PINS[local_u8PinsCounter].PIN) * 2)); // CLEAR LOCATION
					// SELECT PULL UP OR DOWN
					GPIOB -> PUPDR |=  ((ARRAY_OF_PINS[local_u8PinsCounter].PULL_UP_DOWN)<<((ARRAY_OF_PINS[local_u8PinsCounter].PIN) * 2)); // SELECT PULL UP OR DOWN
				}
				else{};
			}
			break;
			//**************************************************************************PORTC
		case PORT_C:
			if(ARRAY_OF_PINS[local_u8PinsCounter].MODE == AF)
			{
				// CLEAR THE LOCATION OF PIN
				GPIOC -> MODER &= ~((0b11) <<((ARRAY_OF_PINS[local_u8PinsCounter].PIN) * 2));

				// SELECT MODE"INPUT OR OUTPUT ,AF,ADC"BY NUM OF PIN*2 AND MAKING OR WITH GPIOMODER THIS DETERMINE THE MODE
				GPIOC -> MODER |=  ((ARRAY_OF_PINS[local_u8PinsCounter].MODE)<<((ARRAY_OF_PINS[local_u8PinsCounter].PIN) * 2));

				if((ARRAY_OF_PINS[local_u8PinsCounter].PIN)/8==0)
				{
					GPIOC -> AFRL |=((ARRAY_OF_PINS[local_u8PinsCounter].AF_MODE)<<(4*ARRAY_OF_PINS[local_u8PinsCounter].PIN)); // CONFIG AF0 OR AF1				CLR_BIT(GPIOA -> OTYPER,configPin[itr].PIN*2);

				}
				else if((ARRAY_OF_PINS[local_u8PinsCounter].PIN)/8==1)
				{

					GPIOC -> AFRH |=((ARRAY_OF_PINS[local_u8PinsCounter].AF_MODE)<<(4*((ARRAY_OF_PINS[local_u8PinsCounter].PIN)%8))); // CONFIG AF0 OR AF1				CLR_BIT(GPIOA -> OTYPER,configPin[itr].PIN*2);
				}

				else
				{};
			}
			else{
				// CLEAR THE LOCATION OF PIN
				GPIOC -> MODER &= ~((0b11) <<((ARRAY_OF_PINS[local_u8PinsCounter].PIN) * 2));

				// SELECT MODE"INPUT OR OUTPUT ,AF,ADC"BY NUM OF PIN*2 AND MAKING OR WITH GPIOMODER THIS DETERMINE THE MODE
				GPIOC -> MODER |=  ((ARRAY_OF_PINS[local_u8PinsCounter].MODE)<<((ARRAY_OF_PINS[local_u8PinsCounter].PIN) * 2));

				if(ARRAY_OF_PINS[local_u8PinsCounter].TYPE!=NOT_USED)
				{
					CLR_BIT(GPIOC -> OTYPER,ARRAY_OF_PINS[local_u8PinsCounter].PIN*2);
					// this determine open_drain or push pull
					GPIOC -> OTYPER |=  ((ARRAY_OF_PINS[local_u8PinsCounter].TYPE)<<((ARRAY_OF_PINS[local_u8PinsCounter].PIN)));
					//CLEAR THE LOCATION
					GPIOC -> OSPEEDR &= ~((0b11) <<((ARRAY_OF_PINS[local_u8PinsCounter].PIN)));
					// DETERMINE THE SPEED HIGH OR LOW OR MIDUM OR VERY HIGH
					GPIOC -> OSPEEDR |=  ((ARRAY_OF_PINS[local_u8PinsCounter].SPEED)<<((ARRAY_OF_PINS[local_u8PinsCounter].PIN) * 2));
					//GPIOA -> PUPDR &= ~((0b11) <<((configPin[itr].PIN) * 2)); // CLEAR LOCATION
					//GPIOA -> PUPDR |=  ((configPin[itr].PULL_UP_DOWN)<<((configPin[itr].PIN) * 2)); // SELECT PULL UP OR DOWN
				}
				else if(ARRAY_OF_PINS[local_u8PinsCounter].PULL_UP_DOWN != NOT_USED)
				{       // CLEAR LOCATION
					GPIOC -> PUPDR &= ~((0b11) <<((ARRAY_OF_PINS[local_u8PinsCounter].PIN) * 2)); // CLEAR LOCATION
					// SELECT PULL UP OR DOWN
					GPIOC -> PUPDR |=  ((ARRAY_OF_PINS[local_u8PinsCounter].PULL_UP_DOWN)<<((ARRAY_OF_PINS[local_u8PinsCounter].PIN) * 2)); // SELECT PULL UP OR DOWN
				}
				else{};
			}
				break;
			}
		}
	}

	void GPIO_voidSetPinValue_BSRR(u8 Local_u8Port,
			u8 Local_u8Pin,
			u8 Local_u8State)
	{
		if(Local_u8Pin > 15)
		{
			//DET_reportError();
		}
		else
		{
			switch(Local_u8Port)
			{
			//*******************************************************************************
			case PORT_A:
				if(Local_u8State==GPIO_LOW)
				{
					SET_BIT(GPIOA ->BSRR,(Local_u8Pin+16));
				}
				else if(Local_u8State==GPIO_HIGH)
				{
					SET_BIT(GPIOA ->BSRR,Local_u8Pin);
				}
				else
				{
					//DET_reportError();
				}
				break;
				//********************************************************************************
			case PORT_B:
				if(Local_u8State==GPIO_LOW)
				{
					SET_BIT(GPIOB ->BSRR,(Local_u8Pin+16));
				}
				else if(Local_u8State==GPIO_HIGH)
				{
					SET_BIT(GPIOB ->BSRR,Local_u8Pin);
				}
				else
				{
					//DET_reportError();
				}
				break;
				//********************************************************************************
			case PORT_C:
				if(Local_u8State==GPIO_LOW)
				{
					SET_BIT(GPIOC ->BSRR,(Local_u8Pin+16));
				}
				else if(Local_u8State==GPIO_HIGH)
				{
					SET_BIT(GPIOC ->BSRR,Local_u8Pin);
				}
				else
				{
					//DET_reportError();
				}
				break;
			}
		}


		//********************************************************************************
	}


	u8 GPIO_u8GetPinValue (u8 Local_u8Port, u8 Local_u8Pin)
	{
		u8 Local_u8PinState=0;

		if(Local_u8Pin > 15)
		{
			//DET_reportError();
		}
		else
		{
			switch(Local_u8Port)
			{
			case PORT_A: Local_u8PinState= GET_BIT(GPIOA -> IDR, Local_u8Pin);break;
			case PORT_B: Local_u8PinState= GET_BIT(GPIOB -> IDR, Local_u8Pin);break;
			case PORT_C: Local_u8PinState= GET_BIT(GPIOC -> IDR, Local_u8Pin);break;
			default:  //DET_reportError();
				break;
			}
		}
		return Local_u8PinState;
	}

	void GPIO_voidSetPinValue_ODR(u8 Local_u8Port,
			u8 Local_u8Pin,
			u8 Local_u8State)
	{

		if(Local_u8Pin > 15)
		{
			//DET_reportError();
		}
		else
		{
			switch(Local_u8Port)
			{
			case PORT_A:
				if(Local_u8State == GPIO_HIGH)
				{
					SET_BIT(GPIOA -> ODR, Local_u8Pin);
				}
				else if(Local_u8State == GPIO_LOW)
				{
					CLR_BIT(GPIOA -> ODR, Local_u8Pin);
				}
				else
				{
					//DET_reportError();
				}
				break;

			case PORT_B:
				if(Local_u8State == GPIO_HIGH)
				{
					SET_BIT(GPIOB -> ODR, Local_u8Pin);
				}
				else if(Local_u8State == GPIO_LOW)
				{
					CLR_BIT(GPIOB -> ODR, Local_u8Pin);
				}
				else
				{
					//DET_reportError();
				}
				break;


			case PORT_C:
				if(Local_u8State == GPIO_HIGH)
				{
					SET_BIT(GPIOC -> ODR, Local_u8Pin);
				}
				else if(Local_u8State == GPIO_LOW)
				{
					CLR_BIT(GPIOC -> ODR, Local_u8Pin);
				}
				else
				{
					//DET_reportError();
				}
				break;

			}
		}
	}
	void GPIO_VoidSet_LCD_Value_ODR(u8 Local_u8Port, u8 Local_u8Data)
	{
		switch(Local_u8Port)
		{
		case PORT_A: GPIOA->ODR=Local_u8Data;break;
		case PORT_B: GPIOB->ODR=Local_u8Data;break;
		case PORT_C: GPIOC->ODR=Local_u8Data;break;
		}
	}
