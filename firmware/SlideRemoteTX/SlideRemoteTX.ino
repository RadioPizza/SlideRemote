// SlideRemote v1.0.1
// TX - Передатчик

// Подключение библиотек
#include <EncButton.h>
#include <ESP8266WiFi.h>
#include <espnow.h>

// Настройка пинов подключения
#define BTN_PREV_PIN 5   // это D1 на Wemos
#define BTN_NEXT_PIN 4   // это D2 на Wemos
#define BTN_LASER_PIN 0  // это D3 на Wemos
#define LED_LASER_PIN 16 // это D0 на Wemos

Button buttonPrev(BTN_PREV_PIN);
Button buttonNext(BTN_NEXT_PIN);
Button buttonLaser(BTN_LASER_PIN);

// MAC адрес приёмника
uint8_t broadcastAddress[] = {0x48, 0x55, 0x19, 0xDE, 0xB3, 0x6B};

// Структура для отправки данных
struct StructMessage {
  bool buttonNext;
  bool buttonPrev;
};

StructMessage myData;

void setupWiFi() {
  WiFi.mode(WIFI_STA); 
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
  Serial.println("WiFi Setup completed successfully");
}

void setup() {
  Serial.begin(9600);
  pinMode(LED_LASER_PIN, OUTPUT);
  setupWiFi();
  Serial.println("Initialization completed successfully");
}

void updateButtonsState(bool next, bool prev) {
  myData.buttonNext = next;
  myData.buttonPrev = prev;
  
  if (esp_now_send(broadcastAddress, (uint8_t *)&myData, sizeof(myData)) != 0) {
    Serial.println("Error sending the data");
  }
}

void handleLaserButton() {
  if (buttonLaser.press()) {
    digitalWrite(LED_LASER_PIN, HIGH);
    Serial.println("Laser ON");
  } else if (buttonLaser.release()) {
    digitalWrite(LED_LASER_PIN, LOW);
    Serial.println("Laser OFF");
  }
}

void handleSlideButtons() {
  const bool nextClicked = buttonNext.click();
  const bool prevClicked = buttonPrev.click();
  
  if (nextClicked || prevClicked) {
    updateButtonsState(nextClicked, prevClicked);
    Serial.println(nextClicked ? "Button Next was clicked" : "Button Prev was clicked");
  }
}

void loop() {
  buttonPrev.tick();
  buttonNext.tick();
  buttonLaser.tick();
  handleSlideButtons();
  handleLaserButton();
}
