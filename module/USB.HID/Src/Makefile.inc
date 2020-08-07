###########################################################
# GCC template makefile
###########################################################

USB_HID_SOURCE = 
USB_HID_SOURCE += usb_desc.c
USB_HID_SOURCE += usb_endp.c
USB_HID_SOURCE += usb_istr.c
USB_HID_SOURCE += usb_prop.c
USB_HID_SOURCE += usb_pwr.c

EXTRAINCDIRS += $(TOP)/module/USB.HID/Inc

C_SOURCES += $(USB_HID_SOURCE)

