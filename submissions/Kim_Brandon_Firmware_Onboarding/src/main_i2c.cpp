#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

void setup()
{
    Serial.begin(BMEConstants::SERIAL_BAUD);
    pinMode(BMEConstants::LED_PIN, OUTPUT);

    BMESPIInterfaceInstance::create();
    LEDControllerInstance::create();

    if (!BMESPIInterfaceInstance::instance().begin())
    {
        Serial.println(F("BME280 not found over SPI. Check wiring and BME_CS_PIN."));
        while (true)
        {
        }
    }

    BMESPIInterfaceInstance::instance().update();
}

void loop()
{
    static uint32_t lastReadMs = 0;

    auto &sensor = BMESPIInterfaceInstance::instance();
    auto &controller = LEDControllerInstance::instance();

    uint32_t now = millis();

    if (now - lastReadMs >= BMEConstants::SENSOR_READ_INTERVAL_MS)
    {
        lastReadMs = now;
        sensor.update();

        Serial.print(F("Temp (C): "));
        Serial.print(sensor.getTemperatureC());
        Serial.print(F("  blink interval (ms): "));
        Serial.println(controller.getBlinkIntervalMs());
    }

    controller.update(sensor.getTemperatureC(), now);
    digitalWrite(BMEConstants::LED_PIN, controller.isLedOn() ? HIGH : LOW);
}