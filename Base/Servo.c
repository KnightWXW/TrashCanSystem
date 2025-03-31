#include "stm32f10x.h"
#include "PWM.h"

void Servo_Init(void)
{
  PWM_Init();
}

// 舵机设置角度
// Angle 要设置的舵机角度，范围：0~180
void Servo_SetAngle(float Angle)
{
  PWM_SetCompare2(Angle / 180 * 2000 + 500); // 设置占空比
                                             // 将角度线性变换，对应到舵机要求的占空比范围上
}
