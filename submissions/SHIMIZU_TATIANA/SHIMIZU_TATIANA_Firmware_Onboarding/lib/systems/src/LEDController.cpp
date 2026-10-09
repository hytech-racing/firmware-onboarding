#include "LEDController.h"

void LEDController::begin()
{
    pinMode(BMEConstants::LED_PIN, OUTPUT);
    digitalWrite(BMEConstants::LED_PIN, LOW);
}

void LEDController::update(float current_temperature_c)
{
    float clamped_temp = constrain(current_temperature_c, 
                                   BMEConstants::TEMP_MIN_C, 
                                   BMEConstants::TEMP_MAX_C);

    current_period_ms_ = map(
        (long)(clamped_temp * 100),
        (long)(BMEConstants::TEMP_MIN_C * 100),
        (long)(BMEConstants::TEMP_MAX_C * 100),
        BMEConstants::BLINK_PERIOD_SLOW_MS,
        BMEConstants::BLINK_PERIOD_FAST_MS
    );

    unsigned long half_period_ms = current_period_ms_ / 2;
    unsigned long current_time = millis();

    if (current_time - last_toggle_time_ >= half_period_ms)
    {
        last_toggle_time_ = current_time;
        led_state_ = !led_state_;
        digitalWrite(BMEConstants::LED_PIN, led_state_ ? HIGH : LOW);
    }
}