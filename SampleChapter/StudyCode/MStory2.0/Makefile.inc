###########################################################
# GCC template makefile
###########################################################


ifeq ($(CONFIG_MSTORY_V2_0_SRC_LED_1), y)

    SUB_ARCH := 
    SUB_ARCH += 01.M32.Src001.LedOn/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_MSTORY_V2_0_SRC_LED_2), y)

    SUB_ARCH := 
    SUB_ARCH += 02.M32.Src001.LedOn.2009.1022.1419/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))


else ifeq ($(CONFIG_MSTORY_V2_0_SRC_LED_3), y)

    SUB_ARCH :=
    SUB_ARCH += 03.M32.Src003.LedOff/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_MSTORY_V2_0_SRC_LED_4), y)

    SUB_ARCH :=
    SUB_ARCH += 04.M32.Src005.LedAllOnOff/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_MSTORY_V2_0_SRC_LED_5), y)

    SUB_ARCH :=
    SUB_ARCH += 05.M32.Src006.LedAllOnOff.New1/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_MSTORY_V2_0_SRC_LED_6), y)
    SUB_ARCH :=
    SUB_ARCH += 06.M32.Src007.LedAllOnOff.New2/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.0/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_MSTORY_V2_0_SRC_KEY_PRESS), y)

    SUB_ARCH :=
    SUB_ARCH += 07.M32.Src008.KeyPress/Src

    SUB_ARCH := $(addprefix $(TOP)/SampleChapter/StudyCode/MStory2.o, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

endif

