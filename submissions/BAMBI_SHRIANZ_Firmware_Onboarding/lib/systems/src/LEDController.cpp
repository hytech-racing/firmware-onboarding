#include "LEDController.h"

void LEDController::init()
{
    pinMode(BMEConstants::LED_PIN, OUTPUT);
    digitalWrite(BMEConstants::LED_PIN, LOW);
}

unsigned long LEDController::blink_interval_ms(BMEConstants::celsius temperature_c) const
{
    // Hotter -> shorter interval -> faster blink. Clamp outside the range.
    if (temperature_c <= BMEConstants::TEMP_MIN_C)
    {
        return BMEConstants::BLINK_SLOW_MS;
    }
    if (temperature_c >= BMEConstants::TEMP_MAX_C)
    {
        return BMEConstants::BLINK_FAST_MS;
    }
    const float fraction = (temperature_c - BMEConstants::TEMP_MIN_C) /
                           (BMEConstants::TEMP_MAX_C - BMEConstants::TEMP_MIN_C);
    const float span = static_cast<float>(BMEConstants::BLINK_SLOW_MS - BMEConstants::BLINK_FAST_MS);
    return BMEConstants::BLINK_SLOW_MS - static_cast<unsigned long>(fraction * span);
}

void LEDController::update(BMEConstants::celsius temperature_c, unsigned long now_ms)
{
    // Non-blocking: compare against millis() instead of using delay().
    if (now_ms - last_toggle_ms_ >= blink_interval_ms(temperature_c))
    {
        led_on_ = !led_on_;
        digitalWrite(BMEConstants::LED_PIN, led_on_ ? HIGH : LOW);
        last_toggle_ms_ = now_ms;
    }
}