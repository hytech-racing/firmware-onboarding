#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

uint32_t lastPrint = 0;

void setup()
{
    Serial.begin(BMEConstants::SERIAL_BAUD);
    pinMode(BMEConstants::LED_PIN, OUTPUT);

    BMESPIInterfaceInstance::create();
    LEDControllerInstance::create();

    if (!BMESPIInterfaceInstance::instance().init())
    {
        Serial.println("ERROR: BME280 not connecting over SPI");
        while (true) {}
    }

    Serial.println("BME280 ready (SPI)");
}

void loop()
{
    uint32_t now = millis();

    float temp = BMESPIInterfaceInstance::instance().readTemperature();

    bool ledOn = LEDControllerInstance::instance().update(temp, now);

    digitalWrite(BMEConstants::LED_PIN, ledOn ? HIGH : LOW);

    // Print every 500 ms
    if (now - lastPrint >= BMEConstants::PRINT_PERIOD_MS)
    {
        lastPrint = now;
        Serial.print("Temp: ");
        Serial.print(temp);
        Serial.println(" C");
    }
}