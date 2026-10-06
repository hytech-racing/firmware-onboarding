#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"
#include "BMESPIInterface.h"

bool BMESPIInterface::begin() {
    return bme.begin();
}

float BMESPIInterface::readTemperature() {
    return bme.readTemperature();
}