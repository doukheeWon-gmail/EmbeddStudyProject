#include "usart.h"
/*******************************************************************************************************************************
 * 函数名：USART1_Conf()
 * 参数：无
 *返回值：无
 * 功能：配置USART1，并初始化
********************************************************************************************************************************/																		
void USART1_Conf(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;                                          //定义GPIO初始化结构体
	USART_InitTypeDef USART_InitStructure;                                        //定义USART初始化结构体
	   RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA|RCC_AHB1Periph_GPIOC|RCC_AHB1Periph_GPIOB, ENABLE);		
	GPIO_PinAFConfig(GPIOA,GPIO_PinSource2,GPIO_AF_USART3);						  //配置PA2复用连接到USART2
	/*配置复用管脚TXD(PA2)和RXD(PA3)连接到USART1*/
    GPIO_PinAFConfig(GPIOA,GPIO_PinSource3,GPIO_AF_USART3);					  //配置PA3复用连接到USART2
		/*配置USART1相应的时钟*/
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC,ENABLE);                          //使能GPIOA的AHB1时钟
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART2, ENABLE);                        //使能USART2的APB2时钟
	/*配置USART1的发送管脚TXD(PA2)为复用推挽输出*/
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_2;                                       //设置初始化GPIO为PIN2
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;                               //设置GPIO的速度为50MHz
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;                                    //设置GPIO模式为复用模式
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;								  //设置GPIO输出类型为推挽输出
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;						          //设置GPIO为连接上拉电阻
	GPIO_Init(GPIOA,&GPIO_InitStructure);                                         //初始化GPIOA的PIN2
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3;                                      //设置初始化GPIO为PIN3
	/*配置USART1的接收管脚RXD(PA3)为浮空输入*/
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF;                                    //设置GPIO的模式为复用模式
	GPIO_Init(GPIOA,&GPIO_InitStructure);                                         //初始化GPIOA的PIN3

	/*配置USART1的模式*/
    USART_InitStructure.USART_BaudRate=115200;                                    //设置USART的波特率为115200
    USART_InitStructure.USART_Parity=USART_Parity_No;                             //设置USART的校验位为None
    USART_InitStructure.USART_WordLength=USART_WordLength_8b;                     //设置USART的数据位为8bit
    USART_InitStructure.USART_StopBits=USART_StopBits_1;                          //设置USART的停止位为1
    USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None; //失能硬件流控制
    USART_InitStructure.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;                   //设置USART的模式为发送接收模式
    USART_Init(USART2,&USART_InitStructure);                                      //初始化USART1
    USART_Cmd(USART2,ENABLE);                                                     //使能USART1
}


/********************************************************************************************************************************
*函数名：fputc()
* 参数：int ch，FILE *f
* 返回值：int
* 功能：重新定义stdio.h中的fputc()函数，使printf()输出到USART1
*********************************************************************************************************************************/
int fputc(int ch,FILE *f)
{
  USART_SendData(USART2,(u8)ch);	                                                   //将ch从USART1发送出去
  while (USART_GetFlagStatus(USART2, USART_FLAG_TXE) == RESET)				       //等待发送完毕
  {
  }											  
  return ch;																	   //返回 ch
}																		           








