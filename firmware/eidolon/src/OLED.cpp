#include "OLED.h"
#include "I2c.h"

Adafruit_SSD1306 OLED::display(SCREEN_WIDTH, SCREEN_HEIGHT, &I2c::getWire(), OLED_RESET);
bool OLED::initialized = false;

bool OLED::init() {
    if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDRESS)) {
        Serial.println("Failed to initialize OLED");
        return false;
    }
    initialized = true;
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Eidolon");
    display.display();
    return true;
}

void OLED::clear() {
    if (!initialized) {
        return;
    }
    display.clearDisplay();
}

void OLED::update() {
    if (!initialized) {
        return;
    }
    display.display();
}

void OLED::drawPixel(int16_t x, int16_t y, uint16_t color) {
    if (!initialized) {
        return;
    }
    display.drawPixel(x, y, color);
}

void OLED::drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color) {
    if (!initialized) {
        return;
    }
    display.drawLine(x0, y0, x1, y1, color);
}

void OLED::drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
    if (!initialized) {
        return;
    }
    display.drawRect(x, y, w, h, color);
}

void OLED::fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color) {
    if (!initialized) {
        return;
    }
    display.fillRect(x, y, w, h, color);
}

void OLED::drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color) {
    if (!initialized) {
        return;
    }
    display.drawCircle(x0, y0, r, color);
}

void OLED::fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color) {
    if (!initialized) {
        return;
    }
    display.fillCircle(x0, y0, r, color);
}

void OLED::setTextSize(uint8_t size) {
    if (!initialized) {
        return;
    }
    display.setTextSize(size);
}

void OLED::setTextColor(uint16_t color) {
    if (!initialized) {
        return;
    }
    display.setTextColor(color);
}

void OLED::setCursor(int16_t x, int16_t y) {
    if (!initialized) {
        return;
    }
    display.setCursor(x, y);
}

void OLED::print(const char* text) {
    if (!initialized) {
        return;
    }
    display.print(text);
}

void OLED::println(const char* text) {
    if (!initialized) {
        return;
    }
    display.println(text);
}

Adafruit_SSD1306& OLED::getDisplay() {
    return display;
}

bool OLED::isInitialized() {
    return initialized;
}

