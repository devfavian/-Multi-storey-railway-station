#include "MessageReceiver.h"

MessageReceiver::MessageReceiver(HardwareSerial& serial)
: _serial(serial),
  _state(WAIT_START),
  _index(0),
  _value(0)
{
}

void MessageReceiver::begin(unsigned long baud) {
    _serial.begin(baud);
}

bool MessageReceiver::update() {
    while (_serial.available()) {
        uint8_t b = _serial.read();

        switch (_state) {
            case WAIT_START:
                if (b == START_BYTE) {
                    _index = 0;
                    _state = WAIT_DATA;
                }
                break;

            case WAIT_DATA:
                _buffer[_index++] = b;
                if (_index >= 2) {
                    memcpy(&_value, _buffer, 2);
                    _state = WAIT_START;
                    return true;    // messaggio completo
                }
                break;
        }
    }
    return false;
}

int16_t MessageReceiver::getValue() const {
    return _value;
}


