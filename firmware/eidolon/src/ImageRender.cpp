#include "ImageRender.h"
#include "OLED.h"
#include "LittleFSM.h"

bool ImageR::renderBMP(const String& path) {
    File f = LittleFSM::open(path.c_str(), "r");
    if (!f) {
        return false;
    }
    if (!isBMP(f)) {
        f.close();
        return false;
    }
    bool res = renderBMPMono(f);
    f.close();
    return res;
}

bool ImageR::renderRaw(const String& path, uint16_t x, uint16_t y) {
    File f = LittleFSM::open(path.c_str(), "r");
    if (!f) {
        return false;
    }
    OLED::clear();
    size_t ppb = 8;
    size_t bpl = (x+ppb-1)/ppb;
    for (uint16_t i = 0; i < y; i++) {
        for (uint16_t j = 0; j < bpl; j++) {
            uint8_t b = f.read();
            for (uint8_t k = 0; k < ppb; k++) {
                if (b & (1 << k)) {
                    OLED::drawPixel(j*ppb+k, i, WHITE);
                }
            }
        }
    }
    OLED::update();
    f.close();
    return true;
}

void ImageR::clear() {
    OLED::clear();
    OLED::update();
}


bool ImageR::isBMP(File& f) {
    uint8_t header[2];
    if (!f.read(header, 2)) {
        return false;
    }
    return header[0] == 'B' && header[1] == 'M';
}

bool ImageR::renderBMPMono(File& f) {
    if (f.size() <= 54) {
        return false;
    }
    
    f.seek(54);
    OLED::clear();
    for (int y = 0; y < SCREEN_HEIGHT; y++) {
        for (int x = 0; x < SCREEN_WIDTH; x += 8) {
            uint8_t byte;
            if (!f.read(&byte, 1)) {
                return false;
            }
            for (int bit = 0; bit < 8; bit++) {
                OLED::drawPixel(x + bit, y, (byte & (1 << (7 - bit))) ? 1 : 0);
            }
        }
    }
    OLED::update();
    return true;
}