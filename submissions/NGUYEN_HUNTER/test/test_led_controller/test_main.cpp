#include <unity.h>
#include <math.h>
#include "LEDController.h"

void setUp() {}
void tearDown() {}
void test_mapping_and_clamping() {
    TEST_ASSERT_EQUAL_UINT32(1000, LEDController::halfPeriodForTemperature(-40));
    TEST_ASSERT_EQUAL_UINT32(1000, LEDController::halfPeriodForTemperature(0));
    TEST_ASSERT_EQUAL_UINT32(550, LEDController::halfPeriodForTemperature(25));
    TEST_ASSERT_EQUAL_UINT32(100, LEDController::halfPeriodForTemperature(50));
    TEST_ASSERT_EQUAL_UINT32(100, LEDController::halfPeriodForTemperature(85));
}
void test_warmer_always_faster_in_mapping_range() {
    uint32_t previous = 1001;
    for (int temperature = 0; temperature <= 50; ++temperature) {
        const uint32_t current = LEDController::halfPeriodForTemperature(temperature);
        TEST_ASSERT_TRUE(current < previous);
        previous = current;
    }
}
void test_full_blink_period_and_boundaries() {
    LEDController led;
    TEST_ASSERT_TRUE(led.update(25, 100));
    TEST_ASSERT_TRUE(led.update(25, 649));
    TEST_ASSERT_FALSE(led.update(25, 650));
    TEST_ASSERT_FALSE(led.update(25, 1199));
    TEST_ASSERT_TRUE(led.update(25, 1200));
}
void test_no_transition_when_polled_at_same_time() {
    LEDController led;
    led.update(50, 0);
    TEST_ASSERT_FALSE(led.update(50, 100));
    TEST_ASSERT_FALSE(led.update(50, 100));
}
void test_millis_rollover() {
    LEDController led;
    const uint32_t start = UINT32_MAX - 49;
    TEST_ASSERT_TRUE(led.update(50, start));
    TEST_ASSERT_TRUE(led.update(50, 49));
    TEST_ASSERT_FALSE(led.update(50, 50));
    TEST_ASSERT_TRUE(led.update(50, 150));
}
void test_delayed_loop_keeps_phase_and_parity() {
    LEDController led;
    led.update(50, 0);
    TEST_ASSERT_TRUE(led.update(50, 450));
    TEST_ASSERT_FALSE(led.update(50, 500));
}
void test_invalid_readings_turn_led_off() {
    const float invalid[] = {NAN, INFINITY, -INFINITY, -41.0f, 86.0f};
    for (float value : invalid) {
        LEDController led;
        TEST_ASSERT_TRUE(led.update(25, 0));
        TEST_ASSERT_FALSE(led.update(value, 1));
        TEST_ASSERT_EQUAL_UINT32(0, led.halfPeriodMs());
    }
}
void test_recovery_starts_new_period() {
    LEDController led;
    led.update(50, 0);
    led.update(NAN, 99);
    TEST_ASSERT_TRUE(led.update(50, 500));
    TEST_ASSERT_TRUE(led.update(50, 599));
    TEST_ASSERT_FALSE(led.update(50, 600));
}
void test_temperature_change_updates_period() {
    LEDController led;
    led.update(0, 0);
    TEST_ASSERT_FALSE(led.update(50, 100));
    TEST_ASSERT_EQUAL_UINT32(100, led.halfPeriodMs());
    TEST_ASSERT_TRUE(led.update(50, 200));
}
int main() {
    UNITY_BEGIN();
    RUN_TEST(test_mapping_and_clamping);
    RUN_TEST(test_warmer_always_faster_in_mapping_range);
    RUN_TEST(test_full_blink_period_and_boundaries);
    RUN_TEST(test_no_transition_when_polled_at_same_time);
    RUN_TEST(test_millis_rollover);
    RUN_TEST(test_delayed_loop_keeps_phase_and_parity);
    RUN_TEST(test_invalid_readings_turn_led_off);
    RUN_TEST(test_recovery_starts_new_period);
    RUN_TEST(test_temperature_change_updates_period);
    return UNITY_END();
}
