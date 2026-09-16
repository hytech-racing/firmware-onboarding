#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterface
{
public:
    BMEI2CInterface() = default;

    bool init ();
    float getTemperature();

 // Code here!
private:
 // Code here!
    Adafruit_BME280 new_sensor;

};
using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;
