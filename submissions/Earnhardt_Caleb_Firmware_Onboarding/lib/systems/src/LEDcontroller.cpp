#pragma once

class LEDController
{
public:
    unsigned long led_speed(float temperature_value_1);
};

#include "LEDController.h"

float threshold_lower = 20.0;
float threshold_upper = 40.0;
float slope = 20.0;

unsigned long LEDController::led_speed(float temperature_value_1)
{
    if (temperature_value_1 <= threshold_lower)
    {
        return 500;
    }

    if (temperature_value_1 >= threshold_upper)
    {
        return 100; //no negatives
    }

    return static_cast<unsigned long>(
        500.0f - slope * (temperature_value_1 - threshold_lower)
    );
}