#ifndef _SPI2IOCTL_H_
#define _SPI2IOCTL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "esp_system.h"
#include "driver/gpio.h"

//#include "gpio_types.h"

/* LCD */
// #define PIN_NUM_BUSY    GPIO_NUM_0
// #define PIN_NUM_RST     GPIO_NUM_8
// #define PIN_NUM_DC      GPIO_NUM_9
//#define PIN_NUM_CS      GPIO_NUM_9

#define W25QXX_ACTION_CS_L  0
#define W25QXX_ACTION_CS_H  1

/* FLASH */
#define PIN_NUM_CS CONFIG_CS_GPIO

void spi2ioctl_init(uint8_t dev);
void spi2ioctl_uninit(uint8_t dev);

void spi2ioctl(uint8_t dev, uint8_t action);


#ifdef __cplusplus
} // extern "C"
#endif

#endif //_SPI2IOCTL_H_