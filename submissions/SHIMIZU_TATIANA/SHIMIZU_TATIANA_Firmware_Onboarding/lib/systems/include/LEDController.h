#pragma once
#include <Arduino.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class LEDController
{
public:
    LEDController() = default;

    void begin();
    void update(float current_temperature_c);

    // Returns active period in milliseconds
    unsigned long get_current_period_ms() const { return current_period_ms_; }

private:
    unsigned long last_toggle_time_ = 0;
    unsigned long current_period_ms_ = BMEConstants::BLINK_PERIOD_SLOW_MS;
    bool led_state_ = false;
};

using LEDControllerInstance = etl::singleton<LEDController>;