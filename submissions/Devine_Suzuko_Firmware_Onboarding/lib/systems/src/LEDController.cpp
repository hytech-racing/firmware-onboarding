#include "LEDController.h"

LEDController::LEDController() : previousMillis(0), ledState(LOW)
{
    pinMode(BMEConstants::LED_PIN, OUTPUT);
}

void LEDController::update(float temperature)
{
    if (isnan(temperature)) return;

    float clampedTemp = constrain(temperature, BMEConstants::TEMP_MIN, BMEConstants::TEMP_MAX);
    unsigned long blinkInterval = map(
        clampedTemp * 10,
        BMEConstants::TEMP_MIN * 10,
        BMEConstants::TEMP_MAX * 10,
        BMEConstants::INTERVAL_MAX,
        BMEConstants::INTERVAL_MIN
    );

    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= blinkInterval) {
        previousMillis = currentMillis;
        ledState = !ledState;
        digitalWrite(BMEConstants::LED_PIN, ledState);
    }
}