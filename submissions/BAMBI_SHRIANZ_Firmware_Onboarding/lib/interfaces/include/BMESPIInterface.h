#pragma once
#include <Adafruit_BME280.h>
#include <etl/singleton.h>
#include "BMEConstants.h"

class BMESPIInterface
{
public:
    BMESPIInterface() = default;

    // Returns false if the sensor was not found (wiring / CS problem).
    bool init();
    // Reads and stores the latest temperature.
    void tick();
    BMEConstants::celsius read_temperature();
    bool is_ready() const { return ready_; }

private:
    Adafruit_BME280 bme_{BMEConstants::SPI_CS_PIN};
    BMEConstants::celsius temperature_c_ = 0.0f;
    bool ready_ = false;
};

using BMESPIInterfaceInstance = etl::singleton<BMESPIInterface>;