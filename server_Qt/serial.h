#include <bcm2835.h>
#include <stdio.h>

class Serial
{
    public:
        virtual uint8_t transfer(uint8_t data_to_send) = 0;
};
