#include "LEDController.h"
#include "BMEConstants.h"

bool LEDController::isValidTemperature(float temperatureC) {
    // Comparisons also reject NaN and infinities.
    return temperatureC >= BMEConstants::MIN_SENSOR_TEMPERATURE_C &&
           temperatureC <= BMEConstants::MAX_SENSOR_TEMPERATURE_C;
}

uint32_t LEDController::halfPeriodForTemperature(float temperatureC) {
    if (!isValidTemperature(temperatureC)) return 0;
    if (temperatureC <= BMEConstants::COLD_TEMPERATURE_C)
        return BMEConstants::SLOW_HALF_PERIOD_MS;
    if (temperatureC >= BMEConstants::HOT_TEMPERATURE_C)
        return BMEConstants::FAST_HALF_PERIOD_MS;
    const float fraction = (temperatureC - BMEConstants::COLD_TEMPERATURE_C) /
        (BMEConstants::HOT_TEMPERATURE_C - BMEConstants::COLD_TEMPERATURE_C);
    return static_cast<uint32_t>(BMEConstants::SLOW_HALF_PERIOD_MS - fraction *
        (BMEConstants::SLOW_HALF_PERIOD_MS - BMEConstants::FAST_HALF_PERIOD_MS) + 0.5f);
}

bool LEDController::update(float temperatureC, uint32_t nowMs) {
    halfPeriodMs_ = halfPeriodForTemperature(temperatureC);
    if (halfPeriodMs_ == 0) {
        started_ = false;
        on_ = false;
        return on_;
    }
    if (!started_) {
        started_ = true;
        on_ = true;
        lastTransitionMs_ = nowMs;
        return on_;
    }
    // Unsigned subtraction remains correct through millis() rollover.
    const uint32_t elapsed = nowMs - lastTransitionMs_;
    const uint32_t transitions = elapsed / halfPeriodMs_;
    if (transitions != 0) {
        if ((transitions & 1U) != 0) on_ = !on_;
        lastTransitionMs_ += transitions * halfPeriodMs_;
    }
    return on_;
}
