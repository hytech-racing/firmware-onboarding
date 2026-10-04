#pragma once

#include <Arduino.h> 

class LEDController {
public:
	void begin(uint8_t pin); // Configures the selected LED pin and starts it in the off state.
	void setTemperature(float temperatureC); // Converts a Celsius reading into a blink-cycle duration.
	void update(); // Toggles the LED when enough time has elapsed; does not block the main loop.

private:
	uint8_t pin = LED_BUILTIN; // Stores which Arduino pin controls the LED.
	bool ledOn = false; // Tracks the output state so each update can toggle it.
	unsigned long lastToggleMs = 0; // Records when the LED last changed state.
	unsigned long blinkPeriodMs = 1000; // Stores the full on/off cycle duration in milliseconds.
};
