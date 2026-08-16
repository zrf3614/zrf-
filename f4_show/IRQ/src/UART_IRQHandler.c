#include "UART_IRQHandler.h"
uint8_t rx_buffer[100]={0};
uint8_t tx_buffer[100]={0};            
volatile  uint8_t Beef_count = 0;      

void UART_Start_Receive(void)
{
    HAL_UARTEx_ReceiveToIdle_DMA(&huart1, rx_buffer, sizeof(rx_buffer));
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
//         HAL_UART_Receive_DMA(&huart1, rx_buffer, sizeof(rx_buffer)); // 重新启动DMA接收
// //     }
// }
/*-------------------------------空闲DMA接收---------------------------------*/
void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
    if (huart->Instance == USART1)
    {
        if (Size < sizeof(rx_buffer))      // 只有 Size<100 才是总线空闲停下的，正常处理
        {
            for (uint8_t i = 0; i < Size; i++)
            {
                if (rx_buffer[i] == 0x01)
                {
                    Beef_count++;
                }
            }
        }
        UART_Start_Receive();              // 重新启动下一轮接收
    }
}

