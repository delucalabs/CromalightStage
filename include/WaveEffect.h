#include "LibGuitarMap.h"

#define WAVE_MIN_HUE 155
#define WAVE_MAX_HUE 165

class WaveEffect {
   private:
    int points[HEIGHT][WIDTH];
    LibGuitarMap guitarMap;

   public:
    WaveEffect(const LibGuitarMap& guitarMap);
    void draw();
    ~WaveEffect();
};