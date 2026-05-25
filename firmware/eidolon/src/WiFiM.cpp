#include "WiFiM.h"
#include "Config.h"`

IPAddress WiFiM::IP = IPAddress(0, 0, 0, 0);
bool WiFiM::connected = false;

bool WiFiM::init() {
    WiFi.mode(WIFI_STA);
    bool conn = WiFi.softAP(SSID, PASSWORD, CHANNEL, MAX_CONNECTIONS, true);
    if (conn) {
        IP = WiFi.softAPIP();
        connected = true;
    }
    return conn;
}
IPAddress WiFiM::getIP() {
    return IP;
}
void WiFiM::stop() {
    WiFi.softAPdisconnect(true);
    connected = false;
}


void WiFiM::restart() {
    stop();
    init();
}

bool WiFiM::isConnected() {
    return connected;
}