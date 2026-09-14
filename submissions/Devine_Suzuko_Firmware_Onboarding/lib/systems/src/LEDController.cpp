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
    // Determine the correct blink interval from temperature.
    blinkInterval = calculateBlinkInterval(temperature);

    unsigned long currentTime = millis();

    // Toggle the LED whenever the interval has elapsed.
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
    // Cold or below minimum temperature:
    // use the slowest blink rate.
    if (temperature <= BMEConstants::MIN_TEMP_C)
    {
        return BMEConstants::SLOW_BLINK_INTERVAL_MS;
    }

    // Hot or above maximum temperature:
    // use the fastest blink rate.
    if (temperature >= BMEConstants::MAX_TEMP_C)
    {
        return BMEConstants::FAST_BLINK_INTERVAL_MS;
    }

    // Convert temperature to a value from 0.0 to 1.0.
    //
    // MIN_TEMP_C -> 0.0
    // MAX_TEMP_C -> 1.0
    float temperatureFraction =
        (temperature - BMEConstants::MIN_TEMP_C) /
        (BMEConstants::MAX_TEMP_C - BMEConstants::MIN_TEMP_C);

    // IMPORTANT:
    // As temperatureFraction gets BIGGER,
    // blinkInterval gets SMALLER.
    //
    // Smaller interval = faster blinking.
    float blinkIntervalFloat =
        BMEConstants::SLOW_BLINK_INTERVAL_MS -
        temperatureFraction *
        (
            BMEConstants::SLOW_BLINK_INTERVAL_MS -
            BMEConstants::FAST_BLINK_INTERVAL_MS
        );

    return static_cast<unsigned long>(blinkIntervalFloat);
}