#include <WiFi.h>
#include "Config.h"

class WiFiM {
public:
    static bool init();
    static IPAddress getIP();
    static void stop();
    static void restart();
    static bool isConnected();

private:
    static IPAddress IP;
    static bool connected;
}