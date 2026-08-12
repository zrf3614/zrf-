#ifndef BEEP_H
#define BEEP_H

/*----------------include---------------*/
#include "main.h"
#include "gpio.h"
/*----------------define----------------*/
#define BEEP_ON()   HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_SET)
#define BEEP_OFF()  HAL_GPIO_WritePin(BEEP_GPIO_Port, BEEP_Pin, GPIO_PIN_RESET)
#define BEEP_TOGGLE() HAL_GPIO_TogglePin(BEEP_GPIO_Port, BEEP_Pin)

/*----------------function--------------*/
void BEEP_INIT();
void BEEP_ALARM(uint8_t times);

#endif /*BEEP_H*/