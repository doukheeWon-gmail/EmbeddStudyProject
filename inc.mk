###########################################################
# GCC template makefile
###########################################################

MODEL = 
SUBMODEL = makeProject


#prefix GCC (cross compiler)
PREFIX = arm-none-eabi-

#REMOVE COMMAND
REMOVE_CMD = rm

#shell use bash
SHELL = sh

#Cross Compiler 
CC = $(PREFIX)gcc
CPP = $(PREFIX)g++
AR = $(PREFIX)ar
LD = $(PREFIX)ld
OBJCOPY = $(PREFIX)objcopy
OBJDUMP = $(PREFIX)objdump
SIZE = $(PREFIX)size
NM = $(PREFIX)nm
REMOVE = $(REMOVE_CMD) -rf

#kconfig file Include
-include .config

#####################################################################
# CFLAGS
#####################################################################

#Cpu architecture
ifeq ($(CONFIG_MANGO_M3), y)
CPU = -mcpu=cortex-m3

#Floating point unit
FPU = 

FLOAT-ABI = 

endif

ifeq ($(CONFIG_MANGO_Z1), y)
CPU = -mcpu=cortex-m3

#Floating point unit
FPU = 

FLOAT-ABI = 

endif

ifeq ($(CONFIG_MANGO_M4), y)
CPU = -mcpu=cortex-m4

# fpu
FPU = -mfpu=fpv4-sp-d16
# float-abi
FLOAT-ABI = -mfloat-abi=hard

endif


#CPU Flag Setting 
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

## Output format. (can be ihex or binary)
## (binary i.e. for openocd and SAM-BA, hex i.e. for lpc21isp and uVision)
#OUTPUT Format  settting

#FORMAT = ihex
FORMAT = binary

# Optimization level, can be [0, 1, 2, 3, s].
# 0 = turn off optimization. s = optimize for size.
# (Note: 3 is not always the best optimization level. See avr-libc FAQ.)
OPT = g

# Debugging format.
# Native formats for GCC's -g are stabs [default], or dwarf-2.
#DEBUG = stabs
DEBUG = dwarf-2

#define Set up
# Place -D or -U options for C here
#CDEFS =  -D$(RUN_MODE)



#Default define flag It is use CMSIS Driver
C_DEFS = \
-D USE_STDPERIPH_DRIVER 

#board mango-z1
ifeq ($(CONFIG_MANGO_Z1), y)
C_DEFS += \
-D BOARD_DEF_MANGO_Z1
endif

#config mango-m3
ifeq ($(CONFIG_MANGO_M3), y)
C_DEFS += \
-D BOARD_DEF_MANGO_M32
endif

ifeq ($(CONFIG_MANGO_M4), y)
C_DEFS += \
-D STM32F407xx \
-D STM32F40_41xxx
endif

#Place -D or -U options for ASM here
#ADEFS = -D$(RUN_MODE)
#Assembler Define Flag 
ADEFS = 

# Compiler flags.
#  -g*:          generate debugging information
#  -O*:          optimization level
#  -f...:        tuning, see GCC manual and avr-libc documentation
#  -Wall...:     warning level
#  -Wa,...:      tell GCC to pass this to the assembler.
#    -adhlns...: create assembler listing
#

COMFLAGS = -Wall -fdata-sections -ffunction-sections

#Flags for C and C++ (arm-elf-gcc/arm-elf-g++)
CFLAGS = -g$(DEBUG)
CFLAGS += $(C_DEFS) $(C_INCLUDES)
CFLAGS += -O$(OPT)
CFLAGS += -Wcast-align -Wimplicit
CFLAGS += -Wredundant-decls -Wreturn-type -Wshadow -Wunused
CFLAGS += $(COMFLAGS)
#add prefix Header Include 
CFLAGS += $(patsubst %,-I%,$(EXTRAINCDIRS))
ASFLAGS = $(COMFLAGS)
#flags only for C
CONLYFLAGS += -Wnested-externs

# Compiler flag to set the C Standard level.
# c89   - "ANSI" C
# gnu89 - c89 plus GCC extensions
# c99   - ISO C99 standard (not yet fully implemented)
# gnu99 - c99 plus GCC extensions
CONLYFLAGS += -std=gnu99

#warings with
CFLAGS += -Wcast-qual
CONLYFLAGS += -Wmissing-prototypes
CONLYFLAGS += -Wstrict-prototypes
CONLYFLAGS += -Wmissing-declarations


#output directory
LIB_DIR := $(TOP)/lib.$(SUBMODEL)
OUT_DIR := $(TOP)/obj.$(SUBMODEL)
BUILD_DIR := $(TOP)/bin.$(SUBMODEL)
PRJ_LIBS := 