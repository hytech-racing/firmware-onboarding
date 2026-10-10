#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

static unsigned long last_read_ms = 0;

void setup()
{
    Serial.begin(BMEConstants::SERIAL_BAUD);

    BMEI2CInterfaceInstance::create();
    LEDControllerInstance::create();

    LEDControllerInstance::instance().init();

    if (!BMEI2CInterfaceInstance::instance().init())
    {
        Serial.println(F("BME280 not found over I2C - check wiring/address"));
    }
}

void loop()
{
    const unsigned long now = millis();

    if (now - last_read_ms >= BMEConstants::SENSOR_READ_PERIOD_MS)
    {
        last_read_ms = now;
        BMEI2CInterfaceInstance::instance().tick();

        BMEConstants::celsius temp_C = BMEI2CInterfaceInstance::instance().read_temperature();
        Serial.print(F("Temp (C): "));
        Serial.println(temp_C);
    }

    LEDControllerInstance::instance().update(
        BMEI2CInterfaceInstance::instance().read_temperature(), now);
}