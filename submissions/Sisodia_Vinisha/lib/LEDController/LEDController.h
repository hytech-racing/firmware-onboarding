#pragma once
#include <Arduino.h>
#include "BMEConstants.h"

class LEDController
{
public:
    void begin();
    void update(float temperature);

private:
    unsigned long lastToggleTime = 0;
    bool ledOn = false;
};