#include "LEDController.h"
#include <math.h>

void LEDController::begin()
{
    pinMode(BMEConstants::LED_PIN, OUTPUT);
    digitalWrite(BMEConstants::LED_PIN, LOW);
    ledOn = false;
    lastToggleMs = millis();
}

void LEDController::update(float temperatureC)
{
    // turns off the LED if the reading isnt valid
    if (!isfinite(temperatureC))
    {
        ledOn = false;
        digitalWrite(BMEConstants::LED_PIN, LOW);
        lastToggleMs = millis();
        return;
    }
    // makes temp a positive fraction less than 1
    float fraction =
        (temperatureC - BMEConstants::COOL_TEMP_C) /
        (BMEConstants::HOT_TEMP_C - BMEConstants::COOL_TEMP_C);
    fraction = constrain(fraction, 0.0f, 1.0f);
    // makes it so higher temps create shorter blink intervals
    const unsigned long intervalMs =
        static_cast<unsigned long>(
            BMEConstants::SLOW_BLINK_MS -
            fraction * (
                BMEConstants::SLOW_BLINK_MS -
                BMEConstants::FAST_BLINK_MS
            )
        );
    const unsigned long now = millis();
    // turn on the LED after a set time interval
    if (now - lastToggleMs >= intervalMs)
    {
        lastToggleMs = now;
        ledOn = !ledOn;
        digitalWrite(
            BMEConstants::LED_PIN,
            ledOn ? HIGH : LOW
        );
    }
}