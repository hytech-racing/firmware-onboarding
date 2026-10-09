#pragma once
#include <Arduino.h>
#include "BMEConstants.h"

class LEDController
{
public:
    void begin();
    void update(float temperatureC);

private:
    bool ledOn = false;
    unsigned long lastToggleMs = 0;
};