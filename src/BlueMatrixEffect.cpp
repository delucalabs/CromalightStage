#include "BlueMatrixEffect.h"

BlueMatrixEffect::BlueMatrixEffect(const LibGuitarMap& guitarMap) {
    this->guitarMap = guitarMap;

    for (int i = 0; i < HEIGHT; i++) {
        points[i] = random(HEIGHT, HEIGHT + 5);
        points_black[i] = random(HEIGHT + 5, HEIGHT + 15);
    }
}

void BlueMatrixEffect::draw() {
    for (int i = 0; i < HEIGHT; i++) {
        int blue = random(50, 255);

        guitarMap.setRGBColor(0, 0, blue);
        guitarMap.point(points[i], i, false);

        guitarMap.setRGBColor(0, 0, 0);
        guitarMap.point(points_black[i], i, false);

        points[i]--;
        points_black[i]--;

        if (points_black[i] < 0) {
            points[i] = random(HEIGHT, HEIGHT + 5);
            points_black[i] = random(HEIGHT + 5, HEIGHT + 15);
        }
    }

    delay(50);
    guitarMap.update();
}

BlueMatrixEffect::~BlueMatrixEffect() {
}
