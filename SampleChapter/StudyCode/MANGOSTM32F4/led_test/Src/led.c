#include "hw_config.h"

GPIO_TypeDef *GPIO_PORT[LEDn] = {GPIOF, GPIOF, GPIOF};
const uint16_t GPIO_PIN[LEDn] = {GPIO_LED1_PIN, GPIO_LED2_PIN, GPIO_LED3_PIN};


void BSP_LED_Init(LED_TypeDef LED){
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_PIN[LED];
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(GPIO_PORT[LED], &GPIO_InitStructure);

}

void BSP_LED_On(LED_TypeDef LED){
    GPIO_ResetBits(GPIO_PORT[LED], GPIO_PIN[LED]);
}

void BSP_LED_Off(LED_TypeDef LED){
    GPIO_SetBits(GPIO_PORT[LED], GPIO_PIN[LED]);
}