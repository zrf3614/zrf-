#include "myostask.h"
#include "led.h"
#include "led_breath.h"
#include "UART_IRQHandler.h"
#include "Beep.h"
#include "CAN_IRQHandler.h"
#include "can.h"
#include "led_breath.h"
volatile uint32_t LedTaskStackHighWaterMark = 0;

void Led_Task(void *argument)
{
    uint8_t i=1;
    TickType_t xlast_wake_time = osKernelGetTickCount();
    const TickType_t xFrequency = pdMS_TO_TICKS(250);  //固定周期250ms
    for (;;)
    {
        LED_OFF(1);
        LED_OFF(2);
        if (i == 1)
         { LED_ON(1); }
         else { LED_ON(2); }
        i = (i % 2) + 1;
        LedTaskStackHighWaterMark = uxTaskGetStackHighWaterMark(NULL)*sizeof(StackType_t);
       vTaskDelayUntil(&xlast_wake_time, xFrequency);  // osDelay(xlast_wake_time)为相对唤醒时间
    }
}

void Beef_Task(void *argument)
{
    uint8_t beep_times;
    for (;;)
     {
      beep_times = Beef_count;     
      if(beep_times !=0)
      {
       Beef_count=0;
       BEEP_ALARM(beep_times);
       }
       osDelay(100);
     }
}
void  Noise_Task(void  *argument)
{
            CAN_TxHeaderTypeDef tx_header;
        uint32_t txMailbox=0;
   uint8_t tx_data[4]={0x5A,0X5A,0X5A,0X5A};
   tx_header.ExtId = 0x02010103; 
    tx_header.IDE = CAN_ID_EXT; 
   tx_header.RTR = CAN_RTR_DATA; 
   tx_header.DLC = 4; 
   HAL_CAN_AddTxMessage(&hcan1, &tx_header, tx_data,&txMailbox);
   osDelay(2);
}

void Send_Data(void *argument)
{

    if(Send_State)
    {
     CAN_TxHeaderTypeDef tx_header;
    uint32_t txMailbox=0;
   uint8_t tx_data[4];
    float data=s_duty/999.0f;
   memcpy(tx_data,&data,4);
   tx_header.ExtId = 0x02010101; 
    tx_header.IDE = CAN_ID_EXT; 
   tx_header.RTR = CAN_RTR_DATA; 
   tx_header.DLC = 4; 
   HAL_CAN_AddTxMessage(&hcan1, &tx_header, tx_data,&txMailbox);
    }

   static uint16_t breath_count = 0;
    breath_count++;
    if (BREATH_STATE )
    {
        if(((breath_count*10) >= (BREATH_PERIOD / 100)))
        {
        breath_count = 0;
        BREATH_Step();
        } 
    }
    else 
    {
        BREATH_Init();
    }
    osDelay(10);
}