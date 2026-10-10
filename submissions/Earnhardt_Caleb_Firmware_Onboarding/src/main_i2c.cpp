#include <Arduino.h>
#include "BMEI2Cinterface.h"

bool sensor_ready = false;

void setup()
{
    Serial.begin(115200);

    sensor_ready =
        BMEI2CinterfaceInstance::instance().initialize();

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
            BMEI2CinterfaceInstance::instance().read_temperature();

        Serial.print("Temperature: ");
        Serial.println(temperature);
    }
}