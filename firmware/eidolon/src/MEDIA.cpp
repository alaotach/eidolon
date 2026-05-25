#include "MEDIA.h"
#include "LittleFSM.h"

Media currentMedia = { "", "", MEDIA_NONE, 0, 0 };
uint32_t MediaManager::mediaCount = 0;
int MediaManager::currentIndex = -1;

void MediaManager::init() {
    scanMedia();
}

MediaType MediaManager::getMediaType(const char* path) {
    String filePath(path);
    if (filePath.endsWith(".jpg") || filePath.endsWith(".jpeg") || filePath.endsWith(".png") || filePath.endsWith(".bmp")) {
        return MEDIA_IMAGE;
    } else if (filePath.endsWith(".mp4") || filePath.endsWith(".avi") || filePath.endsWith(".mov") || filePath.endsWith(".gif")) {
        return MEDIA_VIDEO;
    }
    return MEDIA_NONE;
}

bool MediaManager::loadNextMedia() {
    File root = LittleFSM::open("/uploads", "r");
    if (!root) {
        return false;
    }
    bool found = (currentMedia.name == "") ? true : false;
    File f = root.openNextFile();
    while (f) {
        String name = String(f.name());
        if (name.startsWith("/uploads/")) {
            name = name.substring(9);
        }
        MediaType type = getMediaType(name.c_str());
        if (type != MEDIA_NONE) {
            if (found) {
                currentMedia.name = name;
                currentMedia.type = type;
                currentMedia.path = "/uploads/" + name;
                root.close();
                return true;
            }
            if (name == currentMedia.name) {
                found = true;
            }
        }
        f = root.openNextFile();
    }
    root.close();
    currentMedia.name = "";
    currentMedia.type = MEDIA_NONE;
    currentMedia.path = "";
    return loadNextMedia();
}
bool MediaManager::loadPreviousMedia() {
    File root = LittleFSM::open("/uploads", "r");
    if (!root) {
        return false;
    }
    Media prev = {"", "", MEDIA_NONE, 0, 0};
    bool found = (currentMedia.name == "") ? true : false;
    File f = root.openNextFile();
    while (f) {
        String name = String(f.name());
        if (name.startsWith("/uploads/")) {
            name = name.substring(9);
        }
        MediaType type = getMediaType(name.c_str());
        if (type != MEDIA_NONE) {
            if (found) {
                if (prev.name==""){
                    break;
                }
                currentMedia = prev;
                root.close();
                return true;
            }
            prev.name = name;
            prev.type = type;
            prev.path = String(f.path());
            if (name == currentMedia.name) {
                found = true;
            }
        }
        f = root.openNextFile();
    }
    root.close();
    currentMedia.name = "";
    currentMedia.type = MEDIA_NONE;
    currentMedia.path = "";
    return loadNextMedia();
}

bool MediaManager::loadMedia(const char* path) {
    if (!LittleFSM::exists(path)) {
        return false;
    }
    currentMedia.path = path;
    return true;
}

Media* MediaManager::getCurrentMedia() {
    return &currentMedia;
}

uint32_t MediaManager::getMediaCount() {
    return mediaCount;
}

void MediaManager::scanMedia() {
    mediaCount = 0;
    File root = LittleFSM::open("/uploads", "r");
    if (!root) {
        return;
    }
    File f = root.openNextFile();
    while (f) {
        if (!f.isDirectory()) {
            mediaCount++;
        }
        f = root.openNextFile();
    }
    root.close();
}