#ifndef NUMBER_H
#define NUMBER_H

#include <Arduino.h>

class Number {
public:
    explicit Number(uint8_t pin);

    void on();
    void off();

private:
    uint8_t _pin;

    bool _blinking = false;
    bool _state = false;
    unsigned long _lastToggle = 0;
};

#endif


