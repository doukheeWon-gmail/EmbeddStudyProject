#include "hw_config.h"

GPIO_TypeDef *BUTTON_PORT[BUTTONn]  = {
    KEY_BUTTON_1_GPIO_PORT,
    KEY_BUTTON_2_GPIO_PORT
};

uint16_t BUTTON_PIN[BUTTONn] = {
    KEY_BUTTON_1_PIN,
    KEY_BUTTON_2_PIN
};

uint8_t BUTTON_IRQn[BUTTONn] = {
    KEY_BUTTON_1_IRQn,
    KEY_BUTTON_2_IRQn
};

void BSP_PB_Init(Button_TypeDef Button, ButtonMode_TypeDef ButtonMode){
    GPIO_InitTypeDef GPIO_InitStructure;
    /** GPIO KEY1 Pin Configuration */
    GPIO_InitStructure.GPIO_Pin = KEY_BUTTON_1_PIN;
    /** GPIO Mode Set */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    /** GPIO Push-Pull or open-Drain Setting */
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    /** GPIO Init */
    GPIO_Init(KEY_BUTTON_1_GPIO_PORT, &GPIO_InitStructure);

    /** GPIO KEY2 Pin Configuration */
    GPIO_InitStructure.GPIO_Pin = KEY_BUTTON_2_PIN;
    /** GPIO Mode Set */
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
    /** GPIO Push-Pull or open-Drain Setting */
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
    /** GPIO Init */
    GPIO_Init(KEY_BUTTON_2_GPIO_PORT, &GPIO_InitStructure);

}
uint32_t BSP_PB_GetState(Button_TypeDef Button){
    return GPIO_ReadInputDataBit(BUTTON_PORT[Button], BUTTON_PIN[Button]);
}