#include "UART_IRQHandler.h"
uint8_t rx_buffer[100]={0};            
 volatile  uint8_t Beef_count = 0;      

void USART_Start_Receive(void)
{
//     HAL_UART_Receive_IT(&huart1, rx_buffer, sizeof(rx_buffer));
        HAL_UARTEx_ReceiveToIdle_IT(&huart1, rx_buffer, sizeof(rx_buffer));  // 启动空闲中断接收
 }
/*-------------------------------中断接收---------------------------------*/
// void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
// {
//     if (huart->Instance == USART1)
//     {
       
//         for(uint8_t i=0;i<sizeof(rx_buffer);i++) 
//         {
//             if(rx_buffer[i]==0x01)
//             {
//                 Beef_count++;
//             }
//         }
//         HAL_UART_Receive_IT(&huart1, rx_buffer, sizeof(rx_buffer));  // 重新启动接收中断
        
//     }
// }
/*-------------------------------空闲中断---------------------------------*/
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
    if (huart->Instance == USART1)
    {
        for(uint8_t i=0;i<Size;i++) 
        {
            if(rx_buffer[i]==1)
            
            {
                Beef_count++;
            }
        }
        HAL_UARTEx_ReceiveToIdle_IT(&huart1, rx_buffer, sizeof(rx_buffer));  // 重新启动接收中断
    }
}