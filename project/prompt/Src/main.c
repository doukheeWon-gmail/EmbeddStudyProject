#include "main_menu.h"
#include "hw_config.h"

/** clocks Info Structure */
RCC_ClocksTypeDef rcc_clocks;

void SystemInformation(void){
    printf("SYSCLK_Frequency = %d\r\n",rcc_clocks.SYSCLK_Frequency );
    printf("HCLK_Frequency = %d\r\n",rcc_clocks.HCLK_Frequency );
    printf("PCLK1_Frequency = %d\r\n",rcc_clocks.PCLK1_Frequency );
    printf("PCLK2_Frequency = %d\r\n",rcc_clocks.PCLK2_Frequency );
    printf("ADCCLK_Frequency = %d\r\n",rcc_clocks.ADCCLK_Frequency );
}

int main(void){
    
    RCC_Configuration();

    USART1_Init();

    SystemInformation();


    while(1){
        main_menu();
    }
    return 0;
}