#ifndef PWM_H
#define PWM_H


class Pwm
{
public:
    Pwm(float frecventa, float fact_umpl);
    void set(float value_f, float value_ump);
    float getFrecv(void);
    float getFactUmpl(void);
    void reconfig(void);
private:
    float frecventa;
private:
    float fact_umpl;
};

#endif // PWM_H
