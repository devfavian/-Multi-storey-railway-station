#ifndef NUMBER_SERVICES_H
#define NUMBER_SERVICES_H

#include <Arduino.h>

class NumberServices {
public:
    NumberServices();

    void begin();

    void on(uint8_t number);
    void off(uint8_t number);

    void onAll();
    void offAll();

    // ⭐ NUOVO METODO
    void blinkPressedNumber(int16_t value, unsigned long periodMs = 300);

private:
    static const uint8_t _count = 12;
    uint8_t _pins[_count];

    // stato interno per il lampeggio
    int8_t _activeNumber = -1;   // 1..12
    bool _blinkState = false;
    bool _blinking = false;
    unsigned long _lastToggle = 0;
};

#endif


