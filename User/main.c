#include "stm32f10x.h"
#include "Delay.h"
#include "LED.h"
#include "OLED.h"
#include "Servo.h"
#include "Key.h"
#include "Timer.h"

KeyHandler myKeyHandler;

int main(void)
{
	OLED_Init();  // OLED初始化
	Timer_Init(); // Timer初始化
	Servo_Init(); // 舵机初始化
	Key_Init();	  // 按键初始化
	InitKeyHandler(&myKeyHandler);
	
	OLED_ShowString(1, 1, "Angle:");	//1行1列显示字符串Angle:
	
	while (1)
	{
	}
}
