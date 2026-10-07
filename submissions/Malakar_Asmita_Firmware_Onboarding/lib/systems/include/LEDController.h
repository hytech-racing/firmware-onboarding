#pragma once
#include <stdint.h>
#include <etl/singleton.h>

class LEDController
{
public:
    bool update(float temperature, uint32_t now);

private:
    uint32_t lastToggle = 0;
    bool on = false;
};

using LEDControllerInstance = etl::singleton<LEDController>;