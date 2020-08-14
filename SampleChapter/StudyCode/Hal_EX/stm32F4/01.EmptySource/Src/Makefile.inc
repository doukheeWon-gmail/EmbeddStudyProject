###########################################################
# GCC template makefile
###########################################################

M4_EMPTY_SOURCE = 
M4_EMPTY_SOURCE += gpio.c
M4_EMPTY_SOURCE += main.c
M4_EMPTY_SOURCE += stm32f4xx_hal_msp.c
M4_EMPTY_SOURCE += stm32f4xx_it.c
M4_EMPTY_SOURCE += system_stm32f4xx.c
M4_EMPTY_SOURCE += usart.c

EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/Hal_EX/stm32F4/01.EmptySource/Inc

C_SOURCES += $(M4_EMPTY_SOURCE)

