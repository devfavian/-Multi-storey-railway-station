#include "StationController.h"

StationController::StationController(Motor& x, Motor& y, Motor& z, MotorServices& ms)
  : motorX(x), motorY(y), motorZ(z), motorServices(ms) {}

void StationController::begin(int startTrack) {
  _currentTrack = startTrack;
  _targetTrack  = startTrack;
}

int StationController::getCurrentTrack() const { return _currentTrack; }
int StationController::getTargetTrack()  const { return _targetTrack;  }

void StationController::goToTrack(int track) {
  _targetTrack = track;

  int diff = _targetTrack - _currentTrack;
  if (diff == 0) return;

  bool dir = diff  < 0;
  int turns = abs(diff);

  motorServices.setDirectionAll(motorX, motorY, motorZ, dir);
  motorServices.stepAllSync(motorX, motorY, motorZ, turns);

  _currentTrack = _targetTrack;
}

void StationController::setCurrentTrack(int track) {
  _currentTrack = track;
  _targetTrack  = track;  // mantiene stato coerente
}





