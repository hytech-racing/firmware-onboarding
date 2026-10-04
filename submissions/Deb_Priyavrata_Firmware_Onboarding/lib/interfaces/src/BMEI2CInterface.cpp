#include "BMEI2CInterface.h" 

bool BMEI2CInterface::begin()
{
	// Try the primary address first, and try the alternate address only if needed.
	return sensor.begin(BMEConstants::i2cAddressPrimary) ||
		   sensor.begin(BMEConstants::i2cAddressSecondary);
}

float BMEI2CInterface::readTemperatureC()
{
	return sensor.readTemperature(); // Forward the driver's Celsius temperature reading to the caller.
}
