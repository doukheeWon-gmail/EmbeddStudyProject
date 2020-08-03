/**
  ******************************************************************************
  * @file    main.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    18-April-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************  
  */ 

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "config.h"
#include "usart.h"
#include <string.h>
#include <stdio.h>


/* Private function prototypes -----------------------------------------------*/
void  Delay(uint32_t nCount);


/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
	uint8_t Key;
	Open407V_LEDInit();
	Open407V_JOYSTICK_KEY_Init();

	Key=0;
	/* Infinite loop */
	while (1)
	{
 	//JOYSTICK  A(PA4) B(PA6)  C(PB15)  D(PC6)  PRESS(PC7)
	// user(PB1) 
	//wakeup(PA0)
		if(!(GPIOA->IDR & (1<<4)))
			Key=1;
		else if(!(GPIOA->IDR & (1<<6)))
			Key=2;
		else if(!(GPIOB->IDR & (1<<15)))
			Key=3;
		else if(!(GPIOC->IDR & (1<<6)))
			Key=4;
		else if(!(GPIOC->IDR & (1<<7)))
			Key=0;


		else if(!(GPIOB->IDR & 0x0002))
			Key=5;
		else if(!(GPIOA->IDR & 0x0001))
			Key=6;
	
		switch(Key)
		{
			case 0:
			GPIO_SetBits(GPIOD , GPIO_Pin_12);
			GPIO_SetBits(GPIOD , GPIO_Pin_13);
			GPIO_SetBits(GPIOD , GPIO_Pin_14);
			GPIO_SetBits(GPIOD , GPIO_Pin_15);
			Delay(0x5fffff);
			GPIO_ResetBits(GPIOD , GPIO_Pin_12);
			GPIO_ResetBits(GPIOD , GPIO_Pin_13);
			GPIO_ResetBits(GPIOD , GPIO_Pin_14);
			GPIO_ResetBits(GPIOD , GPIO_Pin_15);
			Delay(0x5fffff);
				break;
			case 1:
			GPIO_SetBits(GPIOD , GPIO_Pin_12);
			Delay(0x5fffff);
			GPIO_ResetBits(GPIOD , GPIO_Pin_12);
			Delay(0x5fffff);
				break;
			case 2:
			GPIO_SetBits(GPIOD , GPIO_Pin_13);
			Delay(0x5fffff);
			GPIO_ResetBits(GPIOD , GPIO_Pin_13);
			Delay(0x5fffff);
				break;
			case 3:
			GPIO_SetBits(GPIOD , GPIO_Pin_14);
			Delay(0x5fffff);
			GPIO_ResetBits(GPIOD , GPIO_Pin_14);
			Delay(0x5fffff);
				break;
			case 4:
			GPIO_SetBits(GPIOD , GPIO_Pin_15);
			Delay(0x5fffff);
			GPIO_ResetBits(GPIOD , GPIO_Pin_15);
			Delay(0x5fffff);
				break;
			case 5:
			GPIO_SetBits(GPIOD , GPIO_Pin_12);
			Delay(0x5fffff);
			GPIO_ResetBits(GPIOD , GPIO_Pin_12);
			
			GPIO_SetBits(GPIOD , GPIO_Pin_13);
			Delay(0x5fffff);
			GPIO_ResetBits(GPIOD , GPIO_Pin_13);
			
			GPIO_SetBits(GPIOD , GPIO_Pin_14);
			Delay(0x5fffff);
			GPIO_ResetBits(GPIOD , GPIO_Pin_14);
			
			GPIO_SetBits(GPIOD , GPIO_Pin_15);
			Delay(0x5fffff);
			GPIO_ResetBits(GPIOD , GPIO_Pin_15);
				break;
			case 6:
			GPIO_SetBits(GPIOD , GPIO_Pin_15);
			Delay(0x5fffff);
			GPIO_ResetBits(GPIOD , GPIO_Pin_15);
			
			GPIO_SetBits(GPIOD , GPIO_Pin_14);
			Delay(0x5fffff);
			GPIO_ResetBits(GPIOD , GPIO_Pin_14);
			
			GPIO_SetBits(GPIOD , GPIO_Pin_13);
			Delay(0x5fffff);
			GPIO_ResetBits(GPIOD , GPIO_Pin_13);
			
			GPIO_SetBits(GPIOD , GPIO_Pin_12);
			Delay(0x5fffff);
			GPIO_ResetBits(GPIOD , GPIO_Pin_12);

			GPIO_SetBits(GPIOD , GPIO_Pin_12);
			Delay(0x5fffff);
			GPIO_ResetBits(GPIOD , GPIO_Pin_12);
			
			GPIO_SetBits(GPIOD , GPIO_Pin_13);
			Delay(0x5fffff);
			GPIO_ResetBits(GPIOD , GPIO_Pin_13);
			
			GPIO_SetBits(GPIOD , GPIO_Pin_14);
			Delay(0x5fffff);
			GPIO_ResetBits(GPIOD , GPIO_Pin_14);
			
			GPIO_SetBits(GPIOD , GPIO_Pin_15);
			Delay(0x5fffff);
			GPIO_ResetBits(GPIOD , GPIO_Pin_15);
				break;
			}
	}
}

/*******************************************************************************
* Function Name  : Delay
* Description    : Delay Time
* Input          : - nCount: Delay Time
* Output         : None
* Return         : None
* Attention		 : None
*******************************************************************************/
void  Delay(uint32_t nCount)
{
  for(; nCount != 0; nCount--);
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {

  }
}
#endif

/**
  * @}
  */ 

/**
  * @}
  */ 

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
