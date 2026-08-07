#include "LEDController.h"


void LEDController::init()
{
    pinMode(_pin, OUTPUT);
}

void LEDController::update_blink_interval(float tempC)
{
    _blink_interval_ms = (unsigned long)_map_temp_to_interval_ms(tempC);
}

void LEDController::update_LED_state(unsigned long curr_millis)
{
    if (curr_millis - _last_toggle_ms >= _blink_interval_ms)
    {
        _last_toggle_ms = curr_millis;
        _is_led_on = !_is_led_on;
        digitalWrite(_pin, _is_led_on ? HIGH : LOW);
    }
}

unsigned long LEDController::get_blink_interval_ms() const
{
    return _blink_interval_ms;
}

float LEDController::_map_temp_to_interval_ms(float temp_C)
{
    // Goal is have some linear ramp.
    // Linear ramp for time correlates with linear ramp in b/w the temp range
    // We limit temp_C to be between min and max
    float temp_clamped = constrain(temp_C, _params.TEMP_MIN_C, _params.TEMP_MAX_C);

    float percentage = (temp_clamped - _params.TEMP_MIN_C) / (_params.TEMP_MAX_C - _params.TEMP_MIN_C);

    // Warmer -> smaller interval (faster blink).
    return _params.BLINK_SLOW_MS + percentage * (float(_params.BLINK_FAST_MS) - float(_params.BLINK_SLOW_MS));
}