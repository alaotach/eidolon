#include <Arduino.h>
#include "Config.h"
#include "MEDIA.h"

class ImageR {
public:
    static bool renderBMP(const String& path);
    static bool renderRaw(const String& path, const uint16_t height, const uint16_t width);
    static void clear();
private:
    static bool isBMP(File& f);
    static bool renderBMPMono(File& f);
}