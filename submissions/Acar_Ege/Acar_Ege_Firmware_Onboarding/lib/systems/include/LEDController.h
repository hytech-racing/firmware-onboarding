#pragma once

#include <Arduino.h>

class LEDController
{
public:
    LEDController() = default;

    void begin(uint8_t ledPin);
    void update(float temperature);

private:
    uint8_t pin = LED_BUILTIN;
    unsigned long lastToggle = 0;
    bool ledState = false;

    unsigned long calculateInterval(float temperature);
};