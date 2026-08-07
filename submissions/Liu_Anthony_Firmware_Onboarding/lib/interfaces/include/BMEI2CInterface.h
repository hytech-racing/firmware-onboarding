#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

using celsius = float;

class BMEI2CInterface
{
public:

    BMEI2CInterface() = default;

    bool init(uint8_t address);

    celsius read_temperature();

private:

    Adafruit_BME280 _bme;

};
using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;