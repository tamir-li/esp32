#include"w25qxx.h"

uint16_t w25qxx_readID(void)
{
	uint8_t tx_data[4] = {W25QXX_CHIP_ID_REG, 0, 0, 0};
    uint8_t rx_data[2] = {0, 0};

	uint16_t  w25qxx_id= 0;

    spi2ioctl(0, W25QXX_ACTION_CS_L);

    spi2bus_write(tx_data, sizeof(tx_data));

    spi2bus_read(rx_data, sizeof(rx_data));

	printf("rx_data: 0x%X ， 0x%X\n", rx_data[0], rx_data[1]);

	w25qxx_id = (rx_data[0] << 8) | (rx_data[1] << 0);
    spi2ioctl(0, W25QXX_ACTION_CS_H);

	return w25qxx_id;
}

void w25qxx_init(void)
{
    spi2ioctl_init(0);
    spi2bus_init(20 * 1000 * 1000, 0);

    uint16_t W25QXX_ID = w25qxx_readID();	  
	printf("W25QXX_ID: 0x%X \n", W25QXX_ID);
}
