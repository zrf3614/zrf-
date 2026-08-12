#include "TIM_IRQHandler.h"


static uint16_t s_duty = 0;
static uint8_t  s_dir  = 1;          

void BREATH_Step(void)
{
    if (s_dir) s_duty += 20;         
    else       s_duty -= 20;

    if (s_duty >= 999) s_dir = 0;    
    if (s_duty <= 0)   s_dir = 1;    

    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, s_duty);  
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, s_duty); 
    HAL_Delay(20);
}

/* 呼吸灯复位，第一次运行发现相互切换模式，另一个模式不会灭 */
void BREATH_Init(void)
{
    s_duty = 0;
    s_dir  = 1;
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, 0);
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, 0);
}
