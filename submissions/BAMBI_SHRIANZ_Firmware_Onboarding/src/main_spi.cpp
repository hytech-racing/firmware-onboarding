#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

static unsigned long last_read_ms = 0;

void setup()
{
    Serial.begin(BMEConstants::SERIAL_BAUD);

    BMESPIInterfaceInstance::create();
    LEDControllerInstance::create();

    LEDControllerInstance::instance().init();

    if (!BMESPIInterfaceInstance::instance().init())
    {
        Serial.println(F("BME280 not found over SPI - check wiring/CS pin"));
    }
}

void loop()
{
    const unsigned long now = millis();

    if (now - last_read_ms >= BMEConstants::SENSOR_READ_PERIOD_MS)
    {
        last_read_ms = now;
        BMESPIInterfaceInstance::instance().tick();

        BMEConstants::celsius temp_C = BMESPIInterfaceInstance::instance().read_temperature();
        Serial.print(F("Temp (C): "));
        Serial.println(temp_C);
    }

    LEDControllerInstance::instance().update(
        BMESPIInterfaceInstance::instance().read_temperature(), now);
}