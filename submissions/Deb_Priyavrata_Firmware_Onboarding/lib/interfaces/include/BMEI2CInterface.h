#pragma once
#include <Adafruit_BME280.h> 
#include <etl/singleton.h> 
#include "BMEConstants.h" 

class BMEI2CInterface {
    public:
        bool begin(); // Initializes the sensor, returning false if neither address responds.
        float readTemperatureC(); // Returns the most recently measured temperature in Celsius.
    private:
        Adafruit_BME280 sensor; // The Adafruit driver object used for I2C operations.
};
using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>; // Optional shared instance type for this interface.