#ifndef UART_IRQHandler_H
#define UART_IRQHandler_H

#include "main.h"
#include "usart.h"
extern volatile uint8_t Beef_count;
  /* 本来是 extern的，AI认为应该在.c里定义，改为extern volatile uint8_t Beef_count; */
  
void USART_Start_Receive(void);
#endif