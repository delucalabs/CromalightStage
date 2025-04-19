#include "WaveEffect.h"

WaveEffect::WaveEffect(const LibGuitarMap& guitarMap) {
    this->guitarMap = guitarMap;

    int h = WAVE_MIN_HUE;

    for (int y = 0; y < HEIGHT; y++) {
        h = random(WAVE_MIN_HUE, WAVE_MAX_HUE);

        for (int x = 0; x < WIDTH; x++) {
            points[y][x] = h + random(-2, 2);
        }
    }
}

void WaveEffect::draw() {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            points[y][x]++;

            if (points[y][x] > WAVE_MAX_HUE) {
                points[y][x] = WAVE_MIN_HUE;
            }

            guitarMap.setHSVColor(points[y][x], 255, 255);
            guitarMap.point(x, y, false);
        }
    }

    delay(50);
    guitarMap.update();
}

WaveEffect::~WaveEffect() {
}