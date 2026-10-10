#include "LEDController.h"

void LEDController::begin(uint8_t p)
{
    pin = p;
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

void LEDController::update(float temp)
{
    float t = (temp - BMEConstants::MIN_TEMP) / (BMEConstants::MAX_TEMP - BMEConstants::MIN_TEMP);
    if (t < 0.0f) t = 0.0f;
    if (t > 1.0f) t = 1.0f;

    interval = BMEConstants::SLOW_MS - (unsigned long)(t * (BMEConstants::SLOW_MS - BMEConstants::FAST_MS));

    unsigned long now = millis();
    if (now - last >= interval)
    {
        last = now;
        on = !on;
        digitalWrite(pin, on ? HIGH : LOW);
    }
}
