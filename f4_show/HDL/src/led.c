#include "led.h"

void LED_WATER(void)
{
    LED_ON(1);
    HAL_Delay(200);
    LED_OFF(1);
     LED_ON(2);
    HAL_Delay(200);
    LED_OFF(2);
    //  LED_ON(3);
    // HAL_Delay(200);
    // LED_OFF(3);
    //  LED_ON(4);
    // HAL_Delay(200);
    // LED_OFF(4);
}
