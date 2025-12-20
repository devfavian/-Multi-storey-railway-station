#ifndef MESSAGE_SENDER_H
#define MESSAGE_SENDER_H

#include <Arduino.h>

class MessageSender {
public:
    explicit MessageSender(HardwareSerial& serial);

    void begin(unsigned long baud);

    // Invia un int16_t. Se requireAck=true aspetta ACK fino a timeoutMs.
    // Ritorna true se inviato (e ACK ricevuto, se richiesto).
    bool sendInt16(int16_t value, bool requireAck = false, uint32_t timeoutMs = 50);

private:
    HardwareSerial& _serial;

    static constexpr uint8_t START_BYTE = 0xAA;
    static constexpr uint8_t ACK_BYTE   = 0x55;
};

#endif

