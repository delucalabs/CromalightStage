#include "AudioPulsesEffect.h"

AudioPulsesEffect::AudioPulsesEffect(const LibGuitarMap& guitarMap) {
    this->guitarMap = guitarMap;
}

void AudioPulsesEffect::draw() {
    for (int i = 0; i < WIDTH; i++) {
        lines[i] = random(0, HEIGHT/2);
    }
    for (int i = 0; i < WIDTH; i++) {
        int line_heigth = lines[i];
        for(int j=0; j<line_heigth; j++){
            guitarMap.setHSVColor(random(0, 255), 255, 255);
            guitarMap.point(i, HEIGHT-j, false);
        }
    }
    guitarMap.update();


    delay(50);
    guitarMap.update();
}

AudioPulsesEffect::~AudioPulsesEffect() {
}
