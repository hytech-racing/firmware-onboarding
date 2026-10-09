#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"
#include "BMEI2CInterface.h"


bool BMEI2CInterface::init () {       
    return new_sensor.begin(BMEConstants::i2c_address);
}; 

float BMEI2CInterface::getTemperature() {
    return new_sensor.readTemperature();
};
