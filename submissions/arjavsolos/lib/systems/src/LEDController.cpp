#include "LEDController.h"

#include "BMEConstants.h"

void LEDController::begin()
{
    pinMode(BMEConstants::LED_PIN, OUTPUT);
    digitalWrite(BMEConstants::LED_PIN, LOW);
    ledIsOn_ = false;
    previousToggleMs_ = millis();
    blinkIntervalMs_ = BMEConstants::SLOW_BLINK_INTERVAL_MS;
}

void LEDController::update(float temperatureC, unsigned long nowMs)
{
    blinkIntervalMs_ = intervalForTemperature(temperatureC);

    // Unsigned subtraction remains safe when millis() rolls over.
    if (nowMs - previousToggleMs_ < blinkIntervalMs_)
    {
        return;
    }

    previousToggleMs_ = nowMs;
    ledIsOn_ = !ledIsOn_;
    digitalWrite(BMEConstants::LED_PIN, ledIsOn_ ? HIGH : LOW);
}

unsigned long LEDController::blinkIntervalMs() const
{
    return blinkIntervalMs_;
}

unsigned long LEDController::intervalForTemperature(float temperatureC)
{
    if (temperatureC <= BMEConstants::MIN_TEMPERATURE_C)
    {
        return BMEConstants::SLOW_BLINK_INTERVAL_MS;
    }

    if (temperatureC >= BMEConstants::MAX_TEMPERATURE_C)
    {
        return BMEConstants::FAST_BLINK_INTERVAL_MS;
    }

    const float temperatureRange =
        BMEConstants::MAX_TEMPERATURE_C - BMEConstants::MIN_TEMPERATURE_C;
    const float position =
        (temperatureC - BMEConstants::MIN_TEMPERATURE_C) / temperatureRange;
    const float intervalRange = static_cast<float>(
        BMEConstants::SLOW_BLINK_INTERVAL_MS - BMEConstants::FAST_BLINK_INTERVAL_MS);

    return BMEConstants::SLOW_BLINK_INTERVAL_MS -
           static_cast<unsigned long>(position * intervalRange);
}
