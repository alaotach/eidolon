#include <WebServer.h>
#include <ArduinoJson.h>
#include "Config.h"

class WebM {
    public:
        static bool init();
        static void handle();
        static void stop();
    private:
        static WebServer* server;
        static bool initialized;
        static void handleRoot();
        static void handleFiles();
        static void handleOled();
        static void handleDelete();
        static void handleUpload();
        static void sendJSON(const DynamicJsonDocument& doc);
        static void sendErr(const String& err);
};