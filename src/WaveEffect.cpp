#include "WaveEffect.h"

WaveEffect::WaveEffect(LibGuitarMap* guitarMap) {
    this->guitarMap = guitarMap;
    int h = 240;

    for (int y = 0; y < HEIGHT; y++) {
        h = random(240, 270);

        for (int x = 0; x < WIDTH; x++) {
            points[y][x] = h + random(-2, 2);
        }
    }
}

void WaveEffect::draw() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            points[y][x]++;

            if (points[y][x] > 270) {
                points[y][x] = 240;
            }

            guitarMap->setHSVColor(points[y][x], 255, 255);
            guitarMap->point(x, y, false);
        }
    }

    delay(50);
    guitarMap->update();
}