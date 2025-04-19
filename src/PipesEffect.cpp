#include "PipesEffect.h"

float h = 0;
int steps = 0;

PipesEffect::PipesEffect(const LibGuitarMap& guitarMap) {
    this->guitarMap = guitarMap;
    randomizeNextPoint();
}

PipesEffect::~PipesEffect() {
}

void PipesEffect::draw() {
    h += 0.4;
    steps++;

    if (steps > WIDTH * HEIGHT) {
        steps = 0;
        guitarMap.setHSVColor(0, 0, 0);
        guitarMap.fill(true);
    }

    guitarMap.setHSVColor(h, 255, 255);

    if (currentX != targetX) {
        if (dirX > 0) {
            right();
        } else {
            left();
        }
    } else if (currentY != targetY) {
        if (dirY > 0) {
            up();
        } else {
            down();
        }
    } else {
        randomizeNextPoint();
    }

    guitarMap.point(currentX, currentY, true);
    delay(20);
}

void PipesEffect::down() {
    currentY++;

    if (currentY >= HEIGHT) {
        currentY = 0;
    }
}

void PipesEffect::up() {
    currentY--;

    if (currentY < 0) {
        currentY = HEIGHT - 1;
    }
}

void PipesEffect::left() {
    currentX--;

    if (currentX < 0) {
        currentX = WIDTH - 1;
    }
}

void PipesEffect::right() {
    currentX++;

    if (currentX >= WIDTH - 1) {
        currentX = 0;
    }
}

void PipesEffect::randomizeNextPoint() {
    targetX = random(0, WIDTH);
    targetY = random(0, HEIGHT);

    dirX = random(-1, 1);
    dirY = random(-1, 1);
}