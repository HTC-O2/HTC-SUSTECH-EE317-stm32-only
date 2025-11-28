#include "led.h"

// RGBµ∆GPIO≥ı ºªØ
void RGB_GPIO_Init(void) {
    GPIO_InitTypeDef  GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
    GPIO_InitStructure.GPIO_Pin = RGB_RED_PIN;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(RGB_PORT, &GPIO_InitStructure);
}

void LED_Toggle_Red(void) {
    static uint8_t redState = 0;
    redState = !redState;
    if (redState) {
        GPIO_SetBits(RGB_PORT, RGB_RED_PIN);
    } else {
        GPIO_ResetBits(RGB_PORT, RGB_RED_PIN);
    }
}    