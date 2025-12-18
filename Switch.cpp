#include "Switch.h"

Switch::Switch(uint8_t pin)
  : _pin(pin) {
}

void Switch::begin() {
  pinMode(_pin, INPUT_PULLUP);
}

bool Switch::isPressed() {
  return digitalRead(_pin) == LOW;   // INPUT_PULLUP
}

bool Switch::isNotPressed() {
  return digitalRead(_pin) == HIGH;
}

