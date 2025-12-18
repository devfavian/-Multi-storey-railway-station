#include "MotorServices.h"
#include <Arduino.h>
#include "Motor.h"

static const int STEPS_PER_REV = 3200;
static const uint16_t PULSE_US = 5;
static const uint16_t PERIOD_US = 1250;

void MotorServices::stepAllSync(
    Motor& motorX, Motor& motorY, Motor& motorZ, int turns) {

  long totalSteps = (long)turns * STEPS_PER_REV;

  for (long s = 0; s < totalSteps; s++) {
    motorX.stepHigh();
    motorY.stepHigh();
    motorZ.stepHigh();
    delayMicroseconds(PULSE_US);

    motorX.stepLow();
    motorY.stepLow();
    motorZ.stepLow();

    if (PERIOD_US > PULSE_US)
      delayMicroseconds(PERIOD_US - PULSE_US);
  }
}
