// SlideRemote v1.0.1
// USB HID

// Подключение библиотек
#include <DigiKeyboard.h>

// Настройка пинов подключения
#define PREV_PIN 0
#define NEXT_PIN 1

void setup() {
  pinMode(PREV_PIN, INPUT);
  pinMode(NEXT_PIN, INPUT);
}

void loop() {
  if (digitalRead(PREV_PIN)){
    DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
    DigiKeyboard.delay(10);
  }
  
  if (digitalRead(NEXT_PIN)){
    DigiKeyboard.sendKeyStroke(KEY_SPACE);
    DigiKeyboard.delay(10);
  }
}                                                                                                                                                                                                                                                                                                                                         
