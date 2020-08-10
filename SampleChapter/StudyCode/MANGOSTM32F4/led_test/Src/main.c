#include "hw_config.h"

int main(void){
    SystemInit();
    GPIO_Configuration();
    LED_Init();
    /** usart init */
    USART1_Init();
    BSP_LED_Off(LED1);
    BSP_LED_Off(LED2);
    BSP_LED_Off(LED3);
    while(1){
        printf("testing\r\n");
    }
    return 0;
}