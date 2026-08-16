/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for LED_Task */
osThreadId_t LED_TaskHandle;
const osThreadAttr_t LED_Task_attributes = {
  .name = "LED_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for Buzzer_Task */
osThreadId_t Buzzer_TaskHandle;
const osThreadAttr_t Buzzer_Task_attributes = {
  .name = "Buzzer_Task",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for SEND_DATA */
osThreadId_t SEND_DATAHandle;
const osThreadAttr_t SEND_DATA_attributes = {
  .name = "SEND_DATA",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};
/* Definitions for NOISE_TASK */
osThreadId_t NOISE_TASKHandle;
const osThreadAttr_t NOISE_TASK_attributes = {
  .name = "NOISE_TASK",
  .stack_size = 128 * 4,
  .priority = (osPriority_t) osPriorityLow,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void Led_Task(void *argument);
void Beef_Task(void *argument);
void Send_Data(void *argument);
void Noise_Task(void *argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* creation of LED_Task */
  LED_TaskHandle = osThreadNew(Led_Task, NULL, &LED_Task_attributes);

  /* creation of Buzzer_Task */
  Buzzer_TaskHandle = osThreadNew(Beef_Task, NULL, &Buzzer_Task_attributes);

  /* creation of SEND_DATA */
  SEND_DATAHandle = osThreadNew(Send_Data, NULL, &SEND_DATA_attributes);

  /* creation of NOISE_TASK */
  NOISE_TASKHandle = osThreadNew(Noise_Task, NULL, &NOISE_TASK_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}

/* USER CODE BEGIN Header_Led_Task */
/**
  * @brief  Function implementing the LED_Task thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_Led_Task */
__weak void Led_Task(void *argument)
{
  /* USER CODE BEGIN Led_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Led_Task */
}

/* USER CODE BEGIN Header_Beef_Task */
/**
* @brief Function implementing the Buzzer_Task thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Beef_Task */
__weak void Beef_Task(void *argument)
{
  /* USER CODE BEGIN Beef_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Beef_Task */
}

/* USER CODE BEGIN Header_Send_Data */
/**
* @brief Function implementing the SEND_DATA thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Send_Data */
__weak void Send_Data(void *argument)
{
  /* USER CODE BEGIN Send_Data */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Send_Data */
}

/* USER CODE BEGIN Header_Noise_Task */
/**
* @brief Function implementing the NOISE_TASK thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_Noise_Task */
__weak void Noise_Task(void *argument)
{
  /* USER CODE BEGIN Noise_Task */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Noise_Task */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

