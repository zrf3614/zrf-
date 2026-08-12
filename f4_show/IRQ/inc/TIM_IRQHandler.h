#ifndef TIM_IRQHANDLER_H
#define TIM_IRQHANDLER_H

#include "main.h"
#include "tim.h"
#include "EXTI_IRQHandler.h"

void BREATH_Step(void);
void BREATH_Init(void);   /* 呼吸灯复位：占空比归零、熄灭 LED3/4 */

#endif