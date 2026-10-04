#include "LEDController.h" 
#include "BMEConstants.h" 

void LEDController::begin(uint8_t ledPin)
{
	pin = ledPin; // Remember which physical pin should drive the LED.
	pinMode(pin, OUTPUT); // Configure that pin to send an output signal.
	digitalWrite(pin, LOW); // Start with the LED off.
	lastToggleMs = millis(); // Begin the timing interval from the current time.
}

void LEDController::setTemperature(float temperatureC)
{
	// Keep the input within the range used for the blink-speed mapping.
	const float clampedTemperature = constrain(
		temperatureC,
		BMEConstants::coolestTemperatureC,
		BMEConstants::warmestTemperatureC);
	// Convert the bounded temperature to a fraction from 0.0 (cool) to 1.0 (warm).
	const float temperatureRatio =
		(clampedTemperature - BMEConstants::coolestTemperatureC) /
		(BMEConstants::warmestTemperatureC - BMEConstants::coolestTemperatureC);
	// Interpolate from a long cycle when cool to a short cycle when warm.
	blinkPeriodMs = BMEConstants::slowBlinkPeriodMs -
		static_cast<unsigned long>(temperatureRatio *
			(BMEConstants::slowBlinkPeriodMs - BMEConstants::fastBlinkPeriodMs));
}

void LEDController::update()
{
	const unsigned long halfPeriodMs = blinkPeriodMs / 2; // Each toggle is half of a complete on/off cycle.
	const unsigned long now = millis(); // Read the current time without pausing program execution.
	if (now - lastToggleMs >= halfPeriodMs) {
		ledOn = !ledOn; // Switch the tracked state from on to off, or off to on.
		digitalWrite(pin, ledOn ? HIGH : LOW); // Apply the new state to the physical output pin.
		lastToggleMs = now; // Restart the half-cycle timer after changing the LED state.
	}
}
