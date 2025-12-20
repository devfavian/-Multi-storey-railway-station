#include "SwitchServices.h"

SwitchServices::SwitchServices(MotorServices& ms, Switch& sx, Switch& sy, Switch& sz)
  : motorServices(ms), switchX(sx), switchY(sy), switchZ(sz) {}

void SwitchServices::begin() {
  // nulla per ora
}

void SwitchServices::reset(
  Motor& motorX, Motor& motorY, Motor& motorZ
) {
  motorServices.setDirectionAll(motorX, motorY, motorZ, true);

  bool doneX = false;
  bool doneY = false;
  bool doneZ = false;

  long steps = 0;

  while (!(doneX && doneY && doneZ) && steps < MAX_STEPS) {

    if (!doneX && switchX.isPressed()) doneX = true;
    if (!doneY && switchY.isPressed()) doneY = true;
    if (!doneZ && switchZ.isPressed()) doneZ = true;

    if (doneX && doneY && doneZ) break;

    // HIGH insieme
    if (!doneX) motorX.stepHigh();
    if (!doneY) motorY.stepHigh();
    if (!doneZ) motorZ.stepHigh();

    delayMicroseconds(PULSE_US);

    // LOW insieme
    if (!doneX) motorX.stepLow();
    if (!doneY) motorY.stepLow();
    if (!doneZ) motorZ.stepLow();

    if (PERIOD_US > PULSE_US)
      delayMicroseconds(PERIOD_US - PULSE_US);

    steps++;
  }
}


