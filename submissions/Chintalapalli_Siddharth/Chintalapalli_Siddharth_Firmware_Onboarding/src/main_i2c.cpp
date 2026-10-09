#include <Arduino.h>
#include "BMEConstants.h"
#include "BMEI2CInterface.h"
#include "LEDController.h"

uint32_t lastReadMs = 0;

void setup() {
    Serial.begin(BMEConstants::SERIAL_BAUD_RATE);
    pinMode(BMEConstants::LED_PIN,OUTPUT);

    BMEI2CInterfaceInstance::create();
    LEDControllerInstance::create();

    if (!BMEI2CInterfaceInstance::instance().init()) {
        Serial.println("BME280 could not be found. Double Check wiring + Address");
    }
}

void loop() {
    uint32_t nowMs = millis();

    if (nowMs - lastReadMs >= BMEConstants::SENSOR_READ_INTERVAL_MS) {
        lastReadMs = nowMs;

        BMEI2CInterfaceInstance::instance().update();
        float temperatureC = BMEI2CInterfaceInstance::instance().getTemperature();

        LEDControllerInstance::instance().setTemp(temperatureC);
        Serial.println(temperatureC);
    }

    LEDControllerInstance::instance().update(nowMs);
    digitalWrite(BMEConstants::LED_PIN, LEDControllerInstance::instance().isLedOn());
    
}

