#include "Number.h"

Number::Number(uint8_t pin)
: _pin(pin)
{
    pinMode(_pin, OUTPUT);
    off();
}

void Number::on() {
    digitalWrite(_pin, HIGH);
}

void Number::off() {
    digitalWrite(_pin, LOW);
}



