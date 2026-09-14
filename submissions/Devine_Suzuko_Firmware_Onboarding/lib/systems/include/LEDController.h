#pragma once

#include <Arduino.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class LEDController
{
public:
    LEDController() = default;

    void begin();

    void update(float temperature);

private:
    unsigned long previousToggleTime = 0;
    unsigned long blinkInterval = BMEConstants::SLOW_BLINK_INTERVAL_MS;

    bool ledState = false;

    unsigned long calculateBlinkInterval(float temperature);
};

using LEDControllerInstance = etl::singleton<LEDController>;