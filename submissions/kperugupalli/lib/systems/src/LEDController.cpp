#include "LEDController.h"

void LEDController::update(float temperature)
{
blinkInterval = constrain(
    map((long)temperature, 15, 35, 1000, 200),
    200,
    1000
);
unsigned long currentTime = millis();

if (currentTime - lastToggleTime >= blinkInterval)
{
    lastToggleTime = currentTime;
    ledState = !ledState;
    digitalWrite(LED_BUILTIN, ledState ? HIGH : LOW);
}
}