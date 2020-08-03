###########################################################
# GCC template makefile
###########################################################
ifeq ($(CONFIG_PRINTF_TEST_M4), y)
SUB_ARCH := 
SUB_ARCH += Printf/Src

SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MANGOSTM32F4/, $(SUB_ARCH))

vpath %.c $(SUB_ARCH)
vpath %.s $(SUB_ARCH)

sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

endif