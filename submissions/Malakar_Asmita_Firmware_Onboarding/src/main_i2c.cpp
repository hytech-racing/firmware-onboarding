#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

uint32_t lastPrint = 0;

void setup()
{
    Serial.begin(BMEConstants::SERIAL_BAUD);
    //led - output
    pinMode(BMEConstants::LED_PIN, OUTPUT);

    BMEI2CInterfaceInstance::create();
    LEDControllerInstance::create();

    if (!BMEI2CInterfaceInstance::instance().init())
    {
        Serial.println("ERROR: BME280 not connecting over I2C");
        while (true) {}
    }

    Serial.println("BME280 ready (I2C)");
}

void loop()
{
    uint32_t now = millis();

    float temp = BMEI2CInterfaceInstance::instance().readTemperature();

    // Update LED speed
    bool ledOn = LEDControllerInstance::instance().update(temp, now);


    digitalWrite(BMEConstants::LED_PIN, ledOn ? HIGH : LOW);

    if (now - lastPrint >= BMEConstants::PRINT_PERIOD_MS)
    {
        lastPrint = now;
        Serial.print("Temp: ");
        Serial.print(temp);
        Serial.println(" C");
    }
}