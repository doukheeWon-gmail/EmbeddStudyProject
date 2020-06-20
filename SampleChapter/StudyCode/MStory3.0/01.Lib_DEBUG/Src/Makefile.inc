###########################################################
# GCC template makefile
###########################################################


#add cc2520 Library
SUB_ARCH := 
SUB_ARCH += ../cc2520/Src
SUB_ARCH := $(addprefix $(TOP)/SampleChapter/MStory3.0/01.Lib_DEBUG/, $(SUB_ARCH))

vpath %.s $(SUB_ARCH)
vpath %.c $(SUB_ARCH)

sinclude %(addsuffix /Makefile.inc, $(SUB_ARCH))


LIB_DEBUG_SOURCES = 

LIB_DEBUG_SOURCES += syscalls.c
LIB_DEBUG_SOURCES += main.c

EXTRAINCDIRS += $(TOP)/SampleChapter/MStory3.0/01.Lib_DEBUG/Inc

C_SOURCES += $(LIB_DEBUG_SOURCES)