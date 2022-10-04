#ifndef _W25QXX_H_
#define _W25QXX_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "esp_system.h"
#include "spi2bus.h"
#include "spi2ioctl.h"

#define W25QXX_CHIP_ID_REG  0x90

/*
W25QXX CHIP_ID: 
1)W25Q80: CHIP_ID = 0xEF13
2)W25Q16: CHIP_ID = 0xEF14
3)W25Q32: CHIP_ID = 0xEF15
4)W25Q64: CHIP_ID = 0xEF16
5)W25Q128: CHIP_ID = 0xEF17
*/
uint16_t w25qxx_readID(void);

void w25qxx_init(void);

#ifdef __cplusplus
} // extern "C"
#endif

#endif //_W25QXX_H_