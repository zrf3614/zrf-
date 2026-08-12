#ifndef EXTI_IRQHANDLER_H
#define EXTI_IRQHANDLER_H

/*---------------------include-------------------*/
#include "main.h"

extern volatile uint8_t  Key_PressPending;  /* 按下标记 */
extern volatile uint32_t Key_PressTick;     /* 按下时刻 */

#endif
