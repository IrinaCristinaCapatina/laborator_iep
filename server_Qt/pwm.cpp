#include <stdint.h>
#include "pwm.h"
#include <bcm2835.h>
#define PIN RPI_GPIO_P1_12
// and it is controlled by PWM channel 0
#define PWM_CHANNEL 0
#define RANGE 1024

Pwm::Pwm(float frecventa, float fact_umpl)
{
    this->frecventa = frecventa;
    this->fact_umpl = fact_umpl;

    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_ALT5);
    // Clock divider is set to 16.
    // With a divider of 16 and a RANGE of 1024, in MARKSPACE mode,
    // the pulse repetition frequency will be
    // 1.2MHz/1024 = 1171.875Hz, suitable for driving a DC motor with PWM
    bcm2835_pwm_set_clock(BCM2835_PWM_CLOCK_DIVIDER_16);
    bcm2835_pwm_set_mode(PWM_CHANNEL, 1, 1);
    bcm2835_pwm_set_range(PWM_CHANNEL, frecventa);
}


void Pwm::set(float value_f, float value_ump )
{
    this->frecventa = value_f;
    this->fact_umpl = value_ump;
    bcm2835_pwm_set_range(PWM_CHANNEL, value_f);
    bcm2835_pwm_set_data(PWM_CHANNEL, value_f * value_ump / 100);
}

float Pwm::getFrecv()
{
    return this->frecventa;
}

float Pwm::getFactUmpl()
{
    return this->fact_umpl * 100 / this->frecventa;
}

