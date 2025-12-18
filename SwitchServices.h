#ifndef SWITCHSERVICES_H_
#define SWITCHSERVICES_H_

#include <Arduino.h>
#include "Motor.h"
#include "Switch.h"
#include "MotorServices.h"

class SwitchServices {
public:
  SwitchServices(MotorServices& ms, Switch& sx, Switch& sy, Switch& sz);

  void begin();

  // Porta tutti gli assi ai rispettivi finecorsa (X+,Y+,Z+),
  // ferma ogni motore quando il suo switch è premuto.
  // Alla fine imposta position = 0.
  void reset(Motor& motorX, Motor& motorY, Motor& motorZ, int& position);

private:
  MotorServices& motorServices;
  Switch& switchX;
  Switch& switchY;
  Switch& switchZ;

  // Timing (mettili uguali a quelli che usi in stepAllSync, o regolali)
  static const uint16_t PULSE_US  = 5;
  static const uint16_t PERIOD_US = 1250;

  // Safety: evita loop infinito se un finecorsa non viene mai raggiunto
  static const long MAX_STEPS = 200000L;
};

#endif /* SWITCHSERVICES_H_ */

