#include "stm32f10x.h"

void Delay_us(uint32_t time)
{
    uint32_t cur = 0;         // 记录当前倒计时的数值
    SysTick->LOAD = 9 * time; // 设置计数器重装载值
    SysTick->CTRL = 0x01;     // 选择计时器为外部计时器，并开启计时器
    SysTick->VAL = 0x00;      // 清空计数器当前数值
    do
    {
        cur = SysTick->CTRL; // 记录当前倒计时的数值
    } while ((cur & 0x01 == 0) && !(cur & (1 << 16)));
    // (cur & 0x01): 判断控制状态寄存器是否在运行 [1: 在运行 | 0: 未运行]
    // !(cur & (1 << 16)): 判断控制状态寄存器第16位: [1: 计时结束 0: 计时未结束]
    SysTick->CTRL = 0x00; // 关闭计数器
    SysTick->VAL = 0x00;  // 清空计数器
    return;
}

void Delay_ms(uint32_t time)
{
    uint32_t cur = 0;            // 记录当前倒计时的数值
    SysTick->LOAD = 9000 * time; // 设置计数器重装载值
    SysTick->CTRL = 0x01;        // 选择计时器为外部计时器，并开启计时器
    SysTick->VAL = 0x00;         // 清空计数器当前数值
    do
    {
        cur = SysTick->CTRL; // 记录当前倒计时的数值
    } while ((cur & 0x01 == 0) && !(cur & (1 << 16)));
    // (cur & 0x01): 判断控制状态寄存器是否在运行 [1: 在运行 | 0: 未运行]
    // !(cur & (1 << 16)): 判断控制状态寄存器第16位: [1: 计时结束 0: 计时未结束]
    SysTick->CTRL = 0x00; // 关闭计数器
    SysTick->VAL = 0x00;  // 清空计数器
    return;
}