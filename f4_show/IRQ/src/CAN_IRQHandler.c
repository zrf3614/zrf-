#include "CAN_IRQHandler.h"
#include "stm32f4xx_hal_can.h"
#include "UART_IRQHandler.h"
#include "led_breath.h"
volatile uint8_t Led_state=0;  
volatile uint8_t CAN_State=0; //是否接收信号
volatile uint8_t Send_State=0;
/*--------------------------------8.13can作业-------------------------------*/
// void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
// {
//     CAN_RxHeaderTypeDef rx_header;
//     uint8_t rx_data[8];

//     if (hcan->Instance == CAN1)
//     {
//         if (HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rx_header, rx_data) == HAL_OK)
//         {
//           if(rx_header.ExtId == 0x01020101)  
//           {
//             Beef_count=rx_data[0]; 
//           }
//           else if(rx_header.ExtId == 0x01020201)  
//           {
//             State=1; // 标记接收到信号
//            Led_state=rx_data[0];
//           } 
            
            
//         }
//     }
   
// }

//  void SendOK_1(void)
//  {
//     CAN_TxHeaderTypeDef tx_header;
//             uint32_t txMailbox=0;
//             uint8_t tx_data[2] = {'O', 'K'}; 
//             tx_header.ExtId = 0x02010101; 
//             tx_header.IDE = CAN_ID_EXT; // 使用扩展标识符
//             tx_header.RTR = CAN_RTR_DATA; // 数据帧
//             tx_header.DLC = 2; // 数据长度
//              HAL_CAN_AddTxMessage(&hcan1, &tx_header, tx_data,&txMailbox);
//  }
//  void SendOK_2(void)
//  {
//     CAN_TxHeaderTypeDef tx_header;
//             uint32_t txMailbox=0;
//             uint8_t tx_data[3] = {'O', 'K',Led_state}; 
//             tx_header.ExtId = 0x02010201; 
//             tx_header.IDE = CAN_ID_EXT; // 使用扩展标识符
//             tx_header.RTR = CAN_RTR_DATA; // 数据帧
//             tx_header.DLC = 3; // 数据长度
//              HAL_CAN_AddTxMessage(&hcan1, &tx_header, tx_data,&txMailbox);
 // }
/*---------------------------大作业-----------------------------*/
 void HAL_CAN_RxFifo0MsgPendingCallback(CAN_HandleTypeDef *hcan)
{
    CAN_RxHeaderTypeDef rx_header;
    uint8_t rx_data[8];
    if (hcan->Instance == CAN1)
    {
        if (HAL_CAN_GetRxMessage(hcan, CAN_RX_FIFO0, &rx_header, rx_data) == HAL_OK)
        {
          if(rx_header.StdId == 0x012)
          {
            if (rx_header.DLC >= 3)   
            {
              CAN_State=1;
              BREATH_STATE=rx_data[0];
              Send_State=1;
              /* 协定：rx_data[1..2] 每 nibble 一个十进制位，拼出周期(ms) */
              /* 例：0x20 0x01 → 千位2 百位0 十位0 个位1 → 2001ms */
              BREATH_PERIOD = ((rx_data[1] >> 4) & 0x0F) * 1000
                            + ((rx_data[1] >> 0) & 0x0F) * 100
                            + ((rx_data[2] >> 4) & 0x0F) * 10
                            + ((rx_data[2] >> 0) & 0x0F);
            }
          }
          else if(rx_header.ExtId == 0x02010102)
          {
            if (rx_header.DLC >= 1)
            {
              Beef_count=rx_data[0];
            }
          }
            
            
        }
    }
   
}
