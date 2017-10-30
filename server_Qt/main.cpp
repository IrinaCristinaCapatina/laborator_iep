#include <QCoreApplication>
#include <bcm2835.h>
#include <stdio.h>
#include <pin.h>
#include <pwm.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    bcm2835_set_debug(1);
    if (!bcm2835_init())
      return 1;

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
    }
    bcm2835_close();

    return a.exec();
}
