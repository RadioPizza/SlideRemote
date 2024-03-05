// Подключение библиотек
#include <ESP8266WiFi.h>
#include <espnow.h>

// Настройка пинов подключения
#define prevPIN D4
#define nextPIN D3

// Структура, принимаемая от передатчика
typedef struct struct_message {
  bool buttonNext;
  bool buttonPrev;
} struct_message;
  
struct_message myData;

// Функция, вызываемая при получении данных
void OnDataRecv(uint8_t * mac, uint8_t *incomingData, uint8_t len) {
  memcpy(&myData, incomingData, sizeof(incomingData));
  if (((struct_message *)incomingData)->buttonNext) {
    digitalWrite(nextPIN, HIGH);
    delay(10);
    digitalWrite(nextPIN, LOW);
    // Действие при получении команды "Next"
  }
  if (((struct_message *)incomingData)->buttonPrev) {
    digitalWrite(prevPIN, HIGH);
    delay(10);
    digitalWrite(prevPIN, LOW);
    // Действие при получении команды "Prev"
  }
}

void setup() {
  pinMode(nextPIN, OUTPUT);
  pinMode(prevPIN, OUTPUT);
  digitalWrite(nextPIN, LOW);
  digitalWrite(prevPIN, LOW);
  Serial.begin(9600);
  // Инициализация Wi-Fi в режиме станции
  WiFi.mode(WIFI_STA);

  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  
  // Установка роли устройства в ESP-NOW сети
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);

  // Регистрация функции обратного вызова для приема данных
  esp_now_register_recv_cb(OnDataRecv);
  Serial.println("ESP-NOW receiver initialized");
}

void loop() {
  // Тут ничего делать не нужно, все действия происходят в функции обратного вызова OnDataRecv
}
