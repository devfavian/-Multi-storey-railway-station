#ifndef STATIONCONTROLLER_H_
#define STATIONCONTROLLER_H_

#include "Motor.h"
#include "MotorServices.h"

class StationController {
public:
  StationController(Motor& x, Motor& y, Motor& z, MotorServices& ms);

  void begin(int startTrack = 0);

  void goToTrack(int track);      // imposta target e fa il movimento
  int currentTrack() const;       // posizione attuale
  int targetTrack() const;        // ultimo target richiesto

private:
  Motor& motorX;
  Motor& motorY;
  Motor& motorZ;
  MotorServices& motorServices;

  int _currentTrack = 0;
  int _targetTrack  = 0;
};



#endif /* STATIONCONTROLLER_H_ */


