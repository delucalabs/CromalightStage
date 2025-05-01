#include "LibGuitarMap.h"

class AudioPulsesEffect {
   private:
    int lines[WIDTH];
    LibGuitarMap guitarMap;

   public:
    AudioPulsesEffect(const LibGuitarMap& guitarMap);
    void draw();
    ~AudioPulsesEffect();
};