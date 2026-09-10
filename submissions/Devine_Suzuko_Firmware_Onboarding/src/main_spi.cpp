#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"

void setup() {
    Serial.begin(115200);
    while (!Serial) { delay(10); }

    auto& spiInterface = BMESPIInterfaceInstance::instance();
    if (!spiInterface.begin()) {
        Serial.println(F("BME280 SPI initialization failed!"));
        while (1) { delay(100); }
    }
    Serial.println(F("BME280 SPI initialized."));
}

void loop() {
    auto& spiInterface = BMESPIInterfaceInstance::instance();
    auto& ledController = LEDControllerInstance::instance();

    float temp = spiInterface.readTemperature();
    Serial.print(F("Temp (SPI): "));
    Serial.print(temp);
    Serial.println(F(" °C"));

    ledController.update(temp);
    delay(100);
}