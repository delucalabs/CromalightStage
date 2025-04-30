#include "LibGuitarMap.h"

class LineEffect {
   private:
    LibGuitarMap guitarMap;

   public:
    LineEffect(const LibGuitarMap& guitarMap);
    void draw();
    ~LineEffect();
};