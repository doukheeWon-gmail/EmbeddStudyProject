###########################################################
# GCC template makefile
###########################################################

ifeq ($(CONFIG_MANGO_M4), y)
    SUB_ARCH := 
    SUB_ARCH += Core/CM4/startup
    SUB_ARCH += Core/CM4/startup/gcc

    SUB_ARCH := $(addprefix $(TOP)/CMSIS/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_HAL_DRIVER), y)
    #cortex cm3
    SUB_ARCH :=
    SUB_ARCH += Core/CMSIS/Device/ST/STM32F1xx/Source/Templates

    SUB_ARCH := $(addprefix $(TOP)/CMSIS/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

    EXTRAINCDIRS += $(TOP)/CMSIS/Core/CMSIS/Inc

else ifeq ($(CONFIG_HAL_DRIVER_M4), y)
    #cortex cm4
    SUB_ARCH :=
    SUB_ARCH += Core/CMSIS/Device/ST/STM32F4xx/Source/Templates

    SUB_ARCH := $(addprefix $(TOP)/CMSIS/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

    EXTRAINCDIRS += $(TOP)/CMSIS/Core/CMSIS/Inc

else

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
endif