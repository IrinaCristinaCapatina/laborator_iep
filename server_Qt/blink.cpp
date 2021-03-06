// blink.c
//
// Example program for bcm2835 library
// Blinks a pin on an off every 0.5 secs
//
// After installing bcm2835, you can build this 
// with something like:
// gcc -o blink blink.c -l bcm2835
// sudo ./blink
//
// Or you can test it before installing with:
// gcc -o blink -I ../../src ../../src/bcm2835.c blink.c
// sudo ./blink
//
// Author: Mike McCauley
// Copyright (C) 2011 Mike McCauley
// $Id: RF22.h,v 1.21 2012/05/30 01:51:25 mikem Exp $
#include <bcm2835.h>
#include <stdio.h>
#include <pin.h>

// Blinks on RPi Plug P1 pin 11 (which is GPIO pin 17)
#define PIN RPI_GPIO_P1_11

int main(int argc, char **argv)
{
    // If you call this, it will not actually access the GPIO
    // Use for testing
    bcm2835_set_debug(1);
    if (!bcm2835_init())
      return 1;
    // Set the pin 17 as an output
    Pin pin_out =  Pin(17,0,0);

    // Set RPI pin P1-15 to be an input
    Pin pin_in = Pin(22,1,1);

    // Blink
    while (1)
    {
        uint8_t value = pin_in.get();

        if (value == 1)
        {
            // Turn it on
            pin_out.set(1);
            // wait a bit
            bcm2835_delay(500);
        }else{
            // turn it off
            pin_out.set(0);

            // wait a bit
            bcm2835_delay(500);
        }
    }
    bcm2835_close();
    return 0;
}
