// SlideRemote v1.0.0

// Подключение библиотек
#include <DigiKeyboard.h>

// Настройка пинов подключения
#define INPUT_NEXT_PIN 0
#define INPUT_PREV_PIN 1

void setup() {
  pinMode(INPUT_NEXT_PIN, INPUT);
  pinMode(INPUT_PREV_PIN, INPUT);
}

void loop() {
  
  if (digitalRead(INPUT_PREV_PIN)){
    DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
    DigiKeyboard.delay(10);
  }
  
  if (digitalRead(INPUT_NEXT_PIN)){
    DigiKeyboard.sendKeyStroke(KEY_SPACE);
    DigiKeyboard.delay(10);
  }
}                                                                                                                                                                                                                                                                                                                                         
