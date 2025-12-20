#include "Main.h"
#include "Arduino.h"
#include "MessageReceiver.h"
#include "Display.h"
#include "Number.h"
#include "NumberServices.h"

// Usa Serial2 → pin 16 (TX), 17 (RX)
MessageReceiver receiver(Serial1);
Display display(0x27);
NumberServices numberServices;

void setup() {
    Serial.begin(115200);   // debug USB
    receiver.begin(9600);

    display.begin(16, 2);
    numberServices.begin();

    display.write(
        0, "System ready",
        0, "Waiting data"
    );
}

static int16_t lastValue = -1;     // ultimo valore valido ricevuto
static bool stopBlink = false;     // se arriva -2

void loop() {

  // 1) aggiorno lastValue solo quando ricevo
  if (receiver.update()) {
    int16_t value = receiver.getValue();
    Serial.println(value);

    if (value == -2) {
      stopBlink = true;          // comando stop (non stampare)
    } else {
      lastValue = value;         // numero 1..12
      stopBlink = false;

      display.write(0, "Binario:", 0, String(value));
    }
  }

  // 2) lampeggio: va chiamato SEMPRE nel loop
  if (!stopBlink) {
    numberServices.blinkPressedNumber(lastValue);
  } else {
	  if (lastValue >= 1 && lastValue <= 12) numberServices.on(lastValue);
  }
}



