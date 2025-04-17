#include <Arduino.h>

#include "WiFi.h"  // ESP32
//#include "ESP8266WiFi.h" // ESP8266
#include <esp_now.h>
#include <FastLED.h>

#define NUM_LEDS 22
CRGB leds[NUM_LEDS];

// ESP8266 40:91:51:50:A1:BA
// ESP32   78:21:84:92:07:F4

uint8_t broadcastAddress[] = {0x34, 0x94, 0x54, 0x25, 0x97, 0xB0};

// Structure example to send data
// Must match the receiver structure
typedef struct packet {
  uint8_t x;
  uint8_t y;
  uint8_t r;
  uint8_t g;
  uint8_t b;
} packet;

// Create a packet called myData
packet pixelData;

esp_now_peer_info_t peerInfo;

// callback when data is sent
void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {

}

void setup() {
  // Init Serial Monitor
  Serial.begin(9600);
  FastLED.addLeds<NEOPIXEL, 23>(leds, NUM_LEDS);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Once ESPNow is successfully Init, we will register for Send CB to
  // get the status of Trasnmitted packet
  esp_now_register_send_cb(OnDataSent);

  // Register peer
  memcpy(peerInfo.peer_addr, broadcastAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  // Add peer
  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }
}

void loop() {
  uint8_t pixel[5];



  if (Serial.available() >= 5) {
    Serial.readBytes(pixel, 5);
    pixelData.x = pixel[0];
    pixelData.y = pixel[1];
    pixelData.r = pixel[2];
    pixelData.g = pixel[3];
    pixelData.b = pixel[4];


    int x = pixelData.x;
    int y = pixelData.y;
    int r = pixelData.r;
    int g = pixelData.g;
    int b = pixelData.b;
    
    Serial.println(r);
    Serial.println(g);
    Serial.println(b);
    Serial.println(x);
    Serial.println(y);

    leds[0] = CRGB(r, g, b);
    FastLED.show();
    delay(100);
    leds[0] = CRGB(0, 0, 0);
    FastLED.show();

    // Send message via ESP-NOW
    esp_err_t result = esp_now_send(broadcastAddress, (uint8_t *)&pixelData, sizeof(pixelData));
  }
}
