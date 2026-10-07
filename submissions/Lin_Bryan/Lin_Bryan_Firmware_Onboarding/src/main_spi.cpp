#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

unsigned long lastPrintTime = 0;

void setup()
{
    Serial.begin(115200);
    Serial.println("Starting BME280 SPI Test...");

    LEDControllerInstance::instance().init();

    bool sensorFound = BMESPIInterfaceInstance::instance().init();

    if (!sensorFound) {
        Serial.println("Failed to find BME280 on SPI. Check wiring!");
        while (1) {
            
        }
    }
}

void loop()
{
    float currentTemp = BMESPIInterfaceInstance::instance().getTemperature();

    LEDControllerInstance::instance().update(currentTemp);

    if (millis() - lastPrintTime >= 100) {
        lastPrintTime = millis();
        Serial.print("SPI Temp: ");
        Serial.print(currentTemp);
        Serial.println(" C");
    }
}