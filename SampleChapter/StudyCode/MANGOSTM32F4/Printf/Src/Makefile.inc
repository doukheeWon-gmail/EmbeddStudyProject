###########################################################
# GCC template makefile
###########################################################


STM32F4_PRINT_SOURCES = 
STM32F4_PRINT_SOURCES += main.c
STM32F4_PRINT_SOURCES += stm32f4xx_it.c
STM32F4_PRINT_SOURCES += usart.c


C_SOURCES += $(STM32F4_PRINT_SOURCES)


