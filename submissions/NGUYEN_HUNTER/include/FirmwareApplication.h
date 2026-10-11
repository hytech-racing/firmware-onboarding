#pragma once
#include <Arduino.h>
#include "BMEConstants.h"
#include "LEDController.h"

// Main-loop orchestration shared by the two entry points, not sensor policy.
template <typename SensorInstance>
class FirmwareApplication {
public:
    void setup(const __FlashStringHelper* busName) {
        pinMode(BMEConstants::LED_PIN, OUTPUT);
        digitalWrite(BMEConstants::LED_PIN, LOW);
        Serial.begin(BMEConstants::SERIAL_BAUD);
        Serial.println(F("NGUYEN_HUNTER Firmware Onboarding"));
        Serial.println(busName);
        SensorInstance::create();
        attemptConnection(millis());
    }

    void loop() {
        const uint32_t now = millis();
        if (!connected_) {
            digitalWrite(BMEConstants::LED_PIN, LOW);
            if (now - lastAttemptMs_ >= BMEConstants::RETRY_INTERVAL_MS)
                attemptConnection(now);
            return;
        }
        if (now - lastSampleMs_ >= BMEConstants::SAMPLE_INTERVAL_MS) {
            lastSampleMs_ = now;
            temperatureC_ = SensorInstance::instance().readTemperature();
            if (!LEDController::isValidTemperature(temperatureC_)) {
                controller_.update(temperatureC_, now);
                connected_ = false;
                lastAttemptMs_ = now;
                digitalWrite(BMEConstants::LED_PIN, LOW);
                Serial.println(F("Invalid temperature; LED off, retrying sensor."));
                return;
            }
            Serial.print(F("Temperature_C="));
            Serial.print(temperatureC_, 2);
            Serial.print(F(" half_period_ms="));
            Serial.println(LEDController::halfPeriodForTemperature(temperatureC_));
        }
        digitalWrite(BMEConstants::LED_PIN,
                     controller_.update(temperatureC_, now) ? HIGH : LOW);
    }

private:
    void attemptConnection(uint32_t now) {
        lastAttemptMs_ = now;
        connected_ = SensorInstance::instance().begin();
        if (!connected_) {
            Serial.println(F("BME280 not found; check bus wiring/address. Retry in 2 s."));
            return;
        }
        Serial.println(F("BME280 connected."));
        // Schedule a fresh read on the next loop; do not blink on stale data.
        lastSampleMs_ = now - BMEConstants::SAMPLE_INTERVAL_MS;
    }
    LEDController controller_;
    bool connected_ = false;
    float temperatureC_ = NAN;
    uint32_t lastAttemptMs_ = 0;
    uint32_t lastSampleMs_ = 0;
};
