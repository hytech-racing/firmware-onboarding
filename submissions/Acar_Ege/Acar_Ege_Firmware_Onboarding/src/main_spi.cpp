#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"

BMESPIInterface sensor;
LEDController led;

void setup()
{
    Serial.begin(115200);

    led.begin(LED_BUILTIN);

    if (!sensor.begin())
    {
        Serial.println("BME280 SPI sensor not found!");

        while (true)
        {
            delay(1000);
        }
    }

    Serial.println("BME280 SPI initialized successfully!");
}

void loop()
{
    float temperature = sensor.readTemperature();

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");

    led.update(temperature);
}