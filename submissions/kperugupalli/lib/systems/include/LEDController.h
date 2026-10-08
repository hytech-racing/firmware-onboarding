#pragma once

#include <Arduino.h>

class LEDController
{
public:
    LEDController() = default;

    void update(float temperature);

private:
    unsigned long blinkInterval = 1000;
    unsigned long lastToggleTime = 0;
bool ledState = false;
};