#include <Arduino.h>
#include "Config.h"

enum MediaType {
    MEDIA_NONE,
    MEDIA_IMAGE,
    MEDIA_VIDEO,
};

struct Media {
    String name;
    String path;
    MediaType type;
    uint32_t size;
    uint32_t timestamp;
};

class MediaManager {
public:
    static void init();
    static MediaType getMediaType(const char* path);
    static bool loadNextMedia();
    static bool loadPreviousMedia();
    static bool loadMedia(const char* path);
    static Media* getCurrentMedia();
    static uint32_t getMediaCount();
private:
    static uint32_t mediaCount;
    static int currentIndex;
    static void scanMedia();
};

