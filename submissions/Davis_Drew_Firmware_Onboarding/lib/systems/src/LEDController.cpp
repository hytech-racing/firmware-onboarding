#include "LEDController.h"

void LEDController::begin()
{
    pinMode(BMEConstants::LED_PIN, OUTPUT);

    digitalWrite(BMEConstants::LED_PIN, LOW);

    ledState = false;
    previousToggleTime = millis();
}

void LEDController::update(float temperature)
{
    blinkInterval = calculateBlinkInterval(temperature);

    unsigned long currentTime = millis();

    if (currentTime - previousToggleTime >= blinkInterval)
    {
        previousToggleTime = currentTime;

        ledState = !ledState;

        digitalWrite(
            BMEConstants::LED_PIN,
            ledState ? HIGH : LOW
        );
    }
}

unsigned long LEDController::calculateBlinkInterval(float temperature)
{
    // If temperature is below the minimum,
    // keep the LED at the slowest rate.
    if (temperature <= BMEConstants::MIN_TEMP_C)
    {
        return BMEConstants::SLOW_BLINK_INTERVAL_MS;
    }

    // If temperature is above the maximum,
    // keep the LED at the fastest rate.
    if (temperature >= BMEConstants::MAX_TEMP_C)
    {
        return BMEConstants::FAST_BLINK_INTERVAL_MS;
    }

    // Determine how far temperature is between
    // MIN_TEMP_C and MAX_TEMP_C.
    float fraction =
        (temperature - BMEConstants::MIN_TEMP_C) /
        (BMEConstants::MAX_TEMP_C - BMEConstants::MIN_TEMP_C);

    // Linearly decrease the blink interval as
    // temperature increases.
    float interval =
        BMEConstants::SLOW_BLINK_INTERVAL_MS -
        fraction *
        (
            BMEConstants::SLOW_BLINK_INTERVAL_MS -
            BMEConstants::FAST_BLINK_INTERVAL_MS
        );

    return static_cast<unsigned long>(interval);
}