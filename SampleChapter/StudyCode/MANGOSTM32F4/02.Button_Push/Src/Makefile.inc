###########################################################
# GCC template makefile
###########################################################

STM32F4_KEY_SOURCES = 
STM32F4_KEY_SOURCES += hw_config.c
STM32F4_KEY_SOURCES += key.c
STM32F4_KEY_SOURCES += led.c
STM32F4_KEY_SOURCES += stm32f4xx_it.c
STM32F4_KEY_SOURCES += syscalls.c
STM32F4_KEY_SOURCES += main.c


EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MANGOSTM32F4/02.Button_Push/Inc


C_SOURCES += $(STM32F4_KEY_SOURCES)