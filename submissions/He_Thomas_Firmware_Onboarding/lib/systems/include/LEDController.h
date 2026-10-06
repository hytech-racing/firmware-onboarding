#pragma once
#include <Arduino.h>
#include <etl/singleton.h>

class LEDController
{
public:
	LEDController() = default;

	void setup();
	void blinkblinkblink(float temp);
};

using LEDControllerInstance = etl::singleton<LEDController>;
