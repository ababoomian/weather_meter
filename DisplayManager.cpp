// DisplayManager.cpp
#include "DisplayManager.h"

DisplayManager::DisplayManager(int screenWidth, int screenHeight)
  : display(screenWidth, screenHeight, &Wire, -1) {}

void DisplayManager::begin() {
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for(;;); // Don't proceed, loop forever
  }
  display.clearDisplay();
}

void DisplayManager::showText(String text, int x, int y) {
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(x, y);
  display.println(text);
  display.display();
}

void DisplayManager::clear() {
  display.clearDisplay();
  display.display();
}
