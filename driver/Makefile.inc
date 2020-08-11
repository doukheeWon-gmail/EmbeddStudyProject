###########################################################
# GCC template makefile
###########################################################


ifeq ($(CONFIG_STANDARD_DRIVER), y)

SUB_ARCH := 
#Standard Driver
SUB_ARCH += STM32F10x_StdPeriph_Driver/Src

SUB_ARCH := $(addprefix $(TOP)/driver/, $(SUB_ARCH))

vpath %.c $(SUB_ARCH)
vpath %.s $(SUB_ARCH)

sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_HAL_DRIVER), y)

SUB_ARCH := 
#HAL Driver
SUB_ARCH += STM32F1xx_HAL_Driver/Src

SUB_ARCH := $(addprefix $(TOP)/driver/, $(SUB_ARCH))

vpath %.c $(SUB_ARCH)
vpath %.s $(SUB_ARCH)

sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_HAL_DRIVER_M4), y)
    
    SUB_ARCH := 
    SUB_ARCH += STM32F4xx_HAL_Driver/Src

    SUB_ARCH := $(addprefix $(TOP)/driver/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_STANDARD_DRIVER_M4), y)

    SUB_ARCH := 
    SUB_ARCH += STM32F4xx_StdPeriph_Driver/Src

    SUB_ARCH := $(addprefix $(TOP)/driver/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else

#TODO
#echo not select driver 

endif

#USB Driver Library
ifeq ($(CONFIG_USB_FS_DEVICE_DRIVER), y)
    SUB_ARCH := 
    SUB_ARCH += STM32_USB-FS-Device_Driver/Src

    SUB_ARCH := $(addprefix $(TOP)/driver/, $(SUB_ARCH))

    vpath %.c $(SUB_ARCH)
    vpath %.s $(SUB_ARCH)

    sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

endif