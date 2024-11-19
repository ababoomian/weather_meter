#include "WiFiManager.h"
#include "DisplayManager.h"

const char* ssid = "tumoTeam";
const char* password = "hello2team";

DisplayManager displayManager(128, 64); // Example for a 128x64 display
WiFiManager wifiManager(ssid, password, &displayManager);

void setup() {
  displayManager.begin();
  wifiManager.connect();
}

void loop() {
  if(!wifiManager.isConnected())
    wifiManager.reconnect();
    delay(10000);
}