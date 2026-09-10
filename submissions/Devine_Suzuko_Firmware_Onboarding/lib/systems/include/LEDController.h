#pragma once
#include <Arduino.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class LEDController
{
public:
    LEDController();
    void update(float temperature);

private:
    unsigned long previousMillis;
    bool ledState;
};

using LEDControllerInstance = etl::singleton<LEDController>;