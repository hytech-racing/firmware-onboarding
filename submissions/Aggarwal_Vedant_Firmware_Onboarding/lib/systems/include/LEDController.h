#pragma once

class LEDController {
    public:
    LEDController() = default;
    unsigned long getBlinkInterval(float temperature) const;

private:
    static constexpr float MIN_TEMP = 15.0F;
    static constexpr float MAX_TEMP = 25.0F;

static constexpr unsigned long SLOW_INTERVAL = 1000;
static constexpr unsigned long FAST_INTERVAL = 100;

};