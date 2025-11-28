#ifndef __LED_H
#define __LED_H

#include "stm32f10x.h"

// 定义RGB灯引脚
#define RGB_RED_PIN GPIO_Pin_5
// 定义GPIO端口
#define RGB_PORT GPIOB

// 函数声明
void RGB_GPIO_Init(void);
void LED_Toggle_Red(void);  

#endif