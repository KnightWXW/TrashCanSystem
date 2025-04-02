#include "stm32f10x.h"
#include "Delay.h"
#include "LED.h"
#include "OLED.h"
#include "Servo.h"
#include "Key.h"
#include "Timer.h"

// KeyHandler myKeyHandler;

#define SERVO_OPEN_ANGLE 120

uint16_t keyNum;
float angle;

int main(void)
{
	OLED_Init(); // OLED初始化
	// Timer_Init(); // Timer初始化
	Servo_Init(); // 舵机初始化
	Key_Init();	  // 按键初始化
	// InitKeyHandler(&myKeyHandler);

	OLED_ShowString(1, 1, "Angle:"); // 1行1列显示字符串Angle:

	while (1)
	{
		keyNum = Key_GetNum();
		if (keyNum == 1)
		{
			angle = SERVO_OPEN_ANGLE;
		}
		else if (keyNum == 2)
		{
			angle = 0.0;
		}
		LED_Turn();
		Servo_SetAngle(SERVO_OPEN_ANGLE);
		OLED_ShowNum(1, 7, SERVO_OPEN_ANGLE, 3);
	}
}
