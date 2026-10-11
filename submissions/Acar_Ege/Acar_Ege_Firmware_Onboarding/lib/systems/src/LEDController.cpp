#include "LEDController.h"

void LEDController::begin(uint8_t ledPin)
{
    pin = ledPin;
    pinMode(pin, OUTPUT);
}

unsigned long LEDController::calculateInterval(float temperature)
{
    // Keep temperature between 10°C and 40°C
    temperature = constrain(temperature, 10.0f, 40.0f);

    // Higher temperature = shorter blinking interval
    return 1000 - (temperature - 10.0f) * 30;
}

void LEDController::update(float temperature)
{
    unsigned long interval = calculateInterval(temperature);

    if (millis() - lastToggle >= interval)
    {
        lastToggle = millis();

        ledState = !ledState;
        digitalWrite(pin, ledState ? HIGH : LOW);
    }
}