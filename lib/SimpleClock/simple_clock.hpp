#ifndef SIMPLE_CLOCK
#define SIMPLE_CLOCK

#include <Arduino.h>

#define CLOCK_OUT_PIN D0

void init_clock();
void disable_clock();
void run_clock(unsigned steps, unsigned long period);

#endif