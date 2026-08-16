#ifndef __MYOSTASK_H
#define __MYOSTASK_H


#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"


void Led_Task(void *argument);
void Beef_Task(void *argument);
void Send_Data(void *argument);
void Noise_Task(void *argument);
#endif /*__MYOSTASK_H */