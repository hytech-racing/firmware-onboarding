#include "LEDController.h"

void LEDController::update(uint32_t nowMs) {
    if (nowMs - lastToggleMs >= blinkIntervalMs) {
        ledOn = !ledOn;
        lastToggleMs = nowMs;
        }
}

void LEDController::setTemp(float temperatureC) {
    float fraction=(temperatureC-BMEConstants::TEMP_MIN_C)/(BMEConstants::TEMP_MAX_C-BMEConstants::TEMP_MIN_C);

    if (fraction < 0.0f) {
        fraction = 0.0f;
    }
    if (fraction > 1.0f) {
        fraction = 1.0f;
    }
    float range = BMEConstants::BLINK_SLOW_MS - BMEConstants::BLINK_FAST_MS;
    blinkIntervalMs = BMEConstants::BLINK_SLOW_MS - static_cast<uint32_t>(fraction * range);
}

bool LEDController::isLedOn() const {
    return ledOn;
}
    