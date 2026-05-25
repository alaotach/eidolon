#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include "Config.h"

class OLED {
public:
    static bool init();
    static void clear();
    static void update();
    static void drawPixel(int16_t x, int16_t y, uint16_t color);
    static void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
    static void drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
    static void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
    static void drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
    static void fillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color);
    static void setTextSize(uint8_t size);
    static void setTextColor(uint16_t color);
    static void setCursor(int16_t x, int16_t y);
    static void print(const char* text);
    static void println(const char* text);
    static Adafruit_SSD1306& getDisplay();
    static bool isInitialized();
private:
    static Adafruit_SSD1306 display;
    static bool initialized;
};