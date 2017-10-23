#include <stdint.h>
#include "pin.h"
#include <bcm2835.h>

Pin::Pin(int nr, int dir, int pull_up)
{
    //dir = 1 input, dir = 0 output
    //pull_up = 1 Up, pull_up = 0 Down
    this->numar = nr;
    this->directie = dir;
    this->pullUp = pull_up;

    if(directie == 1)
    {
        bcm2835_gpio_fsel(numar, BCM2835_GPIO_FSEL_INPT);

        if(pullUp == 1)
        {
            bcm2835_gpio_set_pud(numar, BCM2835_GPIO_PUD_UP);
        }else{
            bcm2835_gpio_set_pud(numar, BCM2835_GPIO_PUD_DOWN);
        }

    }else{
         bcm2835_gpio_fsel(numar, BCM2835_GPIO_FSEL_OUTP);
    }
}


void Pin::set(int value)
{
    if(directie == 0)
    {
        if(value == 0)
        {
            bcm2835_gpio_write(numar, LOW);
        }else{
            bcm2835_gpio_write(numar, HIGH);
        }
    }else{
        //do nothing: input
    }
}

int Pin::get(void)
{
    return bcm2835_gpio_lev(numar);
}

void Pin::changeDir(void)
{
    if(directie == 1)
    {
        directie == 0;
        bcm2835_gpio_fsel(numar, BCM2835_GPIO_FSEL_OUTP);
    }else{
        directie = 1;
        bcm2835_gpio_fsel(numar, BCM2835_GPIO_FSEL_INPT);
    }
}
