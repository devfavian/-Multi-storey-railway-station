#ifndef MESSAGE_RECEIVER_H
#define MESSAGE_RECEIVER_H

#include <Arduino.h>

class MessageReceiver {
public:
    explicit MessageReceiver(HardwareSerial& serial);

    void begin(unsigned long baud);
    bool update();              // ritorna true se ha ricevuto un numero valido
    int16_t getValue() const;   // valore ricevuto

private:
    HardwareSerial& _serial;

    enum State {
        WAIT_START,
        WAIT_DATA
    };

    State _state;
    uint8_t _buffer[2];
    uint8_t _index;
    int16_t _value;

    static constexpr uint8_t START_BYTE = 0xAA;
};

#endif

