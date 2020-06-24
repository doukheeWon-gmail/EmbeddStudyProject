###########################################################
# GCC template makefile
###########################################################

PROMPT_SOURCES = 
PROMPT_SOURCES += main.c
PROMPT_SOURCES += hw_config.c
PROMPT_SOURCES += stm32f10x_it.c
PROMPT_SOURCES += syscalls.c

EXTRAINCDIRS += $(TOP)/project/prompt/Inc