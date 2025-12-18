#include "ButtonServices.h"

ButtonServices::ButtonServices() {
  // pin da 46 a 35
  uint8_t p = 46;
  for (uint8_t i = 0; i < _count; i++) {
    _pins[i] = p--;
    _map[i]  = i + 1;   // mapping di default: 46->1, 45->2, ... 35->12
  }

  // ESEMPIO specifico richiesto: se arriva 35 -> voglio 3
  // 35 è l'ultimo nell'array (indice 11)
  _map[_count - 1] = 3;
}

void ButtonServices::begin() {
  for (uint8_t i = 0; i < _count; i++) {
    pinMode(_pins[i], INPUT_PULLUP);
  }
}

int ButtonServices::readHighPin() {
  for (uint8_t i = 0; i < _count; i++) {
    // INPUT_PULLUP: premuto = LOW
    if (digitalRead(_pins[i]) == LOW) {
      return _pins[i];
    }
  }
  return -1;
}

int ButtonServices::readPressedNumber() {
  for (uint8_t i = 0; i < _count; i++) {
    if (digitalRead(_pins[i]) == LOW) {
      return _map[i];  // ritorna il numero associato al pin premuto
    }
  }
  return -1;
}


