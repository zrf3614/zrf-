#include "EXTI_IRQHandler.h"

volatile uint8_t  Key_PressPending = 0;
volatile uint32_t Key_PressTick = 0;
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    if (GPIO_Pin == INPUT_1_Pin)
    {
        Key_PressTick = HAL_GetTick();
        Key_PressPending = 1;

    }
}
//HAL_GPIO