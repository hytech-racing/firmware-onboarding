#pragma once
#include <Arduino.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class LEDController
{
public:
    LEDController() = default;

    void init();                          
    void setTemperature(float tempC);     
    void update();                        

private:
    uint32_t _intervalMs = BMEConstants::BLINK_SLOW_MS;
    uint32_t _lastToggleMs = 0;
    bool _ledOn = false;
};
using LEDControllerInstance = etl::singleton<LEDController>;