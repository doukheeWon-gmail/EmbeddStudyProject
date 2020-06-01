###########################################################
# GCC template makefile
###########################################################


ifeq ($(CONFIG_STANDARD_DRIVER), y)
#Standard Driver
SUB_ARCH += STM32F10x_StdPeriph_Driver/Src

SUB_ARCH := $(addprefix $(TOP)/driver/, $(SUB_ARCH))

vpath %.c $(SUB_ARCH)
vpath %.s $(SUB_ARCH)

sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))

else ifeq ($(CONFIG_HAL_DRIVER), y)

#HAL Driver
SUB_ARCH += STM32F1xx_HAL_Driver/Src

SUB_ARCH := $(addprefix $(TOP)/driver/, $(SUB_ARCH))

vpath %.c $(SUB_ARCH)
vpath %.s $(SUB_ARCH)

sinclude $(addsuffix /Makefile.inc, $(SUB_ARCH))


else

#TODO
#echo not select driver 

endif