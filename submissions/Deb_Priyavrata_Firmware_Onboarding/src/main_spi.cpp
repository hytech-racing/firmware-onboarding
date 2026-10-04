#include <Arduino.h> 
#include "BMESPIInterface.h" 
#include "LEDController.h" 
#include "BMEConstants.h"

BMESPIInterface sensor; // Owns the BME280 device accessed over SPI.
LEDController led; // Owns the LED pin and its current blink timing.
unsigned long lastSensorReadMs = 0; // Remembers when the previous sample was taken.
bool sensorReady = false; // Prevents temperature reads if startup could not find the sensor.

void setup()
{
    Serial.begin(115200); // Starts the serial monitor output at 115200 baud.
    led.begin(BMEConstants::spiLedPin); // Configures the external LED on pin 7 as an output.

    sensorReady = sensor.begin(); // Starts SPI communication and checks for the BME280.
    if (!sensorReady) {
        Serial.println("BME280 not found over SPI"); // Reports an initialization failure.
        return; // Leaves the loop running the LED without requesting invalid sensor data.
    }

    Serial.println("BME280 ready over SPI"); // Confirms that the sensor initialized successfully.
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