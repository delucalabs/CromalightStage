#include "LineEffect.h"

int fromX = 0;
int toX = 0;

LineEffect::LineEffect(const LibGuitarMap& guitarMap) {
    this->guitarMap = guitarMap;
}

void LineEffect::draw() {
    guitarMap.setRGBColor(0, 0, 0);
    guitarMap.fill(false);
    guitarMap.setRGBColor(100, 100, 255);

    fromX = random(0, WIDTH);
    toX = random(0, WIDTH);
    guitarMap.drawLine(fromX, 0, toX, HEIGHT, true);
    delay(50);

    fromX = random(0, WIDTH);
    toX = random(0, WIDTH);
    guitarMap.drawLine(fromX, 0, toX, HEIGHT, true);
    delay(50);

    fromX = random(0, WIDTH);
    toX = random(0, WIDTH);
    guitarMap.drawLine(fromX, 0, toX, HEIGHT, true);
    delay(50);
}

LineEffect::~LineEffect() {}