#include "BMESPIInterface.h"

BMESPIInterface::BMESPIInterface() : bme(BMEConstants::SPI_CS_PIN) {}    

bool BMESPIInterface::init() {
    initialized = bme.begin();
    return initialized;
}   

void BMESPIInterface::update() {
    if (initialized) {
        temperatureC = bme.readTemperature();
    }
}

float BMESPIInterface::getTemperature() const {
    return temperatureC;
}
