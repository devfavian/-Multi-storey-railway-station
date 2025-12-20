#include "NumberServices.h"

NumberServices::NumberServices() {
    _pins[0]  = 34;
    _pins[1]  = 33;
    _pins[2]  = 32;
    _pins[3]  = 31;
    _pins[4]  = 30;
    _pins[5]  = 29;
    _pins[6]  = 28;
    _pins[7]  = 27;
    _pins[8]  = 26;
    _pins[9]  = 25;
    _pins[10] = 24;
    _pins[11] = 23;
}

void NumberServices::begin() {
    for (uint8_t i = 0; i < _count; i++) {
        pinMode(_pins[i], OUTPUT);
        digitalWrite(_pins[i], HIGH);
    }
}

void NumberServices::on(uint8_t number) {
    if (number < 1 || number > _count) return;
    digitalWrite(_pins[number - 1], HIGH);
}

void NumberServices::off(uint8_t number) {
    if (number < 1 || number > _count) return;
    digitalWrite(_pins[number - 1], LOW);
}

void NumberServices::onAll() {
    for (uint8_t i = 0; i < _count; i++) {
        digitalWrite(_pins[i], HIGH);
    }
}

void NumberServices::offAll() {
    for (uint8_t i = 0; i < _count; i++) {
        digitalWrite(_pins[i], LOW);
    }
}

// ⭐⭐ METODO CHIAVE ⭐⭐
void NumberServices::blinkPressedNumber(int16_t number, unsigned long periodMs) {
    unsigned long now = millis();

    // numero valido?
    if (number < 1 || number > _count) {
        return;
    }

    // cambio numero → reset stato
    if (number != _activeNumber) {
        _activeNumber = number;
        _blinkState = false;
        _lastToggle = now;
    }

    // abilita lampeggio
    _blinking = true;

    // lampeggio
    if (now - _lastToggle >= periodMs) {
        _lastToggle = now;
        _blinkState = !_blinkState;

        off(_activeNumber);
        if (_blinkState) {
            on(_activeNumber);
        }
    }
}
