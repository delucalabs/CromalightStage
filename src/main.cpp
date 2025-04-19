#include <WiFi.h>
#include <Wire.h>
#include <esp_now.h>
#include <esp_wifi.h>

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

PipesEffect pipesEffect(guitarMap);
BlueMatrixEffect blueMatrixEffect(guitarMap);
WaveEffect waveEffect(guitarMap);

void OnDataRecv(const uint8_t *mac, const uint8_t *incomingData, int len) {
    memcpy(&packetData, incomingData, sizeof(packetData));

    uint8_t effectNumber = packetData.effectNumber;

    Serial.printf("Switching effect to: %d\n", effectNumber);
}

void setup() {
    Serial.begin(115200);
    guitarMap.init(500);
    WiFi.mode(WIFI_STA);

    // Init ESP-NOW
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

    randomSeed(esp_random());

    esp_now_register_recv_cb(OnDataRecv);
    guitarMap.setRGBColor(255, 0, 0);
}

void loop() {
    switch (packetData.effectNumber) {
        case 0:
            pipesEffect.draw();
            break;
        case 1:
            pipesEffect.draw();
            break;
        case 2:
            blueMatrixEffect.draw();
            break;
        case 3:
            waveEffect.draw();
            break;

        default:
            break;
    }
}
