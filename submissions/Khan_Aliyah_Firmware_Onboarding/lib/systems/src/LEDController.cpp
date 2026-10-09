#include "LEDController.h"

// Store the pin used to control the LED
LEDController::LEDController(uint8_t pin)
    : ledPin(pin)
{
}

void LEDController::begin()
{
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, LOW);
}

void LEDController::update(float temperature)
{
    unsigned long interval;
    // Higher temperatures use shorter blink intervals
    if (temperature < 20.0f)
    {
        interval = 1000;
    }
    else if (temperature < 30.0f)
    {
        interval = 500;
    }
    else
    {
        interval = 200;
    }
    // Change the LED state once enough time has passed
    if (millis() - lastToggle >= (unsigned long)interval)
    {
        lastToggle = millis();
        ledState = !ledState;

        digitalWrite(ledPin, ledState ? HIGH : LOW);
    }
}