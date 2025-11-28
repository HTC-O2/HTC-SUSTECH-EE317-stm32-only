#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"

// 定义按键引脚
#define KEY1_PIN GPIO_Pin_0
#define KEY1_PORT GPIOA

// 函数声明
void KEY_GPIO_Init(void);
uint8_t KEY1_Scan(void);

#endif