#include <Arduino.h>
#include <FS.h>
#include <LittleFS.h>

class LittleFSM {
public:
    static bool init();
    static bool exists(const char* path);
    static bool deleteFile(const char* path);
    static uint32_t getFreeBytes();
    static uint32_t getTotalBytes();
    static uint32_t getUsedBytes();
    static void createDir();
    static File open(const char* path, const char* mode);
    static void list(const char* path);
    static bool format();
    static bool rename(const char* pathFrom, const char* pathTo);
    static bool mkdir(const char* path);

private:
    static bool initialized;
};