###########################################################
# GCC template makefile
###########################################################


EMPTY_SOURCES = 
EMPTY_SOURCES += hw_config.c
EMPTY_SOURCES += main.c
EMPTY_SOURCES += stm32f10x_it.c
EMPTY_SOURCES += syscalls.c


#Select Empty

ifeq ($(CONFIG_EMPTY), y)

EXTRAINCDIRS += $(TOP)/SampleChapter/EmptySource/Inc

C_SOURCES += $(EMPTY_SOURCES)

endif