#ifndef __HW_CONFIG_H__
#define __HW_CONFIG_H__

#include "stm32f4xx.h"
#include <stdio.h>

#define GPIO_LED_PORT               GPIOF
#define GPIO_LED1_PIN               GPIO_Pin_6
#define GPIO_LED2_PIN               GPIO_Pin_7
#define GPIO_LED3_PIN               GPIO_Pin_8
#define LEDn                        3

#define BUTTONn                     2

#define KEY_BUTTON_1_GPIO_PORT      GPIOF
#define KEY_BUTTON_1_PIN            GPIO_Pin_9
#define KEY_BUTTON_1_IRQn           EXTI9_5_IRQn

#define KEY_BUTTON_2_GPIO_PORT      GPIOF
#define KEY_BUTTON_2_PIN            GPIO_Pin_10
#define KEY_BUTTON_2_IRQn           EXTI15_10_IRQn

#define USART1_PORT                 GPIOA
#define USART1_TX_PIN               GPIO_Pin_9
#define USART1_TX_PIN_SOURCE        GPIO_PinSource9
#define USART1_RX_PIN               GPIO_Pin_10
#define USART1_RX_PIN_SOURCE        GPIO_PinSource10



typedef enum{
    LED1 = 0,
    LED2 = 1,
    LED3 = 2
} LED_TypeDef;

typedef enum{
    BUTTON_KEY_1 = 0,
    BUTTON_KEY_2 = 1
}Button_TypeDef;

typedef enum{
    BUTTON_MODE_GPIO = 0,
    BUTTON_MODE_EXTI = 1
} ButtonMode_TypeDef;

void delay_int_count(volatile unsigned int nTime);
void delay_1_second(void);

void RCC_Configuration();
void GPIO_Configuration();
void NVIC_Configuration();
void EXTI_Configuration();
void USART1_Init();

void BSP_LED_Init(LED_TypeDef LED);
void BSP_LED_On_All(void);
void BSP_LED_Off_All(void);
void BSP_LED_Test(void);

void BSP_PB_Init(Button_TypeDef Button, ButtonMode_TypeDef ButtonMode);
uint32_t BSP_PB_GetState(Button_TypeDef Button);

#endif