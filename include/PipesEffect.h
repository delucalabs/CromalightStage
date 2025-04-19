#include "LibGuitarMap.h"

#define PIPES_DELAY 20

class PipesEffect {
   private:
    void randomizeNextPoint();
    void left();
    void right();
    void up();
    void down();

    int targetX = 0;
    int targetY = 0;

    int currentX = 0;
    int currentY = 0;

    int dirX = 0;
    int dirY = 0;
    LibGuitarMap guitarMap;

   public:
    PipesEffect(const LibGuitarMap& guitarMap);
    void draw();
    ~PipesEffect();
};