#include "LEDController.h"

bool LEDController::update(float temperature, uint32_t now)
{
    // Keep temperature between 20 and 35 °C
    if (temperature < 20) temperature = 20;
    if (temperature > 35) temperature = 35;

    // 20 °C -> 1000 ms, 35 °C -> 100 ms (60 ms faster per degree)
    uint32_t interval = 1000 - (temperature - 20) * 60;

    // Flip the LED when enough time has passed
    if (now - lastToggle >= interval)
    {
        on = !on;
        lastToggle = now;
    }

    return on;
}