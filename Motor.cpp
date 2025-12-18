#include "Motor.h"

int stepsPerRevolution  = 3200;

Motor::Motor(uint8_t stepPin, uint8_t dirPin, uint8_t enablePin)
  : _stepPin(stepPin),
    _dirPin(dirPin),
    _enablePin(enablePin) {
}

void Motor::begin() {
  pinMode(_stepPin, OUTPUT);
  pinMode(_dirPin, OUTPUT);
  pinMode(_enablePin, OUTPUT);

  enable();
}

void Motor::enable() {
  digitalWrite(_enablePin, LOW);   // TMC enable attivo LOW
}

void Motor::disable() {
  digitalWrite(_enablePin, HIGH);
}

void Motor::setDirection(bool dir) {
  digitalWrite(_dirPin, dir ? HIGH : LOW);
}

void Motor::step(int turns, uint16_t periodUs) {
	 for (int i = 0; i < turns; i++) {
	    for (int y = 0; y < stepsPerRevolution; y++) {
	      digitalWrite(_stepPin, HIGH);
	      delayMicroseconds(5);          // impulso breve
	      digitalWrite(_stepPin, LOW);

	      // completa il periodo
	      if (periodUs > 5) delayMicroseconds(periodUs - 5);
	    }
	  }
}

void Motor::stepHigh() {
  digitalWrite(_stepPin, HIGH);
}

void Motor::stepLow() {
  digitalWrite(_stepPin, LOW);
}



