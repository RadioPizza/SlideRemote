// SlideRemote v1.0.1
// RX - Приёмник

// Подключение библиотек
#include <ESP8266WiFi.h>
#include <espnow.h>

// Настройка пинов подключения
#define PREV_PIN D4
#define NEXT_PIN D3

// Структура, принимаемая от передатчика
struct StructMessage {
  bool buttonNext;
  bool buttonPrev;
};

StructMessage myData;

void setupPins() {
  pinMode(NEXT_PIN, OUTPUT);
  pinMode(PREV_PIN, OUTPUT);
  digitalWrite(NEXT_PIN, LOW);
  digitalWrite(PREV_PIN, LOW);
}

void setupWiFi() {
  WiFi.mode(WIFI_STA); 
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataRecv);
  Serial.println("ESP-NOW receiver initialized");
}

void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  StructMessage *msg = (StructMessage *)incomingData;
  if (len == sizeof(StructMessage)) {
    if (msg->buttonNext) triggerSlideChange(NEXT_PIN);
    if (msg->buttonPrev) triggerSlideChange(PREV_PIN);
  } else {
    Serial.println("Received data size does not match");
  }
}

void triggerSlideChange(int pin) {
  digitalWrite(pin, HIGH);
  delay(10);
  digitalWrite(pin, LOW);
  Serial.println(pin == NEXT_PIN ? "Next slide" : "Previous slide");
}

void setup() {
  Serial.begin(9600);
  setupPins();
  setupWiFi();
}

void loop() {
  // Основной цикл не используется, поскольку все действия происходят в OnDataRecv
}
