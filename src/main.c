#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"

#include "GPIO_interface.h"




void main(void)
{
	RCC_voidInitSysClock();
    RCC_voidEnableClock(RCC_GPIOA);
    GPIO_voidSetPinsMode();

 while(1)
 {
   GPIO_voidSetPinValue_ODR(PORT_A,PIN_0,GPIO_HIGH);
   GPIO_voidSetPinValue_ODR(PORT_A,PIN_1,GPIO_LOW);
 }
}
