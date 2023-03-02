#include "logic_analyzer.hpp"

unsigned long LOGIC_CLOCK_COUNT = 0;

void init_logic_analyzer()
{

    // Attach the interupt routine
    for (pin_size_t i = START_DBUS_PIN; i <= END_DBUS_PIN; ++i)
    {
        pinMode(i, INPUT);
    }
    Serial.begin(LOGIC_ANALYZER_BAUD_RATE);
    attachInterrupt(digitalPinToInterrupt(D1), interupt_routine, CHANGE);
}

void disable_logic_analyzer()
{
    // No need to set the pin states back to input; that's the default anyway
    Serial.end();
    detachInterrupt(digitalPinToInterrupt(D1));
}

void interupt_routine()
{
    uint16_t bus = 0x0000;

    for (pin_size_t i = START_DBUS_PIN; i <= END_DBUS_PIN; ++i)
    {
        bus |= (digitalRead(i) == HIGH) ? 1 : 0;
        bus <<= 1;
    }
    bus >>= 1;

    char printBuf[PRINT_BUF_SIZE];
    memset(printBuf, 0, PRINT_BUF_SIZE);

    int strSize = sprintf(printBuf, "%X\n", bus);
    if (strSize > 0)
    {
        Serial.write(printBuf, strSize);
    }

    ++LOGIC_CLOCK_COUNT;
}