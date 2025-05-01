#include "HorizontalMatrixEffect.h"

HorizontalMatrixEffect::HorizontalMatrixEffect(const LibGuitarMap& guitarMap) {
    this->guitarMap = guitarMap;

    for (int i = 0; i < WIDTH; i++) {
        points[i] = random(WIDTH, WIDTH + 5);
        points_black[i] = random(WIDTH + 5, WIDTH + 15);
    }
}

void HorizontalMatrixEffect::draw() {
    for (int i = 0; i < WIDTH; i++) {
        int blue = random(50, 255);

        guitarMap.setRGBColor(0, 0, blue);
        guitarMap.point(i, points[i], false);

        guitarMap.setRGBColor(0, 0, 0);
        guitarMap.point(i, points_black[i], false);

        points[i]--;
        points_black[i]--;

        if (points_black[i] < 0) {
            points[i] = random(WIDTH, WIDTH + 5);
            points_black[i] = random(WIDTH + 5, WIDTH + 15);
        }
    }

    delay(50);
    guitarMap.update();
}

HorizontalMatrixEffect::~HorizontalMatrixEffect() {
}
