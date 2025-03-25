#include "stm32f10x.h"
#include "Delay.h"

// 按键状态变量
volatile uint8_t key_pressed = 0;  // 0: 未按下, 1: 短按, 2: 长按
volatile uint32_t key_timer = 0;   // 按键计时器
// LED状态变量
volatile uint8_t led_state = 0;    // 0: LED灭, 1: LED亮

void Key_Init()
{
    // 开启时钟
    RCC_APB2PeriphClockCmd(KEY_PORT, ENABLE);
    // 配置结构体
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = KEY_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
    return;
}

void TIM2_IRQHandler(void)
{
    if (TIM_GetITStatus(TIM2, TIM_IT_Update) == SET)
    { // 判断是否是TIM2的更新事件触发的中断
        static uint8_t last_key_state = 1; // 初始化为1，因为按键默认是高电平（未按下）
        // 读取按键状态
        uint8_t current_key_state = GPIO_ReadInputDataBit(KEY_PORT, KEY_PIN);
        // 消抖处理
        if (current_key_state == 0)
        { // 按键按下（低电平）
            key_timer++;
            if (key_timer >= 200)
            {                    // 假设长按时间为200ms
                key_pressed = 2; // 长按
            }
            else if (last_key_state == 1)
            {                    // 确保不是抖动
                key_pressed = 1; // 短按
            }
        }
        else
        {
            // 按键释放
            if (key_pressed == 1 || key_pressed == 2)
            {
                // 如果之前检测到按键按下（无论是短按还是长按），则处理按键事件
                key_pressed = 0; // 重置按键状态
                // 切换LED状态
                led_state = !led_state;
                if (led_state)
                {
                    LED_ON(); // LED亮
                }
                else
                {
                    LED_OFF(); // LED灭
                }
            }
            key_timer = 0; // 重置计时器
        }
        last_key_state = current_key_state; // 更新按键状态
    }
}
