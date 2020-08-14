###########################################################
# GCC template makefile
###########################################################

ifeq ($(CONFIG_HAL_EMPTY), y)
    
    SUB_ARCH := 
    SUB_ARCH += 01.EmptySource/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/Hal_EX/stm32F103/, $(SUB_ARCH))

    vpath %.s $(SUB_ARCH)
    vpath %.c $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else

endif