###########################################################
# GCC template makefile
###########################################################

STM32F4_KEY_EXTI_SOURCES = 
STM32F4_KEY_EXTI_SOURCES += hw_config.c
STM32F4_KEY_EXTI_SOURCES += key.c
STM32F4_KEY_EXTI_SOURCES += led.c
STM32F4_KEY_EXTI_SOURCES += stm32f4xx_it.c
STM32F4_KEY_EXTI_SOURCES += syscalls.c
STM32F4_KEY_EXTI_SOURCES += main.c


EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MANGOSTM32F4/03.Button_Push_EXTI/Inc


C_SOURCES += $(STM32F4_KEY_EXTI_SOURCES)