#include <Arduino.h>
#include "BMEI2CInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

BMEI2CInterface sensor;
LEDController led(BMEConstants::LED_PIN);

void setup()
{
    // Start serial communication and initialize the LED
    Serial.begin(115200);
    led.begin();

    // Stop if the sensor cannot be initialized
    if (!sensor.begin())
    {
        Serial.println("BME280 not found!");

        while (true)
        {
            delay(1000);
        }
    }
}

void loop()
{
    // Get the current temperature from the sensor
    float temperature = sensor.readTemperature();

    // Adjust LED timing based on the temperature
    led.update(temperature);

    Serial.print("Temperature: ");
    Serial.println(temperature);
}