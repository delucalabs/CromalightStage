
#include "LibGuitarMap.h"

class BlueMatrixEffect {
   private:
    /* data */
    LibGuitarMap* guitarMap;
    int points[HEIGHT];
    int points_black[HEIGHT];

   public:
    BlueMatrixEffect(LibGuitarMap* guitarMap);
    void draw();
    ~BlueMatrixEffect();
};