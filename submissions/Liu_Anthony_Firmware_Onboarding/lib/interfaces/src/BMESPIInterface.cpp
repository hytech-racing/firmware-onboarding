#include "BMESPIInterface.h"


bool BMESPIInterface::init(uint8_t cs_pin)
{
    // Adafruit_BME280(int8_t cspin, SPIClass *theSPI = &SPI);
    _bme = new Adafruit_BME280(cs_pin);
    return _bme->begin();
}

celsius BMESPIInterface::read_temperature()
{
  return _bme->readTemperature();
}