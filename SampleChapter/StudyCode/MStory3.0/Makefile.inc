###########################################################
# GCC template makefile
###########################################################


ifeq ($(CONFIG_MSTORY_V3_0_SRC_LIB_DEBUG), y)

    SUB_ARCH := 
    SUB_ARCH += 01.Lib_DEBUG/Src
    SUB_ARCH += 01.Lib_DEBUG/cc2520/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory3.0/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else 

endif