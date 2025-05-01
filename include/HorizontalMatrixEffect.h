#include "LibGuitarMap.h"

class HorizontalMatrixEffect {
   private:
    int points[HEIGHT];
    int points_black[HEIGHT];
    LibGuitarMap guitarMap;

   public:
    HorizontalMatrixEffect(const LibGuitarMap& guitarMap);
    void draw();
    ~HorizontalMatrixEffect();
};