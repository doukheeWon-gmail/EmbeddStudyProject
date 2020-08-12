#include "hw_config.h"

int main(void){
    RCC_Configuration();
    GPIO_Configuration();
    LED_Init();
    KEY_Init();
    /** usart init */
    USART1_Init();
    BSP_LED_Off_All();
    while(1){
        //printf("testing\r\n");
        if(BSP_PB_GetState(BUTTON_KEY_1) == RESET){
            printf("KEY1 Pushed\r\n ");
        }

        if(BSP_PB_GetState(BUTTON_KEY_2) == RESET){
            printf("KEY2 Pushed\r\n ");
        }
    }
    return 0;
}