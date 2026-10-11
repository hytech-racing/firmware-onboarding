#include "BMEI2CInterface.h"

bool BMEI2CInterface::begin() {
    return sensor_.begin(BMEConstants::I2C_ADDRESS);
}

float BMEI2CInterface::readTemperature() {
    temperatureC_ = sensor_.readTemperature();
    return temperatureC_;
}
