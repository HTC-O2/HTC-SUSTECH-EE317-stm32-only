#include "delay.h"

static uint8_t  fac_us = 0;  // us延时倍乘数
static uint16_t fac_ms = 0;  // ms延时倍乘数

// 初始化延时函数
void delay_init(void) {
    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK_Div8);  // 选择外部时钟  HCLK/8
    fac_us = SystemCoreClock / 8000000;  // 为系统时钟的1/8
    fac_ms = (uint16_t)fac_us * 1000;  // 每个ms需要的SysTick时钟数
}

// 延时nus微秒
// nus:要延时的us数
void delay_us(uint32_t nus) {
    uint32_t temp;
    SysTick->LOAD = nus * fac_us;  // 时间加载
    SysTick->VAL = 0x00;  // 清空计数器
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;  // 开始倒数
    do {
        temp = SysTick->CTRL;
    } while ((temp & 0x01) && !(temp & (1 << 16)));  // 等待时间到达
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;  // 关闭计数器
    SysTick->VAL = 0x00;  // 清空计数器
}

// 延时nms毫秒
// nms:要延时的ms数
void delay_ms(uint32_t nms) {
    uint32_t temp;
    SysTick->LOAD = (uint32_t)nms * fac_ms;  // 时间加载(SysTick->LOAD为24bit)
    SysTick->VAL = 0x00;  // 清空计数器
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;  // 开始倒数
    do {
        temp = SysTick->CTRL;
    } while ((temp & 0x01) && !(temp & (1 << 16)));  // 等待时间到达
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;  // 关闭计数器
    SysTick->VAL = 0x00;  // 清空计数器
}    