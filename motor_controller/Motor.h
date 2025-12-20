#ifndef MOTOR_H_
#define MOTOR_H_

#include <Arduino.h>

class Motor {
public:
  Motor(uint8_t stepPin, uint8_t dirPin, uint8_t enablePin);

  void begin();

  void enable();
  void disable();

  void setDirection(bool dir);
  void step(int turns, uint16_t periodUs);

  void stepHigh();
  void stepLow();

private:
  uint8_t _stepPin;
  uint8_t _dirPin;
  uint8_t _enablePin;
};

#endif /* MOTOR_H_ */

