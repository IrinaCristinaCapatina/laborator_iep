#include <QCoreApplication>
#include <bcm2835.h>
#include <stdio.h>
#include <pin.h>
#include <pwm.h>
#include <spi.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    bcm2835_set_debug(1);
    if (!bcm2835_init())
      return 1;
    /*
    Pin pin_in = Pin(22,1,1);
    Pwm pwm = Pwm(1024, 10);
    while (1)
    {
        uint8_t value = pin_in.get();

        if (value == 1)
        {
            pwm.set(1024, pwm.getFactUmpl()+ 10);
            bcm2835_delay(500);
        }else{
            //doNothing
        }
    }*/
    if (!bcm2835_spi_begin())
    {
        printf("bcm2835_spi_begin failed. Are you running as root??\n");
          return 1;
    }

    Spi s1 = Spi(BCM2835_SPI_BIT_ORDER_MSBFIRST, BCM2835_SPI_MODE0, BCM2835_SPI_CLOCK_DIVIDER_65536, BCM2835_SPI_CS0, LOW);

    uint8_t send_data = 0x23;
    uint8_t read_data = s1.transfer(send_data);
    printf("Sent to SPI: 0x%02X. Read back from SPI: 0x%02X.\n", send_data, read_data);
    if (send_data != read_data)
          printf("Do you have the loopback from MOSI to MISO connected?\n");

    bcm2835_spi_end();
    bcm2835_close();

    return a.exec();
}
