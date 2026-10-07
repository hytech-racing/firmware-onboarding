#pragma once
#include <Arduino.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class LEDController
{
public:
    LEDController() = default;

    void begin();
    void update(float temperatureC);  // call every loop with the latest temp

private:
    uint32_t getBlinkIntervalMs(float temperatureC) const;

    uint32_t lastToggleMs = 0;
    bool ledOn = false;
};

using LEDControllerInstance = etl::singleton<LEDController>;