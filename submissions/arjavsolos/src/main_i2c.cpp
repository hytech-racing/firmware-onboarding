#include <Arduino.h>

#include "BMEConstants.h"
#include "BMEI2CInterface.h"
#include "LEDController.h"

namespace
{
unsigned long previousSensorReadMs = 0UL;
}

void setup()
{
    Serial.begin(115200);

    LEDControllerInstance::instance().begin();

    if (!BMEI2CInterfaceInstance::instance().begin())
    {
        Serial.println(F("BME280 not found over I2C. Check wiring and I2C_ADDRESS."));
        while (true)
        {
            delay(1000);
        }
    }

    Serial.println(F("BME280 I2C interface ready."));
}

void loop()
{
    const unsigned long nowMs = millis();

    if (nowMs - previousSensorReadMs >= BMEConstants::SENSOR_READ_INTERVAL_MS)
    {
        previousSensorReadMs = nowMs;

        if (BMEI2CInterfaceInstance::instance().update())
        {
            const float temperatureC =
                BMEI2CInterfaceInstance::instance().temperatureC();

            Serial.print(F("Temperature: "));
            Serial.print(temperatureC, 2);
            Serial.println(F(" C"));
        }
        else
        {
            Serial.println(F("Could not read temperature over I2C."));
        }
    }

    const float temperatureC = BMEI2CInterfaceInstance::instance().temperatureC();
    if (!isnan(temperatureC))
    {
        LEDControllerInstance::instance().update(temperatureC, nowMs);
    }
}
