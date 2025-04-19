#include "LibGuitarMap.h"

class BlueMatrixEffect {
   private:
    int points[HEIGHT];
    int points_black[HEIGHT];
    LibGuitarMap guitarMap;

   public:
    BlueMatrixEffect(const LibGuitarMap& guitarMap);
    void draw();
    ~BlueMatrixEffect();
};