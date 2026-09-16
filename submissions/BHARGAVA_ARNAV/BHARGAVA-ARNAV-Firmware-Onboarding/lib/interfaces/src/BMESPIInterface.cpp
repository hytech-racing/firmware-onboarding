#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"
#include "BMESPIInterface.h"          
       
bool BMESPIInterface::init () {       
    return new_sensor.begin();
}; 
float BMESPIInterface::getTemperature() {
    return new_sensor.readTemperature();
}

