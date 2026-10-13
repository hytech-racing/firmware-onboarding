#include "LEDController.h"

void LEDController::update(float temperatureC, uint32_t nowMs)
{
    intervalMs_ = computeIntervalMs(temperatureC);

    if (nowMs - lastToggleMs_ >= intervalMs_)
    {
        ledOn_ = !ledOn_;
        lastToggleMs_ = nowMs;
    }
}

bool LEDController::isLedOn() const
{
    return ledOn_;
}

uint32_t LEDController::getBlinkIntervalMs() const
{
    return intervalMs_;
}

// Linear map: MIN_TEMP_C -> SLOWEST_BLINK_MS, MAX_TEMP_C -> FASTEST_BLINK_MS, clamped outside
uint32_t LEDController::computeIntervalMs(float temperatureC) const
{
    using namespace BMEConstants;

    if (temperatureC <= MIN_TEMP_C)
    {
        return SLOWEST_BLINK_MS;
    }
    if (temperatureC >= MAX_TEMP_C)
    {
        return FASTEST_BLINK_MS;
    }

    float fraction = (temperatureC - MIN_TEMP_C) / (MAX_TEMP_C - MIN_TEMP_C);
}