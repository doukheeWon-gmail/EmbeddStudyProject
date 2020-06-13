#현재 위치 설정
TOP = .

#makefile 버전정의
VERSION = 2020
PATCHLEVEL = 0
SUBLEVEL =
EXTRAVERSION =
NAME =


#bin File name
TARGET = Sample

include $(TOP)/inc.mk

-include .config

#Custom makefile version 
#VERSION 만약 PATCHLEVEL이 있을 경우, PATCHLEVEL을 표현
CUSTOMVERSION = v$(VERSION)$(if $(PATCHLEVEL),.$(PATCHLEVEL)$(if $(SUBLEVEL),.$(SUBLEVEL))) $(EXTRAVERSION)

#Get HOST OS Make lower
HOSTOS := $(shell uname -s | tr '[:upper:]' '[:lower:]' | \
	    sed -e 's/\(cygwin\).*/cygwin/')

export HOSTOS


#BUILD arm-none-eabi-gcc

#FOLDERS  := $(shell ls -R sampleSource kernel | grep : | sed 's/://')

#Source File %.c
SRCS += $(C_SOURCES)
#Source File %.cpp
CPPSRCS += $(CPP_SOURCES)
#List Assmbler sources files here.
ASM_SOURCES = 


#Get Folder 
#SUB_DIRS  := $(shell ls -R sampleSource kernel Project | grep : | sed 's/://')
SUB_DIRS := 
SUB_DIRS += CMSIS
SUB_DIRS += driver
SUB_DIRS += kernel
SUB_DIRS += SampleChapter
SUB_DIRS += module
SUB_DIRS += project
#SUB_DIRS += $(FOLDERS)

#SUB_DIRS ADD USE KCONFIG
SUB_DIRS += PersonalProject/$(CONFIG_SUB_DIRS_NAME)

#Path make full path
SUB_DIRS := $(addprefix $(TOP)/,$(SUB_DIRS))

#auto find c file and compling sources
vpath %.c $(SUB_DIRS)
#auto find assembler file and compling sources
vpath %.s $(SUB_DIRS)
#auto find cpp file and compling sources
vpath %.cpp $(SUB_DIRS)

#Include Sub Makefile
sinclude $(addsuffix /Makefile.inc,$(SUB_DIRS))



#LIBC_LIB = -L $(shell dirname `$(CC) $(ALL_CFLAGS) -print-file-name=libc.a`) -lc
#MATH_LIB = -L $(shell dirname `$(CC) $(ALL_CFLAGS) -print-file-name=libm.a`) -lm
#LIBGCC_LIB += -L $(shell dirname `$(CC) $(ALL_CFLAGS) -print-libgcc-file-name`) -lgcc
# CPLUSPLUS_LIB = -lstdc++

# Linker flags.
#  -Wl,...:     tell GCC to pass this to linker.
#    -Map:      create map file
#    --cref:    add cross reference to  map file
#LDFLAGS = -Map=$(TARGET).map --cref
#Linker script flash 
FLASH_LDSCRIPT = LinkerScripts/stm32f10x103/STM32F103RBTx_FLASH.ld
#Linker script rom 
ROM_LDSCRIPT = LinkerScripts/stm32f10x103/STM32F103RBTx_ROM.ld
#linker lib add float library add -spec=nano.spec -u_printf_float not use system file syscall file _write _read _getpid _close
LD_LIBS = -lc -lm -lnosys -specs=nano.specs -u _printf_float -u _scanf_float -static
#linker flag 
LDFLAGS = $(MCU) $(LD_LIBS) -Wl,-Map=$(OUT_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

LDFLAGS += $(patsubst %,-L%, $(EXTRA_LIBDIRS))
LDFLAGS += $(patsubst %,-L%, $(EXTRA_LIBS))
#Linker Script add
LDFLAGS += -T$(FLASH_LDSCRIPT)


#include Rule
all: projectversion gccversion build sizeinfo


include $(TOP)/rule.mk


#kconfig Test
file:
	@echo "Include Folder - $(SUB_DIRS)"
	@echo "Include Source File - $(SRCS)"

#build options
build: clean createdirs elf bin lss sym sizeinfo flashLoader
lss: $(BUILD_DIR)/$(TARGET).lss
bin: $(BUILD_DIR)/$(TARGET).bin
sym: $(BUILD_DIR)/$(TARGET).sym


#Start Download Use minicom
minicom:
	@echo "Start MINICOM USE Flag -s"
	@minicom -s

#flash Loader ~/stm32ld
flashLoader:
	./download.sh $(BUILD_DIR) $(TARGET)

#version show
version:
	@echo "Custom Embedded Sample Code $(CUSTOMVERSION)"

#config use ncurses
menuconfig: version
	@$(MAKE) -f scripts/Makefile $@


#all delete
distclean:
	$(REMOVE) $(OUT_DIR)
	$(REMOVE) $(BUILD_DIR)
	$(REMOVE) $(LIB_DIR)
	$(REMOVE) build $(TOP)/include .config .config.old
	@$(MAKE) -f scripts/Makefile clean

#Make Command explain
help:
	@echo "----Sample Embedded Study Project $(CUSTOMVERSION)--- "
	@echo menuconfig - "GUI Config Sample Code, Select Board "
	@echo distclean - "All Object File, Folder Delete"
	@echo clean - "Folder Delete"
	@echo version - "Show this project Version"
	@echo file - "Get Inlclude Folder and Source File"
	@echo sizeinfo - "Get Binaray File Size"
	@echo gccversion - "Get arm-none-eabi-gcc version Check"
	@echo createdirs - "Make Object, Binary, hex file In Folder Name"	
	@$(MAKE) -f scripts/Makefile help
