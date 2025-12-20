#ifndef STATIONCONTROLLER_H_
#define STATIONCONTROLLER_H_

#include "Motor.h"
#include "MotorServices.h"

class StationController {
public:

  static constexpr int BASE_TRACK = 1;

  StationController(Motor& x, Motor& y, Motor& z, MotorServices& ms);

  void begin(int startTrack = BASE_TRACK);

  void goToTrack(int track);      // imposta target e fa il movimento

  int getCurrentTrack() const;       // posizione attuale
  int getTargetTrack() const;        // ultimo target richiesto
  void setCurrentTrack(int track);

private:
  Motor& motorX;
  Motor& motorY;
  Motor& motorZ;
  MotorServices& motorServices;

  int _currentTrack = BASE_TRACK;
  int _targetTrack  = BASE_TRACK;
};



#endif /* STATIONCONTROLLER_H_ */


