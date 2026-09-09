#include "BMEI2Cinterface.h"
#include "BMEConstants.h"
#include <Adafruit_BME280.h>

bool BMEI2CInterface::start_sensor(){
    return sensor.begin(BMEConstants::I2C_ADDRESS);
}
float BMEI2CInterface::findtemp(){
    return sensor.readTemperature();
}
