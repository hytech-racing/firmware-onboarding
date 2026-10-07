#include "LEDController.h"
LEDController::LEDController(int pin) : _pin(pin), _state(false)
{ 
}

void LEDController::begin()
{
    pinMode(_pin, OUTPUT);
    off();
}

void LEDController::on()
{
    digitalWrite(_pin, HIGH);
    _state = true;
}

void LEDController::off()
{
    digitalWrite(_pin, LOW);
    _state = false;
}

void LEDController::toggle()
{
    if (_state)
    {
        off();
    }
    else
    {
        on();
    }
}
int LEDController::getBlinkInterval(float temperature)
{
    if (temperature > 30.0)
    {
        return 100; // Blink faster when it's hot
    }
    else if (temperature > 20.0)
    {
        return 500; // Blink at a medium rate when it's moderately hot
    }
    else if (temperature > 10.0)
    {
        return 1000; // Blink at a slower rate when it's cool
    }
    else
    {
        return 2000; // Blink slowest when it's cold
    }
}