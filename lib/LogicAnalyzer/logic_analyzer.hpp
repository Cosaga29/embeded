#ifndef LOGIC_ANALYZER
#define LOGIC_ANALYZER

#include <Arduino.h>

#define LOGIC_ANALYZER_BAUD_RATE 115200

#define START_DBUS_PIN D2
#define END_DBUS_PIN D9

#define PRINT_BUF_SIZE 32

extern unsigned long LOGIC_CLOCK_COUNT;

void init_logic_analyzer();
void disable_logic_analyzer();
void interupt_routine();

#endif