#include "TrainStation.h"
#include "Arduino.h"
#include "Motor.h"
#include "Button.h"
#include "Switch.h"
#include "MotorServices.h"
#include "ButtonServices.h"
#include "StationController.h"
#include "SwitchServices.h"

int counter = 0;
int position = 0;

Motor motorX(2, 5, 8);
Motor motorY(3, 6, 8);
Motor motorZ(4, 7, 8);

Switch switchX(9);
Switch switchY(10);
Switch switchZ(11);

MotorServices motorServices;
ButtonServices buttonServices;
StationController station(motorX, motorY, motorZ, motorServices);
SwitchServices switchServices(motorServices, switchX, switchY, switchZ);

void setup() {
  motorX.begin();
  motorY.begin();
  motorZ.begin();

  switchX.begin();
  switchY.begin();
  switchZ.begin();

  buttonServices.begin();

  station.begin();

  Serial.begin(9600);

  counter = 0;
  position = 0;
}

void loop() {
	  int pressedPin = buttonServices.readPressedNumber();
	  if (pressedPin != -1){
		  Serial.println(pressedPin);
		  	  if(pressedPin == 1)	switchServices.reset(motorX, motorY, motorZ, position);
		  	  else
		  		  station.goToTrack(pressedPin);
	  }
}






