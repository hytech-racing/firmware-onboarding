#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

unsigned long lastPrintTime = 0;

void setup()
{
    Serial.begin(115200);
    Serial.println("Starting BME280 I2C Test...");

    LEDControllerInstance::instance().init();

    bool sensorFound = BMEI2CInterfaceInstance::instance().init();

    if (!sensorFound) {
        Serial.println("Failed to find BME280 on I2C. Check wiring!");
        while (1) {

        }
    }
}

void loop()
{
    float currentTemp = BMEI2CInterfaceInstance::instance().getTemperature();

    LEDControllerInstance::instance().update(currentTemp);

    if (millis() - lastPrintTime >= 100) {
        lastPrintTime = millis();
        Serial.print("I2C Temp: ");
        Serial.print(currentTemp);
        Serial.println(" C");
    }
}