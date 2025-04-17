#include "LibGuitarMap.h"

class WaveEffect {
   private:
    /* data */
    LibGuitarMap* guitarMap;
    int points[HEIGHT][WIDTH];

   public:
    WaveEffect(LibGuitarMap* guitarMap);
    void draw();
    ~WaveEffect();
};