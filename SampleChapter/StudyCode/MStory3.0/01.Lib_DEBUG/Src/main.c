
#include "hw_config.h"
#include "lib_dbg.h"

RCC_ClocksTypeDef rcc_clocks;

void SystemInformation(){
    printf("SYSCLK_Frequency = %d\r\n",rcc_clocks.SYSCLK_Frequency );
    printf("HCLK_Frequency = %d\r\n",rcc_clocks.HCLK_Frequency );
    printf("PCLK1_Frequency = %d\r\n",rcc_clocks.PCLK1_Frequency );
    printf("PCLK2_Frequency = %d\r\n",rcc_clocks.PCLK2_Frequency );
    printf("ADCCLK_Frequency = %d\r\n",rcc_clocks.ADCCLK_Frequency );
}

int main(void){
    RCC_Configuration();
    RCC_GetClocksFreq(&rcc_clocks);
    USART1_Init();
    SystemInformation();
    while(1){
        ;
    }

    return 0;
}