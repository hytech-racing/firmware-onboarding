#pragma once

#include <Arduino.h>

// Controls the LED blink rate based on temperature
class LEDController
{
public:
    explicit LEDController(uint8_t pin);

    void begin();
    void update(float temperature);

private:
    uint8_t ledPin;
    bool ledState = false;
    unsigned long lastToggle = 0;
};