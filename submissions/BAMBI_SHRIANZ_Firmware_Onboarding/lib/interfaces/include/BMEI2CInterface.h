#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMEI2CInterface
{
public:
    BMEI2CInterface() = default;

    // Returns false if the sensor was not found (wiring / address problem).
    bool init();
    // Reads and stores the latest temperature.
    void tick();
    BMEConstants::celsius read_temperature();
    bool is_ready() const { return ready_; }

private:
    Adafruit_BME280 bme_;
    BMEConstants::celsius temperature_c_ = 0.0f;
    bool ready_ = false;
};

using BMEI2CInterfaceInstance = etl::singleton<BMEI2CInterface>;