#ifndef LIBGUITARMAP_H
#define LIBGUITARMAP_H
#define FASTLED_INTERNAL
#define WIDTH 43
#define HEIGHT 34

#define adagfxswap(a, b) \
    {                    \
        a = a ^ b;       \
        b = a ^ b;       \
        a = a ^ b;       \
    }

#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

#include "FastLED.h"

#define NUM_LEDS_B 489  // 22 Led in più di buffer
#define NUM_LEDS_T 378  // 22 Led in più di buffer

class LibGuitarMap {
   private:
    int pin_t;
    int pin_b;
    int power;

    int r = 0;  // RED
    int g = 0;  // GREEN
    int b = 0;  // BLUE

    int h = 0;  // Hue
    int s = 0;  // Saturation
    int v = 0;  // Value

    int colorType = 0;

    int fadeAmount;
    int brightness;

    int ledBufferB = 1;
    int ledBufferT = 1;

      public:
    LibGuitarMap();

    // ~LibGuitarMap();

    void point(int x, int y, bool update);
    void init(int power);
    void update();
    void fill(bool update);
    void setRGBColor(int r_new, int g_new, int b_new);
    void setHSVColor(int h_new, int s_new, int v_new);

    void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1);
};
#endif