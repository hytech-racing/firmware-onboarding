#pragma once
#include <Arduino.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

// System: pure logic. Knows nothing about BME280, I2C or SPI.
class LEDController
{
public:
    LEDController() = default;

    void init();
    // Feed it the latest temperature and the current time; it decides the LED state.
    void update(BMEConstants::celsius temperature_c, unsigned long now_ms);
    unsigned long blink_interval_ms(BMEConstants::celsius temperature_c) const;

private:
    bool led_on_ = false;
    unsigned long last_toggle_ms_ = 0;
};

using LEDControllerInstance = etl::singleton<LEDController>;