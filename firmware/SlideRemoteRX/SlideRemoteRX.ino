// SlideRemote v1.0.1
// RX - Приёмник

// Подключение библиотек
#include <ESP8266WiFi.h>
#include <espnow.h>

// Настройка пинов подключения
#define prevPin D4
#define nextPin D3

// Структура, принимаемая от передатчика
struct StructMessage {
  bool buttonNext;
  bool buttonPrev;
};

StructMessage myData;

void setupPins() {
  pinMode(nextPin, OUTPUT);
  pinMode(prevPin, OUTPUT);
  digitalWrite(nextPin, LOW);
  digitalWrite(prevPin, LOW);
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
    if (msg->buttonNext) triggerSlideChange(nextPin);
    if (msg->buttonPrev) triggerSlideChange(prevPin);
  } else {
    Serial.println("Received data size does not match");
  }
}

void triggerSlideChange(int pin) {
  digitalWrite(pin, HIGH);
  delay(10);
  digitalWrite(pin, LOW);
  Serial.println(pin == nextPin ? "Next slide" : "Previous slide");
}

void setup() {
  Serial.begin(9600);
  setupPins();
  setupWiFi();
}

void loop() {
  // Основной цикл не используется, поскольку все действия происходят в OnDataRecv
}
