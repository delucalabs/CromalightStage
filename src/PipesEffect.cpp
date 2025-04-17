#include "PipesEffect.h"

#include <vector>

PipesEffect::PipesEffect(LibGuitarMap* guitarMap) {
    this->guitarMap = guitarMap;
}

PipesEffect::~PipesEffect() {
}

void PipesEffect::draw() {
    autoMove(targetX, targetY);
    randomizeNextPoint();
    drawScene();
}

void PipesEffect::autoMove(int x, int y) {
    int stepsX = shortestX(rX, x);
    int stepsY = shortestY(rY, y);

    if (stepsX < 0) {
        for (int i = 0; i > stepsX; i--) {
            left();
            setLastPos();
        }
    } else {
        for (int i = 0; i < stepsX; i++) {
            right();
            setLastPos();
        }
    }

    if (stepsY < 0) {
        for (int i = 0; i > stepsY; i--) {
            up();
            setLastPos();
        }
    } else {
        for (int i = 0; i < stepsY; i++) {
            down();
            setLastPos();
        }
    }
}

int PipesEffect::shortestX(int startX, int endX) {
    int sR = 0;  // Passi necessari per arrivare alla X andando a destra
    int sL = 0;  // Passi necessari per arrivare alla X andando a sinistra

    int tmpXR = startX;  // Posizione temporanea nel calcolo del percorso verso destra

    while (tmpXR != endX) {
        if (tmpXR + 1 < WIDTH) {
            tmpXR++;
        } else {
            tmpXR = 0;
        }
        sR++;
    }

    int tmpXL = startX;  // Posizione temporanea nel calcolo del percorso verso sinistra

    while (tmpXL != endX) {
        if (tmpXL - 1 >= 0) {
            tmpXL--;
        } else {
            tmpXL = WIDTH - 1;
        }
        sL++;
    }

    if (sR <= sL) {
        // Se il percorso verso destra è uguale o più corto di quello a sinistra
        // ritorna il numero di passi verso destra (positivo perché verso destra)
        return sR;
    } else {
        // altrimenti ritorna il numero di passi verso sinistra (negativo perché verso sinistra)
        return -sL;
    }
}

int PipesEffect::shortestY(int startY, int endY) {
    int sU = 0;  // Passi necessari per arrivare alla Y andando verso l'alto
    int sD = 0;  // Passi necessari per arrivare alla Y andando verso il basso

    int tmpYD = startY;  // Posizione temporanea nel calcolo del percorso verso l'alto

    while (tmpYD != endY) {
        if (tmpYD + 1 < HEIGHT) {
            tmpYD++;
        } else {
            tmpYD = 0;
        }
        sD++;
    }

    int tmpYU = startY;  // Posizione temporanea nel calcolo del percorso verso il basso

    while (tmpYU != endY) {
        if (tmpYU - 1 >= 0) {
            tmpYU--;
        } else {
            tmpYU = HEIGHT - 1;
        }
        sU++;
    }

    if (sD <= sU) {
        return sD;
    } else {
        return -sU;
    }
}

void PipesEffect::left() {
    rX--;

    if (rX < 0) {
        rX = WIDTH - 1;
    }

    delay(PIPES_DELAY);
    drawScene();
}

void PipesEffect::right() {
    rX++;

    if (rX >= WIDTH - 1) {
        rX = 0;
    }

    delay(PIPES_DELAY);
    drawScene();
}

void PipesEffect::up() {
    rY--;

    if (rY < 0) {
        rY = HEIGHT - 1;
    }

    delay(PIPES_DELAY);
    drawScene();
}

void PipesEffect::down() {
    rY++;

    if (rY >= HEIGHT) {
        rY = 0;
    }

    delay(PIPES_DELAY);
    drawScene();
}

void PipesEffect::randomizeNextPoint() {
    targetX = random(0, WIDTH - 1);
    targetY = random(0, HEIGHT - 1);
}

void PipesEffect::drawScene() {
    guitarMap->setHSVColor(0, 0, 0);
    guitarMap->fill(false);

    for (int i = 0; i < lastPosX.size(); i++) {
        guitarMap->setHSVColor(lastPosH.at(i), 255, 100);
        guitarMap->point(lastPosX.at(i), lastPosY.at(i), false);
    }

    if (lastPosX.size() > WIDTH * HEIGHT) {
        lastPosX.clear();
        lastPosY.clear();
    }

    guitarMap->update();
}

void PipesEffect::setLastPos() {
    hue += 0.2;

    if (hue > 360) {
        hue = 0;
    }
    lastPosX.push_back(rX);
    lastPosY.push_back(rY);
    lastPosH.push_back(hue);
}