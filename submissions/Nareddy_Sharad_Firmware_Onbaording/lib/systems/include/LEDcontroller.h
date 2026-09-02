#pragma once

#include <Arduino.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class ledController
{
    public:
        ledController() = default;

        void flashLEDByTemperature(int pin, float tempC);

private:

};

using LEDControllerInstance = etl::singleton<ledController>;

