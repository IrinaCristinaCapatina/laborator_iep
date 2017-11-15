#include "Spi.h"

Spi::Spi(uint8_t SPI_BIT_ORDER, uint8_t SPI_MODE, uint16_t SPI_CLOCK_DIVIDER, uint8_t SPI_CS, bool LH)
{
    bcm2835_spi_setBitOrder(SPI_BIT_ORDER);
    bcm2835_spi_setDataMode(SPI_MODE);
    bcm2835_spi_setClockDivider(SPI_CLOCK_DIVIDER);
    bcm2835_spi_chipSelect(SPI_CS);
    bcm2835_spi_setChipSelectPolarity(SPI_CS, LH);
}

uint8_t Spi::transfer (uint8_t data_to_send) {
           return bcm2835_spi_transfer(data_to_send);
}
