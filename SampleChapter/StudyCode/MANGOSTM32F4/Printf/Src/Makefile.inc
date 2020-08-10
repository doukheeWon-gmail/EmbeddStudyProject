###########################################################
# GCC template makefile
###########################################################


STM32F4_PRINT_SOURCES = 
STM32F4_PRINT_SOURCES += main.c
STM32F4_PRINT_SOURCES += stm32f4xx_it.c
STM32F4_PRINT_SOURCES += usart.c
STM32F4_PRINT_SOURCES += syscalls.c


C_SOURCES += $(STM32F4_PRINT_SOURCES)


EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MANGOSTM32F4/Printf/Inc