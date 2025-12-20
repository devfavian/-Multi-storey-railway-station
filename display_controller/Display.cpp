#include "Display.h"

Display::Display(uint8_t address)
: _lcd(address, 16, 2)
{
}

void Display::begin(uint8_t cols, uint8_t rows, bool backlightOn) {
    _cols = cols;
    _rows = rows;

    _lcd.init();
    if (backlightOn) _lcd.backlight();
    else _lcd.noBacklight();

    _lcd.clear();
}

void Display::clearLine(uint8_t row) {
    _lcd.setCursor(0, row);
    for (uint8_t i = 0; i < _cols; i++) {
        _lcd.print(' ');
    }
}

void Display::write(uint8_t xRow0, const String& row0,
                    uint8_t xRow1, const String& row1) {

    // Riga 0
    clearLine(0);
    _lcd.setCursor(xRow0, 0);
    _lcd.print(row0);

    // Riga 1
    if (_rows >= 2) {
        clearLine(1);
        _lcd.setCursor(xRow1, 1);
        _lcd.print(row1);
    }
}



