#include <Arduino.h>
#include "BMESPIInterface.h"
#include "LEDController.h"
#include "BMEConstants.h"

void setup()
{
    Serial.begin(115200);

    // Create singleton instances.
    BMESPIInterfaceInstance::create();
    LEDControllerInstance::create();

    BMESPIInterface& bme =
        BMESPIInterfaceInstance::instance();

    LEDController& led =
        LEDControllerInstance::instance();

    led.begin();

    Serial.println("Starting BME280 in SPI mode...");

    if (!bme.begin())
    {
        Serial.println("ERROR: BME280 not found!");

        while (true)
        {
            // Stop here because the sensor did not initialize.
        }
    }

    Serial.println("BME280 initialized successfully.");
}

void loop()
{
    BMESPIInterface& bme =
        BMESPIInterfaceInstance::instance();

    LEDController& led =
        LEDControllerInstance::instance();

    static unsigned long previousReadTime = 0;
    static float temperature = 0.0;

    unsigned long currentTime = millis();

    if (currentTime - previousReadTime >=
        BMEConstants::SENSOR_READ_INTERVAL_MS)
    {
        previousReadTime = currentTime;

        temperature = bme.readTemperature();

        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" C");
    }

    led.update(temperature);
}