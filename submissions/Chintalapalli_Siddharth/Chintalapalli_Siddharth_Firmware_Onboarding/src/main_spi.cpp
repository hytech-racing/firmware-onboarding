#include <Arduino.h>
#include "BMESPIInterface.h"
#include "BMEConstants.h"
#include "LEDController.h"

uint32_t lastReadMs = 0;

void setup() {
    Serial.begin(BMEConstants::SERIAL_BAUD_RATE);
    pinMode(BMEConstants::LED_PIN, OUTPUT);

    BMESPIInterfaceInstance::create();
    LEDControllerInstance::create();

    if (!BMESPIInterfaceInstance::instance().init()) {
        Serial.println("BME Could not be found. SPI interface not working.");
    }
}

void loop() {
    uint32_t nowMs = millis();

    if (nowMs - lastReadMs >= BMEConstants::SENSOR_READ_INTERVAL_MS) {
        lastReadMs = nowMs;

        BMESPIInterfaceInstance::instance().update();
        float temperatureC = BMESPIInterfaceInstance::instance().getTemperature();

        LEDControllerInstance::instance().setTemp(temperatureC);
        Serial.println(temperatureC);
    }

    LEDControllerInstance::instance().update(nowMs);
    digitalWrite(BMEConstants::LED_PIN, LEDControllerInstance::instance().isLedOn());

}