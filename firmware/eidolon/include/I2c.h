#pragma once
#include <Wire.h>
#include "Config.h"

class I2c {
public:
    static void init();
    static TwoWire& getWire();
    static bool isDevicePresent(uint8_t address);

private:
    static TwoWire* wire;
};
