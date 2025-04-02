#include "stm32f10x.h"
#include "Delay.h"
#include "LED.h"
// #include "OLED.h"
#include "Key.h"
// #include "Servo.h"

#define RCC_KEY_PORT RCC_APB2Periph_GPIOB
#define KEY_PORT GPIOB
#define KEY_PIN GPIO_Pin_1
#define SERVO_SHORT_PRESS_ANGLE 90
#define SERVO_LONG_PRESS_ANGLE 150

void Key_Init()
{
    // 开启时钟
    RCC_APB2PeriphClockCmd(RCC_KEY_PORT, ENABLE);
    // 配置结构体
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = KEY_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    return;
}

void InitKeyHandler(KeyHandler *handler)
{
    handler->status = KEY_UP;
    handler->event = NULL_PRESS;
    handler->longPressCount = 0;
    return;
}

uint16_t Key_GetNum()
{
    uint16_t keyNum = 0;
    if (GPIO_ReadInputDataBit(KEY_PORT, KEY_PIN) == 0)
    {
        Delay_ms(20);
        while(GPIO_ReadInputDataBit(KEY_PORT, KEY_PIN) == 0);
        Delay_ms(20);
        keyNum = 1;
    }
    else
    {
        Delay_ms(20);
        while(GPIO_ReadInputDataBit(KEY_PORT, KEY_PIN) == 0);
        Delay_ms(20);
        keyNum = 2;
    }
    return keyNum;
}

// void TIM2_IRQHandler()
// {
//     if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
//     {
//         if (GPIO_ReadInputDataBit(KEY_PORT, KEY_PIN) == 0)
//         {
//             myKeyHandler.status = KEY_DOWN;
//         }
//         KeyScanHandler(&myKeyHandler);
//         if (myKeyHandler.event == SHORT_PRESS)
//         {
//             LED_Turn();
//             Servo_SetAngle(SERVO_SHORT_PRESS_ANGLE);        // 设置舵机的角度
//             OLED_ShowNum(1, 7, SERVO_SHORT_PRESS_ANGLE, 3); // OLED显示角度变量
//         }
//         else if (myKeyHandler.event == LONG_PRESS)
//         {
//             LED_Turn();
//             Servo_SetAngle(SERVO_LONG_PRESS_ANGLE);        // 设置舵机的角度
//             OLED_ShowNum(1, 7, SERVO_LONG_PRESS_ANGLE, 3); // OLED显示角度变量
//         }
//         TIM_ClearITPendingBit(TIM2, TIM_IT_Update);
//     }
//     return;
// }

// void KeyScanHandler(KeyHandler *handler)
// {
//     unsigned char keyStatus = 1;
//     if (handler->longPressCount == 0 && handler->status != KEY_DOWN)
//     {
//         handler->event = NULL_PRESS; // 重置按键状态标志位
//     }
//     if (handler->status == KEY_DOWN)
//     {
//         handler->status = KEY_UP;
//         keyStatus = GPIO_ReadInputDataBit(KEY_PORT, KEY_PIN);
//     }
//     if (keyStatus == 0)
//     {
//         handler->longPressCount++;
//     }
//     else
//     {
//         if (handler->longPressCount >= 4 && handler->longPressCount < 200)
//         {
//             handler->event = SHORT_PRESS;
//         }
//         else if (handler->longPressCount >= 200)
//         {
//             handler->event = LONG_PRESS;
//         }
//         else
//         {
//             handler->event = NULL_PRESS;
//         }
//         handler->longPressCount = 0;
//     }
//     return;
// }
