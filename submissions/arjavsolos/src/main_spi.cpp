#include <Arduino.h>

#include "BMEConstants.h"
#include "BMESPIInterface.h"
#include "LEDController.h"

namespace
{
unsigned long previousSensorReadMs = 0UL;
}

void setup()
{
    Serial.begin(115200);

    LEDControllerInstance::instance().begin();

    if (!BMESPIInterfaceInstance::instance().begin())
    {
        Serial.println(F("BME280 not found over SPI. Check wiring and SPI_CS_PIN."));
        while (true)
        {
            delay(1000);
        }
    }

    Serial.println(F("BME280 SPI interface ready."));
}

void loop()
{
    const unsigned long nowMs = millis();

    if (nowMs - previousSensorReadMs >= BMEConstants::SENSOR_READ_INTERVAL_MS)
    {
        previousSensorReadMs = nowMs;

        if (BMESPIInterfaceInstance::instance().update())
        {
            const float temperatureC =
                BMESPIInterfaceInstance::instance().temperatureC();

            Serial.print(F("Temperature: "));
            Serial.print(temperatureC, 2);
            Serial.println(F(" C"));
        }
        else
        {
            Serial.println(F("Could not read temperature over SPI."));
        }
    }

    const float temperatureC = BMESPIInterfaceInstance::instance().temperatureC();
    if (!isnan(temperatureC))
    {
        LEDControllerInstance::instance().update(temperatureC, nowMs);
    }
}
