#include <Arduino.h>
#include "Button.h"

Button::Button(uint8_t pin)
  : _pin(pin) {
}

void Button::begin() {
  pinMode(_pin, INPUT_PULLUP);
}

bool Button::enable() {
  // INPUT_PULLUP: LOW = premuto
  return digitalRead(_pin) == LOW;
}

bool Button::disable() {
  return digitalRead(_pin) == HIGH;
}
