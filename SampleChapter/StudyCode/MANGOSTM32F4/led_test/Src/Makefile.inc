###########################################################
# GCC template makefile
###########################################################

STM32F407_LED_TEST_SOURCES = 
STM32F407_LED_TEST_SOURCES += stm32f4xx_it.c
STM32F407_LED_TEST_SOURCES += hw_config.c
STM32F407_LED_TEST_SOURCES += syscalls.c
STM32F407_LED_TEST_SOURCES += main.c
STM32F407_LED_TEST_SOURCES += led.c

EXTRAINCDIRS += $(TOP)/SampleChapter/StudyCode/MANGOSTM32F4/led_test/Inc

C_SOURCES += $(STM32F407_LED_TEST_SOURCES)