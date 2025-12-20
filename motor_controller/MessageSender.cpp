#include "MessageSender.h"

MessageSender::MessageSender(HardwareSerial& serial)
: _serial(serial)
{
}

void MessageSender::begin(unsigned long baud) {
    _serial.begin(baud);
}

bool MessageSender::sendInt16(int16_t value, bool requireAck, uint32_t timeoutMs) {
    // Frame: [START][2 bytes payload]
    _serial.write(START_BYTE);
    _serial.write(reinterpret_cast<const uint8_t*>(&value), 2);
    _serial.flush(); // aspetta che i byte escano (UART TX buffer)

    if (!requireAck) return true;

    uint32_t t0 = millis();
    while (millis() - t0 < timeoutMs) {
        if (_serial.available() > 0) {
            uint8_t b = _serial.read();
            if (b == ACK_BYTE) return true;
            // se arriva altro, lo scarto
        }
    }
    return false; // timeout ACK
}


