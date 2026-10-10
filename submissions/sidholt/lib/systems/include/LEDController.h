#pragma once
#include <etl/singleton.h>
#include "BMEConstants.h"

class LEDController
{
public:
    LEDController() = default;

    void begin(uint8_t p);
    void update(float temp);

    unsigned long getInterval() const { return interval; }

private:
    uint8_t pin = BMEConstants::LED_PIN;
    bool on = false;
    unsigned long interval = BMEConstants::SLOW_MS;
    unsigned long last = 0;
};

using LEDControllerInstance = etl::singleton<LEDController>;
