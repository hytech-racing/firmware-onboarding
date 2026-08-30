#include "LEDController.h"

#include <Arduino.h>

#include "BMEConstants.h"

void LEDController::update(float temperature)
{
    set_blink_rate(temperature);
}

void LEDController::set_blink_rate(float temperature)
{
    static unsigned long last_toggle = 0;
    static bool led_state = false;

    // Clamp temperature range
    if (temperature < 10.0f)
    {
        temperature = 10.0f;
    }

    if (temperature > 40.0f)
    {
        temperature = 40.0f;
    }

    // Convert temperature to blink delay
    // 10°C -> 1000 ms
    // 40°C -> 100 ms
    int blink_delay = map(
        static_cast<int>(temperature),
        10,
        40,
        1000,
        100);

    unsigned long current_time = millis();

    if (current_time - last_toggle >= blink_delay)
    {
        last_toggle = current_time;

        led_state = !led_state;

        digitalWrite(
            BMEConstants::LED_PIN,
            led_state);
    }
}