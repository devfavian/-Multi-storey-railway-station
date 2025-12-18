#ifndef SWITCH_H_
#define SWITCH_H_

#include <Arduino.h>

class Switch {
public:
  Switch(uint8_t pin);

  void begin();

  bool isPressed();     // true se premuto
  bool isNotPressed();  // true se rilasciato

private:
  uint8_t _pin;
};

#endif /* SWITCH_H_ */

