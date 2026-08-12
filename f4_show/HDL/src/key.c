#include "key.h"
#include "EXTI_IRQHandler.h"

void Key_WaitPress(void)
{
    while (Key_PressPending == 0);  /*之前是用if但AI认为需要反复检测 */
}

uint16_t Key_GetDuration(void)
{
    uint32_t t0 = Key_PressTick;    
    Key_PressPending = 0;            

    /* 高电平按键：按下=高电平，等引脚变低=松手 */
    while (HAL_GPIO_ReadPin(INPUT_1_GPIO_Port, INPUT_1_Pin) == GPIO_PIN_SET);    /*之前没有但AI认为需要反复检测 */

    return (HAL_GetTick() - t0);  
}
