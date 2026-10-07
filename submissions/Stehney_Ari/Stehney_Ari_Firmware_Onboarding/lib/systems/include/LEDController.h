#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class LEDController
{
public:

    LEDController() = default;

    int begin();

    void update(float temp);

private:

    unsigned long _lastToggle = 0;
    bool _lastState = false;
};

using LEDControllerInstance = etl::singleton<LEDController>;