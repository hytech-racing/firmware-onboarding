#pragma once

#include <Arduino.h>
#include <etl/singleton.h>

class LEDController
{
public:
    LEDController() = default;

    void begin();
    void update(float temperatureC, unsigned long nowMs);
    unsigned long blinkIntervalMs() const;

    static unsigned long intervalForTemperature(float temperatureC);

private:
    bool ledIsOn_ = false;
    unsigned long previousToggleMs_ = 0UL;
    unsigned long blinkIntervalMs_ = 0UL;
};

using LEDControllerInstance = etl::singleton<LEDController>;
