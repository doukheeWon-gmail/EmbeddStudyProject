###########################################################
# GCC template makefile
###########################################################

SUB_ARCH := 
SUB_ARCH += MStory2.0
SUB_ARCH += MStory3.0
SUB_ARCH += MANGOSTM32F4
SUB_ARCH += Hal_EX

SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/, $(SUB_ARCH))

vpath %.c $(SUB_ARCH)
vpath %.s $(SUB_ARCH)

sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))