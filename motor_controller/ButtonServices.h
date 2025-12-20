#ifndef BUTTONSERVICES_H_
#define BUTTONSERVICES_H_

#include <Arduino.h>

class ButtonServices {
public:
  ButtonServices();

  void begin();

  // ritorna il NUMERO associato al pulsante premuto, oppure -1
  int readPressedNumber();

  // (debug) ritorna il pin premuto, oppure -1
  int readHighPin();

private:
  static const uint8_t _count = 12;
  uint8_t _pins[_count];     // 46..35
  int _map[_count];          // numero associato per ciascun pin
};

#endif /* BUTTONSERVICES_H_ */



