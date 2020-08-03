###########################################################
# GCC template makefile
###########################################################


DRIVER_SOURCES = 
DRIVER_SOURCES += stm32f4xx_hal.c
DRIVER_SOURCES += stm32f4xx_hal_adc.c
DRIVER_SOURCES += stm32f4xx_hal_adc_ex.c
DRIVER_SOURCES += stm32f4xx_hal_can.c
DRIVER_SOURCES += stm32f10x_can.c
DRIVER_SOURCES += stm32f4xx_hal_cortex.c
DRIVER_SOURCES += stm32f4xx_hal_crc.c
DRIVER_SOURCES += stm32f10x_dbgmcu.c
DRIVER_SOURCES += stm32f4xx_hal_cryp.c
DRIVER_SOURCES += stm32f4xx_hal_cryp_ex.c
DRIVER_SOURCES += stm32f4xx_hal_dac.c
DRIVER_SOURCES += stm32f4xx_hal_dac_ex.c
DRIVER_SOURCES += stm32f4xx_hal_dcmi.c
DRIVER_SOURCES += stm32f4xx_hal_dma_ex.c
DRIVER_SOURCES += stm32f4xx_hal_dma.c
DRIVER_SOURCES += stm32f4xx_hal_dma2d.c
DRIVER_SOURCES += stm32f4xx_hal_eth.c
DRIVER_SOURCES += stm32f4xx_hal_flash_ex.c
DRIVER_SOURCES += stm32f4xx_hal_flash.c
DRIVER_SOURCES += stm32f4xx_hal_gpio.c
DRIVER_SOURCES += stm32f4xx_hal_hash.c
DRIVER_SOURCES += stm32f4xx_hal_hash_ex.c
DRIVER_SOURCES += stm32f4xx_hal_hcd.c
DRIVER_SOURCES += stm32f4xx_hal_i2c.c
DRIVER_SOURCES += stm32f4xx_hal_i2c_ex.c
DRIVER_SOURCES += stm32f4xx_hal_i2s.c
DRIVER_SOURCES += stm32f4xx_hal_i2s_ex.c
DRIVER_SOURCES += stm32f4xx_hal_irda.c
DRIVER_SOURCES += stm32f4xx_hal_iwdg.c
DRIVER_SOURCES += stm32f4xx_hal_ltdc.c
DRIVER_SOURCES += stm32f4xx_hal_msp_template.c
DRIVER_SOURCES += stm32f4xx_hal_nand.c
DRIVER_SOURCES += stm32f4xx_hal_nor.c
DRIVER_SOURCES += stm32f4xx_hal_pccard.c
DRIVER_SOURCES += stm32f4xx_hal_pcd.c
DRIVER_SOURCES += stm32f4xx_hal_pwr.c
DRIVER_SOURCES += stm32f4xx_hal_pwr_ex.c
DRIVER_SOURCES += stm32f4xx_hal_rcc.c
DRIVER_SOURCES += stm32f4xx_hal_rcc_ex.c
DRIVER_SOURCES += stm32f4xx_hal_rng.c
DRIVER_SOURCES += stm32f4xx_hal_rtc.c
DRIVER_SOURCES += stm32f4xx_hal_rtc_ex.c
DRIVER_SOURCES += stm32f4xx_hal_sai.c
DRIVER_SOURCES += stm32f4xx_hal_sd.c
DRIVER_SOURCES += stm32f4xx_hal_sdram.c
DRIVER_SOURCES += stm32f4xx_hal_smartcard.c
DRIVER_SOURCES += stm32f4xx_hal_spi.c
DRIVER_SOURCES += stm32f4xx_hal_sram.c
DRIVER_SOURCES += stm32f4xx_hal_tim.c
DRIVER_SOURCES += stm32f4xx_hal_tim_ex.c
DRIVER_SOURCES += stm32f4xx_hal_uart.c
DRIVER_SOURCES += stm32f4xx_hal_usart.c
DRIVER_SOURCES += stm32f4xx_hal_wwdg.c
DRIVER_SOURCES += stm32f4xx_ll_fmc.c
DRIVER_SOURCES += stm32f4xx_ll_fsmc.c
DRIVER_SOURCES += stm32f4xx_ll_sdmmc.c
DRIVER_SOURCES += stm32f4xx_ll_usb.c

EXTRAINCDIRS += $(TOP)/driver/STM32F4xx_HAL_Driver/Inc

C_SOURCES += $(DRIVER_SOURCES)