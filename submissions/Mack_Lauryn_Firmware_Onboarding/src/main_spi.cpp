#include <Arduino.h>

#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

void setup()
{
    Serial.begin(115200);

    auto& bme = BMESPIInterfaceInstance::instance();

    if (!bme.begin())
    {
        Serial.println("BME280 not found!");
        while (true)
        {
        }
    }

    pinMode(BMEConstants::LED_PIN, OUTPUT);
}

void loop()
{
    auto& bme = BMESPIInterfaceInstance::instance();

    float temperature = bme.get_temperature();

    Serial.print("Temperature: ");
    Serial.println(temperature);

    delay(1000);
}