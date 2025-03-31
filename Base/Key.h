#ifndef __KEY_H
#define __KEY_H

#include "stm32f10x.h"

typedef enum
{
    KEY_DOWN, // 按键按下状态
    KEY_UP,   // 按键松开状态
} KeyStatus;

typedef enum
{
    NULL_PRESS,  // 没有按键事件
    SHORT_PRESS, // 短按事件
    LONG_PRESS,  // 长按事件
} KeyEvent;

typedef struct
{
    KeyStatus status;        // 按键状态
    KeyEvent event;          // 按键事件
    uint16_t longPressCount; // 按键按下时长
} KeyHandler;

extern KeyHandler myKeyHandler;

// // 按键状态变量
// volatile uint8_t key_pressed = 0; // 0: 未按下, 1: 短按, 2: 长按
// volatile uint32_t key_timer = 0;  // 按键计时器
// // LED状态变量
// volatile uint8_t led_state = 0; // 0: LED灭, 1: LED亮

extern void Key_Init();
extern void InitKeyHandler(KeyHandler *handler);
extern void TIM2_IRQHandler();
extern void KeyScanHandler(KeyHandler *handler);

#endif
