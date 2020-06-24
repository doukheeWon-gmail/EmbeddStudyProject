#include "hw_config.h"



void RCC_Configuration(void){
    SystemInit();

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO, ENABLE);

}

void USART1_GPIOConfiguration(void){
    /* Configure USARTx_Tx as alternate function push-pull */
    GPIO_InitTypeDef GPIO_InitStructure;
    GPIO_InitStructure.GPIO_Pin = GPIO_USART_Tx_Pin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIO_USART, &GPIO_InitStructure);

    /* Configure USARTx_Rx as input floating */
    GPIO_InitStructure.GPIO_Pin = GPIO_USART_Rx_Pin;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIO_USART, &GPIO_InitStructure);

}

void USART1_Init(void){
    USART1_GPIOConfiguration();
    USART_InitTypeDef USART_InitStructure;
    /* USARTx configuration ------------------------------------------------------*/
    /* USARTx configured as follow:
     - BaudRate = 115200 baud  
     - Word Length = 8 Bits
     - One Stop Bit
     - No parity
     - Hardware flow control disabled (RTS and CTS signals)
     - Receive and transmit enabled
     */
    USART_InitStructure.USART_BaudRate = 115200;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

    USART_Init(USART1, &USART_InitStructure);

    USART_Cmd(USART1, ENABLE);
}