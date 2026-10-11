#pragma once
#include <stdint.h>

// Pure logic: no Arduino, GPIO, BME280 or communication protocol dependency.
class LEDController {
public:
    static bool isValidTemperature(float temperatureC);
    static uint32_t halfPeriodForTemperature(float temperatureC);
    bool update(float temperatureC, uint32_t nowMs);
    bool isOn() const { return on_; }
    uint32_t halfPeriodMs() const { return halfPeriodMs_; }
private:
    bool started_ = false;
    bool on_ = false;
    uint32_t lastTransitionMs_ = 0;
    uint32_t halfPeriodMs_ = 0;
};
