// DisplayManager.h
#ifndef DISPLAY_MANAGER_H
#define DISPLAY_MANAGER_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class DisplayManager {
  public:
    DisplayManager(int screenWidth, int screenHeight);
    void begin();
    void showText(String text, int x, int y);
    void clear();

  private:
    Adafruit_SSD1306 display;
};

#endif
