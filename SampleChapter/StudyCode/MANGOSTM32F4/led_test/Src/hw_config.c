#include "hw_config.h"

void RCC_Configuration(){
    SystemInit();
    /* Enable GPIOA clock */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    /* Enable GPIOB clock */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    /* Enable GPIOC clock */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    /* Enable GPIOD clock */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
    /* Enable GPIOE clock */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
    /* Enable GPIOF clock */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
    /* Enable GPIOG clock */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);
    /* Enable GPIOH clock */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH, ENABLE);
    /* Enable GPIOI clock */
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOI, ENABLE);
}

void GPIO_Configuration(){
    GPIO_InitTypeDef GPIO_InitStructure;
    /** USART1 Clock Init */
  	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    /** Alternate function use setting */
    GPIO_PinAFConfig(USART1_PORT, USART1_TX_PIN_SOURCE, GPIO_AF_USART1);
    GPIO_PinAFConfig(USART1_PORT, USART1_RX_PIN_SOURCE, GPIO_AF_USART1);;

    GPIO_InitStructure.GPIO_Pin = USART1_TX_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;

    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    GPIO_Init(USART1_PORT, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = USART1_RX_PIN;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(USART1_PORT, &GPIO_InitStructure);

}

void USART1_Init(){
    USART_InitTypeDef USART_InitStructure; 

    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
    USART_Init(USART1, &USART_InitStructure);
    /* Enable the Open_USART Transmit interrupt: this interrupt is generated when the 
     Open_USART transmit data register is empty */
    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);

    USART_Cmd(USART1, ENABLE);
}

void LED_Init(){
    /** GPIO Configuration */
    GPIO_InitTypeDef GPIO_InitStructure;
    /** GPIO LED PIN Configuration */
    GPIO_InitStructure.GPIO_Pin = GPIO_LED1_PIN | GPIO_LED2_PIN | GPIO_LED3_PIN;
    /** GPIO Mode OUT PUT MODE */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    /** GPIO push-pull or open-drain setting */
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    /** GPIO Speed Setting */
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    /** GPIO Push Up, Push Down, NOPull (Setting Push pull register) */
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    /** GPIO Set */
    GPIO_Init(GPIO_LED_PORT, &GPIO_InitStructure);
}