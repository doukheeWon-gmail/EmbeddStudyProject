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

else ifeq ($(CONFIG_LED_TEST_M4),y)

    SUB_ARCH :=
    SUB_ARCH += 01.LED_OnOff/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MANGOSTM32F4/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_KEY_TEST_M4),y)

    SUB_ARCH :=
    SUB_ARCH += 02.Button_Push/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MANGOSTM32F4/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else

endif