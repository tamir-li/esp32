#include"spi2ioctl.h"


#define W25QXX_CS_L gpio_set_level(PIN_NUM_CS, 0);
#define W25QXX_CS_H gpio_set_level(PIN_NUM_CS, 1);

void spi2ioctl_init(uint8_t dev)
{
    if(0 == dev) {
        gpio_config_t io_conf;
        //disable interrupt
        io_conf.intr_type = GPIO_PIN_INTR_DISABLE;
        //set as output mode
        io_conf.mode = GPIO_MODE_OUTPUT;
        //bit mask of the pins that you want to set,e.g.GPIO18/19
        io_conf.pin_bit_mask = (1ULL << PIN_NUM_CS);
        //disable pull-down mode
        io_conf.pull_down_en = 0;
        //disable pull-up mode
        io_conf.pull_up_en = 0;
        //configure GPIO with the given settings
        gpio_config(&io_conf);
        gpio_set_pull_mode(PIN_NUM_CS, GPIO_FLOATING);
        W25QXX_CS_H;
        printf("W25QXX_CS_H\n");

    }
}
void spi2ioctl_uninit(uint8_t dev)
{

}

void spi2ioctl(uint8_t dev, uint8_t action)
{    
    if(0 == dev) {
        if(W25QXX_ACTION_CS_L == action)
        {
            printf("W25QXX_CS_L\n");
            W25QXX_CS_L;
        }
        
        if(W25QXX_ACTION_CS_H == action)
        {
            printf("W25QXX_CS_H\n");
            W25QXX_CS_H;
        }
    }
}