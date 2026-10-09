#pragma once
#include <Arduino.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class LEDController {
    public:
        LEDController() = default;

        void setTemp(float temperatureC);
        void update(uint32_t nowMs);
        bool isLedOn() const;

    private:
        uint32_t blinkIntervalMs = BMEConstants::BLINK_SLOW_MS;
        uint32_t lastToggleMs = 0;
        bool ledOn = false;
};
using LEDControllerInstance = etl::singleton<LEDController>;
