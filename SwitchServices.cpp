#include "SwitchServices.h"

SwitchServices::SwitchServices(MotorServices& ms, Switch& sx, Switch& sy, Switch& sz)
  : motorServices(ms), switchX(sx), switchY(sy), switchZ(sz) {}

void SwitchServices::begin() {
  // nulla per ora
}

void SwitchServices::reset(Motor& motorX, Motor& motorY, Motor& motorZ, int& position) {
  // direzione verso i finecorsa: scegli il verso corretto per la tua meccanica
  // (qui assumo "false" = scendere/andare verso 0)
  motorServices.setDirectionAll(motorX, motorY, motorZ, false);

  bool doneX = false;
  bool doneY = false;
  bool doneZ = false;

  long steps = 0;

  while (!(doneX && doneY && doneZ) && steps < MAX_STEPS) {
    // aggiorna chi è arrivato
    if (!doneX && switchX.isPressed()) doneX = true;
    if (!doneY && switchY.isPressed()) doneY = true;
    if (!doneZ && switchZ.isPressed()) doneZ = true;

    // se tutti arrivati, esci
    if (doneX && doneY && doneZ) break;

    // STEP HIGH solo per chi non è arrivato
    if (!doneX) motorX.stepHigh();
    if (!doneY) motorY.stepHigh();
    if (!doneZ) motorZ.stepHigh();
    delayMicroseconds(PULSE_US);

    // STEP LOW solo per chi non è arrivato
    if (!doneX) motorX.stepLow();
    if (!doneY) motorY.stepLow();
    if (!doneZ) motorZ.stepLow();

    if (PERIOD_US > PULSE_US) delayMicroseconds(PERIOD_US - PULSE_US);

    steps++;
  }

  // Se vuoi: gestione errore (finecorsa non raggiunto)
  // if (steps >= MAX_STEPS) { ... }

  position = 0;
}

