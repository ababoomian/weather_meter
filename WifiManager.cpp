// WiFiManager.cpp
#include "WiFiManager.h"

WiFiManager::WiFiManager(const char* ssid, const char* password, DisplayManager* display) {
  this->ssid = ssid;
  this->password = password;
  this->display = display;
}

void WiFiManager::connect() {
    WiFi.begin(ssid, password);
  display->clear();
  display->showText("Connecting to WiFi...", 0, 0);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
  display->clear();
  display->showText("Connected", 0, 1);
  display->showText("IP: " + getIPAddress(), 0, 20);
}

bool WiFiManager::isConnected() {
  return WiFi.status() == WL_CONNECTED;
}

void WiFiManager::reconnect() {
  WiFi.begin(ssid, password);
  display->clear();
  display->showText("Reconnecting to WiFi...", 0, 0);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }
  display->clear();
  display->showText("Connected", 0, 1);
  display->showText("IP: " + getIPAddress(), 0, 20);
}

String WiFiManager::getIPAddress() {
  return WiFi.localIP().toString();
}
