#include <Arduino.h> 
#include "BMEI2CInterface.h" 
#include "LEDController.h" 
#include "BMEConstants.h"

BMEI2CInterface sensor;
LEDController led; 
unsigned long lastSensorReadMs = 0; 
bool sensorReady = false; 

void setup()
{
    Serial.begin(115200); 
    led.begin(BMEConstants::i2cLedPin); // Configures the built-in LED as an output.

    sensorReady = sensor.begin(); // Tries the two common BME280 I2C addresses.
    if (!sensorReady) {
        Serial.println("BME280 not found on I2C (checked 0x76 and 0x77)"); // Reports an initialization failure.
        return; // Leaves the loop running the LED without requesting invalid sensor data.
    }

    Serial.println("BME280 ready over I2C"); // Confirms that the sensor initialized successfully.
}

void loop()
{
    led.update(); // Changes the LED state when its current blink interval expires.
    if (!sensorReady) {
        return; // Skip sensor reads if setup did not find a BME280.
    }

    const unsigned long now = millis(); // Gets the time since startup without blocking.
    if (now - lastSensorReadMs >= BMEConstants::sensorReadIntervalMs) {
        lastSensorReadMs = now; // Starts the next one-second sampling interval.
        const float temperatureC = sensor.readTemperatureC(); // Reads the latest temperature in Celsius.
        led.setTemperature(temperatureC); // Makes warmer readings shorten the blink cycle.
        Serial.print("Temperature: "); // Labels the value in the serial monitor.
        Serial.print(temperatureC); // Prints the numeric temperature.
        Serial.println(" C"); // Adds units and ends this line of output.
    }
}