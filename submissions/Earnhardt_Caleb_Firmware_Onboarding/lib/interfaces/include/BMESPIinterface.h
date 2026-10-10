


#pragma once

#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIinterface
{
public:
    BMESPIinterface() = default;

    bool initialize();
    float read_temperature();

private:
    Adafruit_BME280 _sensor{BMEConstants::CS_PIN_VAR_SPI_SENSOR};
    // ^ creates sensor object and defines the pin that it is connected to
    // for purposes of taking in requests or not. 
};

using BMESPIinterfaceInstance = etl::singleton<BMESPIinterface>;