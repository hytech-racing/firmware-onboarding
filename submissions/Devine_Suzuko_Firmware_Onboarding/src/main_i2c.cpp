#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"

void setup() {
    Serial.begin(115200);
    while (!Serial) { delay(10); }

    auto& i2cInterface = BMEI2CInterfaceInstance::instance();
    if (!i2cInterface.begin(0x76)) {
        Serial.println(F("BME280 I2C initialization failed!"));
        while (1) { delay(100); }
    }
    Serial.println(F("BME280 I2C initialized."));
}

void loop() {
    auto& i2cInterface = BMEI2CInterfaceInstance::instance();
    auto& ledController = LEDControllerInstance::instance();

    float temp = i2cInterface.readTemperature();
    Serial.print(F("Temp (I2C): "));
    Serial.print(temp);
    Serial.println(F(" °C"));

    ledController.update(temp);
    delay(100);
}