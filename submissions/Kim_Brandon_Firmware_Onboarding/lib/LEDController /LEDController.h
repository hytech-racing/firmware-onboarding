#pragma once
#include <stdint.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class LEDController
{
public:
    LEDController() = default;

    void update(float temperatureC, uint32_t nowMs);
    bool isLedOn() const;
    uint32_t getBlinkIntervalMs() const;

private:
    uint32_t computeIntervalMs(float temperatureC) const;

    bool ledOn_ = false;
    uint32_t lastToggleMs_ = 0;
    uint32_t intervalMs_ = BMEConstants::SLOWEST_BLINK_MS;
};

using LEDControllerInstance = etl::singleton<LEDController>;