#include "BMEI2CInterface.h"

bool BMEI2CInterface::init() {
    initialized = bme.begin(BMEConstants::I2C_ADDRESS);
    return initialized;

}

void BMEI2CInterface::update() {
    if (initialized) {
        temperatureC = bme.readTemperature();
    }
}

float BMEI2CInterface::getTemperature() const {
    return temperatureC;
}

