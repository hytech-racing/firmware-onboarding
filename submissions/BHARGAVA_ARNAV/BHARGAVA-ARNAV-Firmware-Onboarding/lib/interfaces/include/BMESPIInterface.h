#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    BMESPIInterface() = default;

    bool init ();
    float getTemperature();


 // Code here!
private:
 // Code here!
    Adafruit_BME280 new_sensor{BMEConstants::the_cspin,
                               &SPI
                               };
};
using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;


/*
Adafruit_BME280();
  Adafruit_BME280(int8_t cspin, SPIClass *theSPI = &SPI);
  Adafruit_BME280(int8_t cspin, int8_t mosipin, int8_t misopin, int8_t sckpin);

*/