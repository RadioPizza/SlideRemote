// SlideRemote v1.0.0
// Передатчик

// Подключение библиотек
#include <EncButton.h>
#include <ESP8266WiFi.h>
#include <espnow.h>

// Настройка пинов подключения
Button buttonPrev(D1);
Button buttonNext(D2);
Button buttonLaser(D3);
#define LASER_PIN D0

// MAC адрес приёмника
uint8_t broadcastAddress[] = {0x48, 0x55, 0x19, 0xDE, 0xB3, 0x6B};

// Структура для отправки данных
typedef struct struct_message {
  bool buttonNext;
  bool buttonPrev;
} struct_message;
struct_message myData = {false, false};

void setup() {
  Serial.begin(9600);
  pinMode(LASER_PIN, OUTPUT);
  pinMode(BUILTIN_LED, OUTPUT);
  digitalWrite(BUILTIN_LED, LOW);
  WiFi.mode(WIFI_STA);
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    digitalWrite(BUILTIN_LED, HIGH);
    return;
  }
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
  Serial.println("Initialization completed successfully");
}

void updateButtonsState(bool next, bool prev) {
  myData.buttonNext = next;
  myData.buttonPrev = prev;
  int result = esp_now_send(broadcastAddress, (uint8_t *)&myData, sizeof(myData));
  if(result != 0) {
    Serial.println("Error sending the data");
    digitalWrite(BUILTIN_LED, HIGH);
  }
}

void handleLaserButton() {
  if (buttonLaser.press()) {
    digitalWrite(LASER_PIN, HIGH);
    Serial.println("Laser ON");
  }
  if (buttonLaser.release()) {
    digitalWrite(LASER_PIN, LOW);
    Serial.println("Laser OFF");
  }
}

void handleSlideButtons() {
  bool nextClicked = buttonNext.click();
  bool prevClicked = buttonPrev.click();
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