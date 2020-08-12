#include "hw_config.h"

RCC_ClocksTypeDef  rcc_clocks;

/* functions */

void System_Information()
{

    printf("SYSCLK_Frequency = %d\r\n",rcc_clocks.SYSCLK_Frequency );
    printf("HCLK_Frequency = %d\r\n",rcc_clocks.HCLK_Frequency );
    printf("PCLK1_Frequency = %d\r\n",rcc_clocks.PCLK1_Frequency );
    printf("PCLK2_Frequency = %d\r\n",rcc_clocks.PCLK2_Frequency );
}


int main(void){
    RCC_Configuration();
    
    NVIC_Configuration();
    GPIO_Configuration();
    LED_Init();
    KEY_Init();
    //TODO
    EXTI_Configuration();
    /** usart init */
    USART1_Init();
    RCC_GetClocksFreq(&rcc_clocks);
    System_Information();
    /* Setup SysTick Timer for 1 msec interrupts  */
    if (SysTick_Config(rcc_clocks.SYSCLK_Frequency / 1000))
    { 
        /* Capture error */ 
        while (1);
    }

    BSP_LED_Off_All();
    printf("MANGO-M4 Board Testing EXTI\r\n");
    while(1){
        //printf("testing\r\n");
        /*
        if(BSP_PB_GetState(BUTTON_KEY_1) == RESET){
            printf("KEY1 Pushed\r\n ");
        }

        if(BSP_PB_GetState(BUTTON_KEY_2) == RESET){
            printf("KEY2 Pushed\r\n ");
        }
        */
    }
    return 0;
}