#include <vector>

#include "LibGuitarMap.h"

#define PIPES_DELAY 20

class PipesEffect {
   private:
    void drawScene();
    void autoMove(int x, int y);
    int shortestY(int startY, int endY);
    int shortestX(int startX, int endX);
    void left();
    void right();
    void up();
    void down();
    void randomizeNextPoint();
    void setLastPos();

    int rX = 0;
    int rY = 0;
    int targetX = 0;
    int targetY = 0;
    float hue = 0;

    std::vector<int> lastPosX;
    std::vector<int> lastPosY;
    std::vector<float> lastPosH;

    LibGuitarMap* guitarMap;

   public:
    PipesEffect(LibGuitarMap* guitarMap);
    void draw();
    ~PipesEffect();
};