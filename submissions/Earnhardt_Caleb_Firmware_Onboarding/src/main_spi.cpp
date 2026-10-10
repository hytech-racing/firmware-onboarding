#include <Arduino.h>
#include "BMESPIinterface.h"

bool sensor_ready = false;

void setup()
{
    Serial.begin(115200);

    sensor_ready =
        BMESPIinterfaceInstance::instance().initialize();

    if (!sensor_ready)
    {
        Serial.println("BME280 initialization failed");
    }
}

void loop()
{
    if (sensor_ready)
    {
        float temperature =
            BMESPIinterfaceInstance::instance().read_temperature();

        Serial.print("Temperature: ");
        Serial.println(temperature);
    }
}