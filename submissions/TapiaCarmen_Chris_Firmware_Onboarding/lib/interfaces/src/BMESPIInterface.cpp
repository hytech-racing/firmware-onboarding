#include "BMESPIInterface.h"
#include "BMEConstants.h"
#include <Adafruit_BME280.h>


bool BMESPIInterface::start_sensor(){
    return sensor.begin(BMEConstants::I2C_ADDRESS);
}
float BMESPIInterface::findtemp(){
    return sensor.readTemperature();
}
