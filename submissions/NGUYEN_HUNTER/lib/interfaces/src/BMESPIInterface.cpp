#include "BMESPIInterface.h"

BMESPIInterface::BMESPIInterface() : sensor_(BMEConstants::SPI_CS_PIN, &SPI) {}

bool BMESPIInterface::begin() {
    // The SPI constructor selects the bus; the I2C address argument is unused.
    return sensor_.begin();
}

float BMESPIInterface::readTemperature() {
    temperatureC_ = sensor_.readTemperature();
    return temperatureC_;
}
