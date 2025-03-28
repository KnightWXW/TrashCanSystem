#ifndef __KEY_H
#define __KEY_H

#define KEY_PORT RCC_APB2Periph_GPIOB
#define KEY_PIN GPIO_Pin_1

extern void Key_Init();
extern void InitKeyHandler(KeyHandler *handler);
extern void TIM2_IRQHandler();
extern void KeyHandler(KeyHandler *handler);
#endif