// SlideRemote v1.0.1
// USB HID

// Подключение библиотек
#include <DigiKeyboard.h>

// Настройка пинов подключения
#define prevPin 0
#define nextPin 1

void setup() {
  pinMode(prevPin, INPUT);
  pinMode(nextPin, INPUT);
}

void loop() {
  if (digitalRead(prevPin)){
    DigiKeyboard.sendKeyStroke(KEY_ARROW_LEFT);
    DigiKeyboard.delay(10);
  }
  
  if (digitalRead(nextPin)){
    DigiKeyboard.sendKeyStroke(KEY_SPACE);
    DigiKeyboard.delay(10);
  }
}                                                                                                                                                                                                                                                                                                                                         
