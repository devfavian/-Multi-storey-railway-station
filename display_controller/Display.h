#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class Display {
public:
    explicit Display(uint8_t address = 0x27);

    void begin(uint8_t cols, uint8_t rows, bool backlightOn = true);

    // Un solo metodo write:
    // setCursor(xRow0,0) e setCursor(xRow1,1)
    void write(uint8_t xRow0, const String& row0,
               uint8_t xRow1, const String& row1);

private:
    uint8_t _cols = 16;
    uint8_t _rows = 2;

    LiquidCrystal_I2C _lcd;

    void clearLine(uint8_t row);
};

#endif
