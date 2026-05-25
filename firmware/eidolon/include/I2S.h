#pragma once
#include <driver/i2s.h>
#include "Config.h"

class I2S {
public:
    static void init();
    static void deinit();
    static esp_err_t read(uint32_t* buffer, size_t size, size_t* bytesRead);
    static esp_err_t write(uint32_t* buffer, size_t size, size_t* bytesWritten);

private:
    static void initMic();
    static void initSpeaker();
};