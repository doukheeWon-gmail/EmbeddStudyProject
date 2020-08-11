###########################################################
# GCC template makefile
###########################################################


ifeq ($(CONFIG_CC2520), y)

    SUB_ARCH :=
    SUB_ARCH += cc2520/Src

    SUB_ARCH := $(addprefix $(TOP)/module/, $(SUB_ARCH))

    vpath %.s $(SUB_ARCH)
    vpath %.c $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

endif

ifeq ($(CONFIG_USB_HID), y)
    SUB_ARCH :=
    SUB_ARCH += USB.HID/Src
    
    SUB_ARCH := $(addprefix $(TOP)/module/, $(SUB_ARCH))

    vpath %.s $(SUB_ARCH)
    vpath %.c $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

endif