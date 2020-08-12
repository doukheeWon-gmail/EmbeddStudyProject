#include "hw_config.h"

GPIO_TypeDef *GPIO_PORT[LEDn] = {GPIOF, GPIOF, GPIOF};
const uint16_t GPIO_PIN[LEDn] = {GPIO_LED1_PIN, GPIO_LED2_PIN, GPIO_LED3_PIN};

void delay_int_count(volatile unsigned int nTime){
    for(; nTime > 0; nTime--);
}

void delay_1_second(void){
    delay_int_count(806596);
}


void BSP_LED_Init(LED_TypeDef LED){
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_PIN[LED];
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

void BSP_LED_On_All(void){
    BSP_LED_On(LED1);
    BSP_LED_On(LED2);
    BSP_LED_On(LED3);
}

void BSP_LED_Off_All(){
    BSP_LED_Off(LED1);
    BSP_LED_Off(LED2);
    BSP_LED_Off(LED3);
}

void LED_OnOffAll_Mult(uint32_t count){
    for(; count > 0; count--){
        BSP_LED_On(LED1);
        BSP_LED_Off(LED2);
        BSP_LED_Off(LED3);
        delay_1_second();

        BSP_LED_Off(LED1);
        BSP_LED_On(LED2);
        BSP_LED_Off(LED3);
        delay_1_second();

        BSP_LED_Off(LED1);
        BSP_LED_Off(LED2);
        BSP_LED_On(LED3);
        delay_1_second();
    }
}

void BSP_LED_Test(void){
    LED_OnOffAll_Mult(30);
}