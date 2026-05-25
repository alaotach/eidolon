#include <I2c.h>

TwoWire* I2c::wire = nullptr;

void I2c::init() {
    wire = new TwoWire(0);
    wire->begin(OLED_SDA, OLED_SCL, 400000);
};

TwoWire& I2c::getWire() {
    if (!wire) {
        init();
    }
    return *wire;
}

bool I2c::isDevicePresent(uint8_t address) {
    wire->beginTransmission(address);
    uint8_t err = wire->endTransmission();
    return err == 0;
}