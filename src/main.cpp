#include <WiFi.h>
#include <Wire.h>
#include <esp_now.h>
#include <esp_wifi.h>

#include "BlueMatrixEffect.h"
#include "HorizontalMatrixEffect.h"
#include "LaserEffect.h"
#include "LibGuitarMap.h"
#include "LineEffect.h"
#include "PipesEffect.h"
#include "WaveEffect.h"

// Loop degli effetti ogni 20 secondi
// #define DEMO_LOOP_MODE
// Abilita il comando remoto con ESP-NOW
#define CROMALIGHT_COMMANDER_ENABLED

// 22 Led in più di buffer
#define NUM_LEDS_B 489
// 22 Led in più di buffer
#define NUM_LEDS_T 378

LibGuitarMap guitarMap;

LaserEffect laserEffect(guitarMap);
PipesEffect pipesEffect(guitarMap);
BlueMatrixEffect blueMatrixEffect(guitarMap);
WaveEffect waveEffect(guitarMap);
LineEffect lineEffect(guitarMap);
HorizontalMatrixEffect horizontalMatrix(guitarMap);

uint64_t lastDemoMillis = 0;
uint8_t effectNumber = 0;

#ifdef CROMALIGHT_COMMANDER_ENABLED

typedef struct packet {
    uint8_t effectNumber;
} packet;

packet packetData;

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
    memcpy(&packetData, incomingData, sizeof(packetData));

    effectNumber = packetData.effectNumber;

    Serial.printf("Switching effect to: %d\n", effectNumber);

    guitarMap.setRGBColor(0, 0, 0);
    guitarMap.fill(true);
}

#endif

void setup() {
    Serial.begin(115200);
    guitarMap.init(500);

#ifdef CROMALIGHT_COMMANDER_ENABLED
    WiFi.mode(WIFI_STA);

    if (esp_now_init() != 0) {
        Serial.println("Error initializing ESP-NOW");
        return;
    }
    uint8_t baseMac[6];
    esp_err_t ret = esp_wifi_get_mac(WIFI_IF_STA, baseMac);
    if (ret == ESP_OK) {
        Serial.printf("%02x:%02x:%02x:%02x:%02x:%02x\n",
                      baseMac[0], baseMac[1], baseMac[2],
                      baseMac[3], baseMac[4], baseMac[5]);
    }

    esp_now_register_recv_cb(OnDataRecv);
#endif

    randomSeed(esp_random());
    guitarMap.setRGBColor(255, 0, 0);
}

void loop() {
#ifdef DEMO_LOOP_MODE
    if (millis() - lastDemoMillis > 20000) {
        lastDemoMillis = millis();
        effectNumber++;
        effectNumber = effectNumber % 5;
        guitarMap.setRGBColor(0, 0, 0);
        guitarMap.fill(true);
    }
#endif

    switch (effectNumber) {
        case 0:
            lineEffect.draw();
            break;
        case 1:
            // Black
            guitarMap.setRGBColor(0, 0, 0);
            guitarMap.fill(true);
            break;
        case 2:
            pipesEffect.draw();
            break;
        case 3:
            // Black
            guitarMap.setRGBColor(0, 0, 0);
            guitarMap.fill(true);
            break;
        case 4:
            blueMatrixEffect.draw();
            break;
        case 5:
            // Black
            guitarMap.setRGBColor(0, 0, 0);
            guitarMap.fill(true);
            break;
        case 6:
            waveEffect.draw();
            break;
        case 7:
            // Black
            guitarMap.setRGBColor(0, 0, 0);
            guitarMap.fill(true);
            break;
        case 8:
            laserEffect.draw();
            break;
        case 9:
            // Black
            guitarMap.setRGBColor(0, 0, 0);
            guitarMap.fill(true);
            break;
        case 10:
            horizontalMatrix.draw();
            break;
        case 11:
            // Black
            guitarMap.setRGBColor(0, 0, 0);
            guitarMap.fill(true);
            break;

        default:
            break;
    }
}
