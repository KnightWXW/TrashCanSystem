#ifndef __LED_H
#define __LED_H

#define LED_PORT RCC_APB2Periph_GPIOA
#define LED_PIN GPIO_Pin_5

extern void LED_Init(void);
extern void LED_ON(void);
extern void LED_OFF(void);
extern void LED_Turn(void);

#endif