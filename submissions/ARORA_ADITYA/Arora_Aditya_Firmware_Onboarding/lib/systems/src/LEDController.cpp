#include "LEDController.h"

void LEDController::init()
{
    pinMode(BMEConstants::LED_PIN, OUTPUT);
}

void LEDController::setTemperature(float tempC)
{
    float t = constrain(tempC, BMEConstants::TEMP_MIN_C, BMEConstants::TEMP_MAX_C);
    float fraction = (t - BMEConstants::TEMP_MIN_C) / (BMEConstants::TEMP_MAX_C - BMEConstants::TEMP_MIN_C);
    _intervalMs = BMEConstants::BLINK_FAST_MS + (BMEConstants::BLINK_SLOW_MS - BMEConstants::BLINK_FAST_MS) * (1.0f - fraction);
}

void LEDController::update()
{
    uint32_t now = millis();
    if (now - _lastToggleMs >= _intervalMs)
    {
        _ledOn = !_ledOn;
        digitalWrite(BMEConstants::LED_PIN, _ledOn ? HIGH : LOW);
        _lastToggleMs = now;
    }
}
