###########################################################
# GCC template makefile
###########################################################

#core cortex m3

SUB_ARCH :=
SUB_ARCH += Core/CM3
SUB_ARCH += Core/CM3/startup/gcc

SUB_ARCH := $(addprefix $(TOP)/CMSIS/, $(SUB_ARCH))

vpath %.c $(SUB_ARCH)
vpath %.s $(SUB_ARCH)


#include sub makefile add
sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))


#include Header File
EXTRAINCDIRS += $(TOP)/CMSIS/Core/CM3
