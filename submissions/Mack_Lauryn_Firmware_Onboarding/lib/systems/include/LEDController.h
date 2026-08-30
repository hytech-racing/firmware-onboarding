#pragma once

class LEDController
{
public:
    LEDController() = default;

    void update(float temperature);

private:
    void set_blink_rate(float temperature);
};