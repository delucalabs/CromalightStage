#include <WiFi.h>
#include <Wire.h>
#include <esp_now.h>

#include "BlueMatrixEffect.h"
#include "LibGuitarMap.h"
#include "PipesEffect.h"
#include "WaveEffect.h"

#define NUM_LEDS_B 489  // 22 Led in più di buffer
#define NUM_LEDS_T 378  // 22 Led in più di buffer

typedef struct packet {
    uint8_t effectNumber;
} packet;

packet packetData;
LibGuitarMap guitarMap;

PipesEffect pipesEffect(&guitarMap);
BlueMatrixEffect blueMatrixEffect(&guitarMap);
WaveEffect waveEffect(&guitarMap);

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
    memcpy(&packetData, incomingData, sizeof(packetData));

    uint8_t effectNumber = packetData.effectNumber;

    Serial.printf("Switching effect to: %d\n", effectNumber);
    guitarMap.setRGBColor(0, 0, 0);
    guitarMap.fill(true);
}

void setup() {
    Serial.begin(115200);
    guitarMap.init(2000);
    WiFi.mode(WIFI_STA);

    // Init ESP-NOW
    if (esp_now_init() != 0) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }

    esp_now_register_recv_cb(OnDataRecv);
}

void loop() {
 //   switch (packetData.effectNumber) {
 //       case 0:
 //           pipesEffect.draw();
 //           break;
 //       case 1:
 //           blueMatrixEffect.draw();
 //           break;
 //       case 2:
            waveEffect.draw();
//         break;

//        default:
//            break;
//    }
}
