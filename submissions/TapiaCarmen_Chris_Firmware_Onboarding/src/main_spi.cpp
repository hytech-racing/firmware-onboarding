#include <Arduino.h>
#include "BMESPIInterface.h"

void setup() {
    Serial.begin(115200);

    BMESPIInterfaceInstance::create();

    auto& bme = BMESPIInterfaceInstance::instance();

    if (!bme.start_sensor()) {
        Serial.println("BME280 sensor not found!");
        while (1);
    }

    Serial.println("BME280 sensor started via SPI!");
}

void loop() {
    auto& bme = BMESPIInterfaceInstance::instance();

    float temp = bme.findtemp();
    Serial.print("Temperature: ");
    Serial.print(temp);
    Serial.println(" C");

    delay(2000);
}