#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

BMESPIInterface sensor;
LEDController led(BMEConstants::LED_PIN);

void setup()
{
    // Initialize serial communication and the LED
    Serial.begin(115200);
    led.begin();

    // Check that SPI communication with the sensor works
    if (!sensor.begin())
    {
        Serial.println("BME280 SPI initialization failed!");

        while (true)
        {
            delay(1000);
        }
    }
}

void loop()
{
    // Read the current temperature through SPI
    float temperature = sensor.readTemperature();

    // Update the LED using the temperature reading
    led.update(temperature);

    Serial.print("Temperature: ");
    Serial.println(temperature);
}