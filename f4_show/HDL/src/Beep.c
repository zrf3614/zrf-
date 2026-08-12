#include "Beep.h"
void BEEP_INIT(void)
{
    
    BEEP_ON();
    HAL_Delay(200);
    BEEP_OFF();
    HAL_Delay(200);

}
void BEEP_ALARM(uint8_t times)
{
uint8_t i;
for(i=0;i<times;i++)
{
    BEEP_ON();
    HAL_Delay(200);
    BEEP_OFF();
    HAL_Delay(200);
}
}
