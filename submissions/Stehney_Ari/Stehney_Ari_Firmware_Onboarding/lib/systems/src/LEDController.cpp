#include "LEDController.h"
#include "BMEConstants.h"

int LEDController::begin()
{
    pinMode(BMEConstants::LED, OUTPUT);
    digitalWrite(BMEConstants::LED, LOW);

    return 0;
}

void LEDController::update(float temp)
{
    if (isnan(temp)) {
        return;
    }

    if (temp < BMEConstants::TEMP_LOW) {
        temp = BMEConstants::TEMP_LOW;
    } else if (temp > BMEConstants::TEMP_HIGH) {
        temp = BMEConstants::TEMP_HIGH;
    }

    float fraction =
        (temp - BMEConstants::TEMP_LOW) /
        (BMEConstants::TEMP_HIGH - BMEConstants::TEMP_LOW);
    unsigned long interval = static_cast<unsigned long>(
        BMEConstants::LOW_IVAL +
        fraction * (static_cast<float>(BMEConstants::HIGH_IVAL) -
                    static_cast<float>(BMEConstants::LOW_IVAL)));
    unsigned long now = millis();

    if (now - _lastToggle >= interval) {
        _lastToggle = now;
        _lastState = !_lastState;

        digitalWrite(BMEConstants::LED, _lastState);
    }
}
