#include "ButtonServices.h"

ButtonServices::ButtonServices() {
  // PIN FISICI
  _pins[0]  = 46;
  _pins[1]  = 45;
  _pins[2]  = 44;
  _pins[3]  = 43;
  _pins[4]  = 42;
  _pins[5]  = 41;
  _pins[6]  = 40;
  _pins[7]  = 39;
  _pins[8]  = 38;
  _pins[9]  = 37;
  _pins[10] = 36;
  _pins[11] = 35;

  // MAPPATURA LOGICA
  _map[0]  = 1;   // 46 → 1
  _map[1]  = 2;   // 45 → 2
  _map[2]  = 3;   // 44 → 3
  _map[3]  = 4;
  _map[4]  = 5;
  _map[5]  = 6;
  _map[6]  = 7;
  _map[7]  = 8;
  _map[8]  = 9;
  _map[9]  = 10;
  _map[10] = 11;
  _map[11] = 12;  // 35 → 12
}

void ButtonServices::begin() {
  for (uint8_t i = 0; i < _count; i++) {
    pinMode(_pins[i], INPUT_PULLUP);
  }
}

int ButtonServices::readPressedNumber() {
  for (uint8_t i = 0; i < _count; i++) {
    if (digitalRead(_pins[i]) == LOW) {
      return _map[i];
    }
  }
  return -1;
}



