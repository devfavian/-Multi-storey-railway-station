#ifndef BUTTON_H_
#define BUTTON_H_

#include <Arduino.h>

class Button {
public:
  Button(uint8_t pin);

  void begin();

  bool enable();   // true quando il pulsante è premuto
  bool disable();  // true quando il pulsante NON è premuto

private:
  uint8_t _pin;
};

#endif /* BUTTON_H_ */

