#include "BMESPIInterface.h" 
#include <SPI.h> 

BMESPIInterface::BMESPIInterface()
	: sensor(BMEConstants::spiChipSelectPin, &SPI) // Selects SPI mode and assigns the chip-select pin.
{
}

bool BMESPIInterface::begin()
{
	return sensor.begin(); // Initializes the already-configured SPI sensor.
}

float BMESPIInterface::readTemperatureC()
{
	return sensor.readTemperature(); // Forward the driver's Celsius temperature reading to the caller.
}
