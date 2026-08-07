#pragma once
#include <Arduino.h>
#include <etl/singleton.h>


using celsius = float;

namespace led_controller_default_params
{
    constexpr celsius temp_min_c = 20.0f;
    constexpr celsius temp_max_c = 32.0f;
    constexpr unsigned long blink_slow_ms = 1000;
    constexpr unsigned long blink_fast_ms = 100;
};

struct LEDControllerParams_s
{
    celsius TEMP_MIN_C;
    celsius TEMP_MAX_C;
    unsigned long BLINK_SLOW_MS;
    unsigned long BLINK_FAST_MS;
};

class LEDController
{
public:

    explicit LEDController(uint8_t pin,
                        LEDControllerParams_s params = {
                            .TEMP_MIN_C = led_controller_default_params::temp_min_c,
                            .TEMP_MAX_C = led_controller_default_params::temp_max_c,
                            .BLINK_SLOW_MS = led_controller_default_params::blink_slow_ms,
                            .BLINK_FAST_MS = led_controller_default_params::blink_fast_ms
                        }
    ) : _pin(pin),
        _params(params),
        _blink_interval_ms(params.BLINK_SLOW_MS),
        _last_toggle_ms(0),
        _is_led_on(false)
    {};

    void init();

    /**
     * @brief Recomputes the target blink interval.
     * @param temp_C is the newest temperature reading
    */
    void update_blink_interval(celsius temp_C);

    /**
     * @brief method to toggle the LED pin
     * @param curr_millis
     */
    void update_LED_state(unsigned long curr_millis);

    unsigned long get_blink_interval_ms() const;

private:

    float _map_temp_to_interval_ms(float temp_C);

    uint8_t _pin;
    LEDControllerParams_s _params;
    unsigned long _blink_interval_ms;
    unsigned long _last_toggle_ms;
    bool _is_led_on;
};
using LEDContollerInstance = etl::singleton<LEDController>;