#include "LaserEffect.h"

int x = 0;
int y = 0;

int stepX = 0;
int stepY = 0;
int amt = 0;
int state = 0;

LaserEffect::LaserEffect(const LibGuitarMap& guitarMap) {
    this->guitarMap = guitarMap;
}

void LaserEffect::draw() {
    // guitarMap.setRGBColor(0, 0, 0);
    // guitarMap.fill(false);

    stepX = 1;
    stepY = 1;
    amt += 1;

    if (amt > 255) {
        amt = 0;
    }

    if (state == 0) {
        x += stepX;
        y += stepY;

        guitarMap.setHSVColor(amt, 255, 255);
        guitarMap.drawLine(0, y, x, HEIGHT, false);

    } else if (state == 1) {
        x -= stepX;
        y -= stepY;

        guitarMap.setHSVColor(amt, 255, 255);
        guitarMap.drawLine(WIDTH, y, WIDTH - x, HEIGHT, false);

    } else if (state == 2) {
        x += stepX;
        y += stepY;

        guitarMap.setHSVColor(amt, 255, 255);
        guitarMap.drawLine(WIDTH - x, 0, WIDTH, HEIGHT - y, false);

    } else if (state == 3) {
        x -= stepX;
        y -= stepY;

        guitarMap.setHSVColor(amt, 255, 255);
        guitarMap.drawLine(x, 0, 0, HEIGHT - y, false);
    }

    if (y > HEIGHT && state == 0) {
        x = WIDTH;
        y = HEIGHT;
        state = 1;
    } else if (y < 0 && state == 1) {
        x = 0;
        y = 0;
        state = 2;
    } else if (x > WIDTH && state == 2) {
        x = WIDTH;
        y = HEIGHT;
        state = 3;
    } else if (x < 0 && y < 0) {
        x = 0;
        y = 0;
        state = 0;
    }

    guitarMap.update();
}

LaserEffect::~LaserEffect() {}