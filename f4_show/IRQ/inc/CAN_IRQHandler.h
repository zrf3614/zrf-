#ifndef CAN_IRQHandler_H
#define CAN_IRQHandler_H

#include"main.h"
#include"can.h"
extern volatile uint8_t Led_state;
extern volatile uint8_t CAN_State; //是否接收信号
extern volatile uint8_t Send_State;
void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan);
void SendOK_1(void);
void SendOK_2(void);
#endif