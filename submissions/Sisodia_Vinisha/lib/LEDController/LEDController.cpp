#include "LEDController.h"

void LEDController::begin()
{
    pinMode(BMEConstants::LED_PIN, OUTPUT);
    digitalWrite(BMEConstants::LED_PIN, LOW);

    ledOn = false;
    lastToggleTime = millis();
}

void LEDController::update(float temperature)
{
    float fraction =
        (temperature - BMEConstants::MIN_TEMPERATURE) /
        (BMEConstants::MAX_TEMPERATURE - BMEConstants::MIN_TEMPERATURE);

    fraction = constrain(fraction, 0.0f, 1.0f);

    unsigned long interval =
        BMEConstants::SLOW_BLINK_INTERVAL_MS -
        fraction * (BMEConstants::SLOW_BLINK_INTERVAL_MS -
                    BMEConstants::FAST_BLINK_INTERVAL_MS);

    unsigned long now = millis();

    if (now - lastToggleTime >= interval)
    {
        ledOn = !ledOn;
        digitalWrite(BMEConstants::LED_PIN, ledOn ? HIGH : LOW);
        lastToggleTime = now;
    }
}