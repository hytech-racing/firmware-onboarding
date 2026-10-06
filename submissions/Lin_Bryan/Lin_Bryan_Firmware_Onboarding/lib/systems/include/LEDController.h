#pragma once
#include <Arduino.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class LEDController
{
public:
    LEDController() = default;

    void init();

    void update(float currentTemperature);

private:
    unsigned long previousMillis = 0;
    bool ledState = false;
};

using LEDControllerInstance = etl::singleton<LEDController>;