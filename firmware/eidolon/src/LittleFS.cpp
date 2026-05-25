#include "LittleFSM.h"

bool LittleFSM::initialized = false;

#define FORMAT_LITTLEFS_IF_FAILED true

bool LittleFSM::init() {
    if (!LittleFS.begin(FORMAT_LITTLEFS_IF_FAILED)) {
        Serial.println("Failed to initialize LittleFS");
        return false;
    }
    initialized = true;
    createDir();
    return true;
}

bool LittleFSM::exists(const char* path) {
    return LittleFS.exists(path);
}

bool LittleFSM::deleteFile(const char* path) {
    if (!exists(path)) {
        return false;
    }
    return LittleFS.remove(path);
}

bool LittleFSM::format() {
    return LittleFS.format();
}

uint32_t LittleFSM::getFreeBytes() {
    return LittleFS.totalBytes() - LittleFS.usedBytes();
}

uint32_t LittleFSM::getTotalBytes() {
    return LittleFS.totalBytes();
}

uint32_t LittleFSM::getUsedBytes() {
    return LittleFS.usedBytes();
}

void LittleFSM::createDir() {
    if (!LittleFS.exists("/uploads")) {
        LittleFS.mkdir("/uploads");
    }
}

File LittleFSM::open(const char* path, const char* mode) {
    return LittleFS.open(path, mode);
}   

void LittleFSM::list(const char* path) {
    File root = LittleFS.open(path);
    if (!root) {
        return;
    }
    if (!root.isDirectory()) {
        return;
    }
    File file = root.openNextFile();
    while (file) {
        Serial.print("FILE: ");
        Serial.print(file.name());
        Serial.print("\tSIZE: ");
        Serial.println(file.size());
        file = root.openNextFile();
    }
    root.close();
}

bool LittleFSM::rename(const char* pathFrom, const char* pathTo) {
    return LittleFS.rename(pathFrom, pathTo);
}

bool LittleFSM::mkdir(const char* path) {
    return LittleFS.mkdir(path);
}