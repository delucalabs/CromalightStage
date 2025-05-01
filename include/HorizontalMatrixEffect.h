#include "LibGuitarMap.h"

class HorizontalMatrixEffect {
   private:
    int points[WIDTH];
    int points_black[WIDTH];
    LibGuitarMap guitarMap;

   public:
    HorizontalMatrixEffect(const LibGuitarMap& guitarMap);
    void draw();
    ~HorizontalMatrixEffect();
};