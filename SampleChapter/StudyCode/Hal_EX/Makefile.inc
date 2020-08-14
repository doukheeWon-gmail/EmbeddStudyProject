###########################################################
# GCC template makefile
###########################################################

SUB_ARCH := 
SUB_ARCH += stm32F4
SUB_ARCH += stm32F103

SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/Hal_EX/, $(SUB_ARCH))

vpath %.s $(SUB_ARCH)
vpath %.c $(SUB_ARCH)

sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))