#include "key.h"
#include "delay.h"

// 按键GPIO初始化
void KEY_GPIO_Init(void) {
    GPIO_InitTypeDef  GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    
    // 配置KEY1引脚（PA0）
    GPIO_InitStructure.GPIO_Pin = KEY1_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;  // 上拉输入模式
    GPIO_Init(KEY1_PORT, &GPIO_InitStructure);
}

// 按键1扫描函数（带消抖）
uint8_t KEY1_Scan(void) {
    if (GPIO_ReadInputDataBit(KEY1_PORT, KEY1_PIN) == 0) {  // 检测到按键按下（低电平有效）
        delay_ms(20);  // 消抖延时
        if (GPIO_ReadInputDataBit(KEY1_PORT, KEY1_PIN) == 0) {  // 确认按下
            while (GPIO_ReadInputDataBit(KEY1_PORT, KEY1_PIN) == 0);  // 等待按键释放
            return 1;  // 返回按键按下标志
        }
    }
    return 0;  // 无按键按下
} 