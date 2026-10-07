#include "LEDController.h"

void LEDController::begin()
{
    pinMode(BMEConstants::LED_PIN, OUTPUT);
    digitalWrite(BMEConstants::LED_PIN, LOW);
}

uint32_t LEDController::getBlinkIntervalMs(float temperatureC) const
{
    // Hotter = faster blink. Adjust thresholds however you like.
    if (temperatureC < 20.0f) return 1000;
    if (temperatureC < 25.0f) return 500;
    if (temperatureC < 30.0f) return 250;
    return 100;
}

void LEDController::update(float temperatureC)
{
    uint32_t now = millis();
    if (now - lastToggleMs >= getBlinkIntervalMs(temperatureC))
    {
        lastToggleMs = now;
        ledOn = !ledOn;
        digitalWrite(BMEConstants::LED_PIN, ledOn ? HIGH : LOW);
    }
}