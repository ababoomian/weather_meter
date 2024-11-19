// WiFiManager.h
#ifndef WIFI_MANAGER_H
#define WIFI_MANAGER_H

#include <WiFi.h>
#include "DisplayManager.h"

class WiFiManager {
  public:
    WiFiManager(const char* ssid, const char* password, DisplayManager* display);
    void connect();
    void reconnect();
    bool isConnected();
    String getIPAddress();

  private:
    const char* ssid;
    const char* password;
    DisplayManager* display;
};

#endif
