#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"

BMEI2CInterface sensor;
LEDController led;

void setup()
{
    Serial.begin(115200);

    led.begin(LED_BUILTIN);

    if (!sensor.begin())
    {
        Serial.println("BME280 sensor not found!");

        while (true)
        {
            delay(1000);
        }
    }

    Serial.println("BME280 initialized successfully!");
}

void loop()
{
    float temperature = sensor.readTemperature();

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    led.update(temperature);
}