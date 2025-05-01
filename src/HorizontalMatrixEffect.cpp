#include "HorizontalMatrixEffect.h"

HorizontalMatrixEffect::HorizontalMatrixEffect(const LibGuitarMap& guitarMap) {
    this->guitarMap = guitarMap;

    for (int i = 0; i < WIDTH; i++) {
        points[i] = random(0, 5);
        points_black[i] = random(5, 5);
    }
}

void HorizontalMatrixEffect::draw() {
    for (int i = WIDTH-1; i >= 0; i--) {
        int blue = random(50, 255);

        guitarMap.setRGBColor(0, 0, blue);
        guitarMap.point(i, points[i], false);

        guitarMap.setRGBColor(0, 0, 0);
        guitarMap.point(i, points_black[i], false);

        points[i]++;
        points_black[i]++;

        if (points_black[i] > HEIGHT) {
            points[i] = random(0, 5);
            points_black[i] = random(5, 5);
        }
    }

    delay(50);
    guitarMap.update();
}

HorizontalMatrixEffect::~HorizontalMatrixEffect() {
}
