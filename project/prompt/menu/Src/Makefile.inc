###########################################################
# GCC template makefile
###########################################################

MAIN_MENU_SOURCES = 
MAIN_MENU_SOURCES += main_menu.c

#EXTRA INCLUDE Header
EXTRAINCDIRS += $(TOP)/project/prompt/menu/Inc

C_SOURCES += $(MAIN_MENU_SOURCES)