#include"spi2bus.h"

static spi_device_handle_t spi2 = {0};

esp_err_t spi2bus_init(uint32_t freq, uint8_t mode)
{
    esp_err_t ret = ESP_OK;

    spi_bus_config_t buscfg={
        .miso_io_num = PIN_NUM_MISO,
        .mosi_io_num = PIN_NUM_MOSI,
        .sclk_io_num = PIN_NUM_CLK,
        .quadwp_io_num = GPIO_NUM_NC,  //GPIO pin for WP (Write Protect) signal, or -1 if not used
        .quadhd_io_num = GPIO_NUM_NC,  //GPIO pin for HD (Hold) signal, or -1 if not used.
    };

    spi_device_interface_config_t devcfg={
        .clock_speed_hz = freq,           //Clock out at 2 MHz
        .mode = mode,                                //SPI mode 0
        .spics_io_num = GPIO_NUM_NC,               //CS pin
        .queue_size=6,                          //We want to be able to queue 7 transactions at a time
    };

    //Initialize the SPI bus
    ret=spi_bus_initialize(SPI2_HOST, &buscfg, 0);
    ESP_ERROR_CHECK(ret);

    //Attach the LCD to the SPI bus
    ret=spi_bus_add_device(SPI2_HOST, &devcfg, &spi2);
    ESP_ERROR_CHECK(ret);
    //Initialize the LCD

    return ret;
}

esp_err_t spi2bus_uninit(void)
{
	esp_err_t ret = ESP_OK;
	ret = spi_bus_remove_device(spi2);
	ESP_ERROR_CHECK(ret);

	ret = spi_bus_free(SPI2_HOST);
	ESP_ERROR_CHECK(ret);
    
    return ret;
}


esp_err_t spi2bus_writebyte(uint8_t data)
{
    esp_err_t ret = ESP_OK;
    spi_transaction_t t;
        
    memset(&t, 0, sizeof(t));
	t.length = sizeof(uint8_t) * 8; //Len is in bytes, transaction length is in bits.
	t.tx_buffer = &data;
	ret = spi_device_transmit(spi2, &t); //Transmit
	ESP_ERROR_CHECK(ret);

    return ret;
}

esp_err_t spi2bus_readbyte(uint8_t *p_data)
{
    esp_err_t ret = ESP_OK;
    spi_transaction_t t;

    uint8_t tx_rx_data = 0xFF;

    memset(&t, 0, sizeof(t));       //Zero out the transaction
	t.length = sizeof(uint8_t) * 8;
	t.rxlength = sizeof(uint8_t) * 8; //The unit of len is byte, and the unit of length is bit.
	t.rx_buffer = &tx_rx_data;
	ret = spi_device_transmit(spi2, &t); //Transmit!
	ESP_ERROR_CHECK(ret);

	*p_data = tx_rx_data;

    return ret;   
}

esp_err_t spi2bus_read(uint8_t *p_data, uint32_t len)
{
	uint32_t ite;
    esp_err_t ret = ESP_OK;

    // if(0 == len) {
    //     return ret;
    // }
    
	for (ite = 0; ite < len; ite++)
		spi2bus_readbyte(&p_data[ite]);
            
    return ret;
}

esp_err_t spi2bus_write(uint8_t *p_data, uint32_t len)
{
	uint32_t ite;
    esp_err_t ret = ESP_OK;

    // if(0 == len) {
    //     return ret;
    // }

	for(ite = 0; ite < len; ite++)
		spi2bus_writebyte(p_data[ite]);
    
    return ret;
}