#pragma once
#include <Arduino.h>
#include "BMEConstants.h"
class LEDController
{
public:
    LEDController(int pin);
    void begin();
    void on();
    void off();
    void toggle();
    int getBlinkInterval(float temperature);
private:
    int _pin;
    bool _state;
}; 