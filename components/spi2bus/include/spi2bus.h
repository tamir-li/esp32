#ifndef _SPI2BUS_H_
#define _SPI2BUS_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "esp_system.h"
#include "driver/spi_master.h"
#include "driver/gpio.h"

// #define PIN_NUM_CS      10//GPIO_NUM_10
// #define PIN_NUM_CLK     6//GPIO_NUM_6
// #define PIN_NUM_MOSI    7//GPIO_NUM_7
// #define PIN_NUM_MISO    2//GPIO_NUM_2//GPIO_NUM_NC
#define PIN_NUM_MISO CONFIG_MISO_GPIO
#define PIN_NUM_MOSI CONFIG_MOSI_GPIO
#define PIN_NUM_CLK CONFIG_SCLK_GPIO

esp_err_t spi2bus_init(uint32_t freq, uint8_t mode);
esp_err_t spi2bus_uninit(void);

esp_err_t spi2bus_writebyte(uint8_t data);
esp_err_t spi2bus_readbyte(uint8_t *p_data);

esp_err_t spi2bus_read(uint8_t *p_data, uint32_t len);
esp_err_t spi2bus_write(uint8_t *p_data, uint32_t len);


#ifdef __cplusplus
} // extern "C"
#endif

#endif //_APP_SPI2_H_