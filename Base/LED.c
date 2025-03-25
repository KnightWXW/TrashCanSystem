#include "stm32f10x.h"

void LED_Init(void)
{
    // 开启时钟
    RCC_APB2PeriphClockCmd(LED_PORT, ENABLE);
    // 配置结构体
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = LED_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    return;
}

void LED_ON(void)
{
    GPIO_ResetBits(GPIOA, LED_PIN);
    return;
}

void LED_OFF(void)
{
    GPIO_SetBits(GPIOA, LED_PIN);
    return;
}

void LED_Turn(void)
{
    if (GPIO_ReadOutputDataBit(GPIOA, LED_PIN) == 0)
    {
        GPIO_SetBits(GPIOA, LED_PIN);
    }
    else
    {
        GPIO_ResetBits(GPIOA, LED_PIN);
    }
    return;
}
