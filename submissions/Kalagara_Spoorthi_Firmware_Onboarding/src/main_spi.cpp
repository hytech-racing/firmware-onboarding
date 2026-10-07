#include <Arduino.h>
#include "BMESPIInterface.h"

void setup()
{
    Serial.begin(115200);

    BMESPIInterfaceInstance::create();

    if (!BMESPIInterfaceInstance::instance().begin())
    {
        Serial.println("BME280 not found over SPI, check wiring");
    }
}

void loop()
{
    auto &bme = BMESPIInterfaceInstance::instance();

    Serial.print("Temp (C): ");
    Serial.println(bme.readTemperature());
    Serial.print("Pressure (Pa): ");
    Serial.println(bme.readPressure());
    Serial.print("Humidity (%): ");
    Serial.println(bme.readHumidity());

    delay(1000);
}