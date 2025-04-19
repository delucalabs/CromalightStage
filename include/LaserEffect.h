#include "LibGuitarMap.h"

class LaserEffect {
   private:
    LibGuitarMap guitarMap;

   public:
    LaserEffect(const LibGuitarMap& guitarMap);
    void draw();
    ~LaserEffect();
};