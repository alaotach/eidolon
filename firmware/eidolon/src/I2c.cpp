#include <I2c.h>

TwoWire* I2c::wire = nullptr;

void I2C::init() {
    wire = new TwoWire(0);
    wire->begin(OLED_SDA, OLED_SCL, 400000);
};

TwoWire& I2C::getWire() {
    if (!wire) {
        init();
    }
    return *wire;
}

bool I2C::isDevicePresent(uint8_t address) {
    wire->beginTransmission(address);
    byte err = wire->endTransmission();
    return err == 0;
}