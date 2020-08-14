###########################################################
# GCC template makefile
###########################################################

EMPTY_SOURCES = 
EMPTY_SOURCES += gpio.c
EMPTY_SOURCES += main.c
EMPTY_SOURCES += stm32f1xx_hal_msp.c
EMPTY_SOURCES += stm32f1xx_it.c
EMPTY_SOURCES += system_stm32f1xx.c
EMPTY_SOURCES += usart.c

EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/Hal_EX/stm32F103/01.EmptySource/Inc

C_SOURCES += $(EMPTY_SOURCES)