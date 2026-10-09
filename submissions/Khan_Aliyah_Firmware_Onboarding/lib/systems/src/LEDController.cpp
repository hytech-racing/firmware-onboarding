#include "LEDController.h"

// Store the pin used for the LED
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
    // Higher temperatures have shorter blink intervals
    long interval = 1500 - (long)(temperature * 40);

    // Limit the minimum and maximum blink interval
    interval = constrain(interval, 100L, 1200L);

    // Toggle the LED when enough time has passed
    if (millis() - lastToggle >= (unsigned long)interval)
    {
        lastToggle = millis();
        ledState = !ledState;

        digitalWrite(ledPin, ledState ? HIGH : LOW);
    }
}