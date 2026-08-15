/**
 * @file board.h
 * Board definition: Custom ESP32-S3 ILI9341 6-Button Board
 *
 * MCU:      ESP32-S3
 * Display:  st7789 135x240 RGB565 via SPI
 * Input:    6 discrete buttons
 * SubGHz:   CC1101 via SPI
 * NFC:      PN532 via I2C
 * SD Card:  SPI
 * IR:       TX + RX
 * RGB LED:  WS2812 x1 (IO48)
 */

#pragma once

/* ---- Board metadata ---- */
#define BOARD_NAME        "esp32s3_6buttons"
#define BOARD_TARGET      "esp32s3"

/* ---- Hardware Button Pins ---- */
#define BOARD_PIN_BTN_UP        41
#define BOARD_PIN_BTN_DOWN      40
#define BOARD_PIN_BTN_LEFT      39
#define BOARD_PIN_BTN_RIGHT     38
#define BOARD_PIN_BTN_OK        0
#define BOARD_PIN_BTN_BACK      1
#define BOARD_PIN_BUTTON_BOOT   0  

/* ---- LCD Pins (ILI9341 via SPI) ---- */
#define BOARD_PIN_LCD_MOSI      17
#define BOARD_PIN_LCD_SCLK      18
#define BOARD_PIN_LCD_DC        15
#define BOARD_PIN_LCD_CS        7
#define BOARD_PIN_LCD_RST       16
#define BOARD_PIN_LCD_BL        6

/* ---- LCD Display Configuration ---- */
#define BOARD_LCD_H_RES         240    
#define BOARD_LCD_V_RES         135     
#define BOARD_LCD_SPI_HOST      SPI2_HOST
#define BOARD_LCD_SPI_FREQ_HZ   (20 * 1000 * 1000)
#define BOARD_LCD_CMD_BITS      8
#define BOARD_LCD_PARAM_BITS    8
#define BOARD_LCD_SWAP_XY       true
#define BOARD_LCD_MIRROR_X      true
#define BOARD_LCD_MIRROR_Y      false
#define BOARD_LCD_INVERT_COLOR  true   
#define BOARD_LCD_GAP_X         40
#define BOARD_LCD_GAP_Y         53
#define BOARD_LCD_BL_ACTIVE_LOW false
#define BOARD_LCD_COLOR_ORDER_BGR false

/* Flipper framebuffer → display color mapping (RGB565, native byte order) */
#define BOARD_LCD_FG_COLOR      0x40FD  /* Flipper Orange 0xFDA0 byte-swapped for S3 SPI */
#define BOARD_LCD_FG_COLOR_RB   0x5F03  /* Same orange with R/B swapped (0x035F swapped) — for post-flash BGR state */
#define BOARD_LCD_BG_COLOR      0xFC00

/* ---- SD Card Pins ---- */
#define BOARD_PIN_SD_CS         3
#define BOARD_PIN_SD_MISO       8
#define BOARD_PIN_SD_MOSI       17
#define BOARD_PIN_SD_SCLK       18

/* ---- Touch Controller — NOT PRESENT ---- */
#define BOARD_PIN_TOUCH_SCL     UINT16_MAX
#define BOARD_PIN_TOUCH_SDA     UINT16_MAX
#define BOARD_PIN_TOUCH_RST     UINT16_MAX
#define BOARD_PIN_TOUCH_INT     UINT16_MAX
#define BOARD_TOUCH_I2C_ADDR    0x00
#define BOARD_TOUCH_I2C_PORT    I2C_NUM_0
#define BOARD_TOUCH_I2C_FREQ_HZ 0
#define BOARD_TOUCH_I2C_TIMEOUT 0

/* ---- SubGHz / CC1101 ---- */
#define BOARD_PIN_CC1101_SCK    13
#define BOARD_PIN_CC1101_CSN    46
#define BOARD_PIN_CC1101_MISO   11
#define BOARD_PIN_CC1101_MOSI   12
#define BOARD_PIN_CC1101_GDO0   9
#define BOARD_PIN_CC1101_GDO2   10
#define BOARD_CC1101_SPI_HOST   SPI3_HOST
#define BOARD_CC1101_SPI_SHARED 0


/* ---- NRF24L01 ---- */
#define BOARD_PIN_NRF24_SCK     13
#define BOARD_PIN_NRF24_MISO    11
#define BOARD_PIN_NRF24_MOSI    12
#define BOARD_PIN_NRF24_CSN     14
#define BOARD_PIN_NRF24_CE      21
#define BOARD_HAS_NRF24         1

/* ---- Power Enable ---- */
//#define BOARD_PIN_PWR_EN        5

/* ---- IR ---- */
#define BOARD_PIN_IR_TX         5  
#define BOARD_PIN_IR_RX         4 

/* ---- NFC / PN532 (via I2C) ---- */
#define BOARD_PIN_NFC_SCL       48
#define BOARD_PIN_NFC_SDA       47
//#define BOARD_PIN_NFC_IRQ       UINT16_MAX attempted fix
//#define BOARD_PIN_NFC_RST       UINT16_MAX attempted fix
#define BOARD_NFC_I2C_PORT      I2C_NUM_0

/* ---- Speaker (I2S) ---- */
#define BOARD_PIN_SPEAKER_BCLK  UINT16_MAX
#define BOARD_PIN_SPEAKER_WCLK  UINT16_MAX
#define BOARD_PIN_SPEAKER_DOUT  UINT16_MAX

/* ---- WS2812 RGB LED ---- */
#define BOARD_PIN_WS2812_DATA   45
#define BOARD_WS2812_LED_COUNT  1

/* ---- Microphone ---- */
#define BOARD_PIN_MIC_DATA      UINT16_MAX
#define BOARD_PIN_MIC_CLK       UINT16_MAX

/* ---- Qwiic / External I2C ---- */
#define BOARD_PIN_QWIIC_SDA     47
#define BOARD_PIN_QWIIC_SCL     42

/* ---- Features ---- */
#define BOARD_HAS_TOUCH         0
#define BOARD_HAS_ENCODER       0
#define BOARD_HAS_SD_CARD       1
#define BOARD_HAS_BLE           1
#define BOARD_HAS_RGB_LED       1
#define BOARD_HAS_VIBRO         0
#define BOARD_HAS_SPEAKER       0
#define BOARD_HAS_IR            1
#define BOARD_HAS_IBUTTON       0
#define BOARD_HAS_RFID          0
#define BOARD_HAS_NFC           1
#define BOARD_HAS_SUBGHZ        1
#define BOARD_HAS_MIC           0

/* ---- RFID ---- */
#define BOARD_PIN_RFID_RX       44
#define BOARD_PIN_RFID_TX       43
#define BOARD_RFID_UART_NUM     1

/* ---- Battery ---- */
#define BQ27220_ADDR            0x00
#define BQ_I2C_PORT             I2C_NUM_0
#define HIGH_DRAIN_CURRENT_THRESHOLD (-200)
#define FURI_HAL_POWER_VIRTUAL_CAPACITY_MAH     (1520U)
#define BQ25896_CHARGE_LIMIT    0
#define BOARD_PIN_BATTERY_ADC   UINT16_MAX
#define FURI_HAL_POWER_OFF_THRESHOLD_PERCENT    (0U)
#define FURI_HAL_POWER_SLEEP_THRESHOLD_PERCENT  (0U)
