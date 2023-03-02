#include "simple_clock.hpp"

void init_clock()
{
    pinMode(CLOCK_OUT_PIN, OUTPUT);
    digitalWrite(D0, LOW);
}

void disable_clock()
{
    // Set to default
    pinMode(CLOCK_OUT_PIN, INPUT);
}

void run_clock(unsigned steps, unsigned long period = 1000)
{
    unsigned stepsLeft = steps;

    while (stepsLeft != 0)
    {
        delay(period);
        digitalWrite(CLOCK_OUT_PIN, HIGH);
        delay(period);
        digitalWrite(CLOCK_OUT_PIN, LOW);
    }
}
