#include "hw_config.h"

int main(void){
    RCC_Configuration();
    GPIO_Configuration();
    LED_Init();
    /** usart init */
    USART1_Init();
    BSP_LED_Off_All();
    while(1){
        printf("testing\r\n");
        BSP_LED_Test();
    }
    return 0;
}