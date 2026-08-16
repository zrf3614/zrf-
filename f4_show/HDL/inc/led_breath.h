#ifndef LED_BREATH_H
#define LED_BREATH_H
#include "main.h"


extern volatile uint16_t s_duty;
extern volatile uint16_t BREATH_PERIOD;   
extern volatile uint8_t  BREATH_STATE;
void BREATH_Step();
void BREATH_Init(void);   /* 呼吸灯复位：占空比归零、熄灭 LED3/4 */
#endif