#ifndef LIBGUITARMAP_H
#define LIBGUITARMAP_H
#define FASTLED_INTERNAL
#define WIDTH 43
#define HEIGHT 34
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

  //int matrixB;
  //int matrixT;
  //int colorType;
  int r;  // RED
  int g;  // GREEN
  int b;  // BLUE

  int h;  // Hue
  int s;  // Saturation
  int v;  // Value
  //int ledBufferB;
  //int ledBufferT;

  //int fadeAmount;
  //int brightness;

 public:
  LibGuitarMap();

  void point(int x, int y, bool update);

	void init(int power);
	void update();
	void fill(bool update);
	void setRGBColor(int r_new, int g_new, int b_new);
	void setHSVColor(int h_new, int s_new, int v_new);

	void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1);
};
#endif