#include "LEDController.h"

unsigned long LEDController::getBlinkInterval(float temperature) const
{
    if (temperature <= MIN_TEMP) {
        return SLOW_INTERVAL;
    }
    else if (temperature >= MAX_TEMP) {
        return FAST_INTERVAL;
    }

    const float temperatureRange = MAX_TEMP - MIN_TEMP;
    const float intervalRange = static_cast<float>(SLOW_INTERVAL - FAST_INTERVAL);

    const float percentage =
        (temperature - MIN_TEMP) / temperatureRange;

    return static_cast<unsigned long>(
        SLOW_INTERVAL - (percentage * intervalRange));
}