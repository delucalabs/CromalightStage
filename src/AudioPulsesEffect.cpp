#include "AudioPulsesEffect.h"

AudioPulsesEffect::AudioPulsesEffect(const LibGuitarMap& guitarMap) {
    this->guitarMap = guitarMap;
}

void AudioPulsesEffect::draw() {
    for (int i = 0; i < WIDTH; i++) {
        lines[i] = random(0, 2*HEIGHT/3);
    }
    guitarMap.setRGBColor(255, 255, 255);
    guitarMap.fill(false);
    for (int i = 0; i < WIDTH; i++) {
        int line_heigth = lines[i];
        guitarMap.setHSVColor(random(0, 255), 255, 255);
        for(int j=0; j<line_heigth; j++){
            guitarMap.point(i, HEIGHT-j-1, false);
        }
    }
    guitarMap.update();


    delay(50);
    guitarMap.update();
}

AudioPulsesEffect::~AudioPulsesEffect() {
}
