#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>

using celsius = float;

class BMESPIInterface
{
public:

    BMESPIInterface() = default;

    /**
     * @param cs_pin is whatever digital pin we wire to the sensor's CS line.
     * Returns true if the sensor responded correctly.
     */
    bool init(uint8_t cs_pin);

    celsius read_temperature();

private:

    // A pointer, not a plain Adafruit_BME280 object. The default
    // member-declaration form (Adafruit_BME280 _bme;) would call the
    // no-argument I2C constructor immediately, before init(cs_pin) ever
    // runs — permanently locking this object into I2C mode regardless
    // of what pin gets passed in later. Delaying construction until
    // init() actually knows cs_pin is what makes SPI mode possible.
    Adafruit_BME280 *_bme = nullptr;

};
using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;