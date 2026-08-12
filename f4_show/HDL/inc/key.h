#ifndef KEY_H
#define KEY_H

#include "main.h"

#define KEY_LONG_MS  1000

/*如何读取摁的时间AI给的思路*/
void Key_WaitPress(void);          /* 阻塞等待一次按下 */
uint16_t Key_GetDuration(void);    /* 量本次按下的时长(ms)：等松手后返回 */

#endif
