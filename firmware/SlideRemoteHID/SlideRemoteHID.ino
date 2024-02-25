#include <EasyHID.h>
#define INPUT_NEXT_PIN 0 // Следующий слайд
#define INPUT_PREV_PIN 1 // Предыдущий слайд

void setup() {
  pinMode(INPUT_NEXT_PIN, INPUT);
  pinMode(INPUT_PREV_PIN, INPUT);
  HID.begin();           // Инициализация USB
}

void loop() {
  HID.tick();            // Тикер HID
  if (digitalRead(INPUT_PREV_PIN))  Keyboard.click(KEY_ARROW_RIGHT);
  if (digitalRead(INPUT_NEXT_PIN))  Keyboard.click(KEY_ARROW_LEFT);
}
