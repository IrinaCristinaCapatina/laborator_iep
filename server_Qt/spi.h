#include <bcm2835.h>
#include <stdio.h>
#include "Serial.h"

class Spi: public Serial{
    public:
            Spi(uint8_t SPI_BIT_ORDER, uint8_t SPI_MODE, uint16_t SPI_CLOCK_DIVIDER, uint8_t SPI_CS, bool LH);
            uint8_t transfer(uint8_t data_to_send);
};
