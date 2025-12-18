#include "TrainStation.h"
#include "Arduino.h"
#include "Motor.h"
#include "Button.h"
#include "Switch.h"
#include "MotorServices.h"
#include "ButtonServices.h"

int contatore = 0;
int posizione = 0;

Motor motorX(2, 5, 8);
Motor motorY(3, 6, 8);
Motor motorZ(4, 7, 8);

Switch switchX(9);
Switch switchY(10);
Switch switchZ(11);

MotorServices motorServices;
ButtonServices buttonServices;

void setup() {
  motorX.begin();
  motorY.begin();
  motorZ.begin();

  switchX.begin();
  switchY.begin();
  switchZ.begin();

  buttonServices.begin();

  Serial.begin(9600);

  posizione = 0;
  contatore = 0;
}

void VaiAlBinario(int pressedPin) {		//here is ok?
  contatore = pressedPin;
  int differenza = contatore - posizione;

  if (differenza == 0) return;

  bool dir = (differenza > 0);
  int turns = abs(differenza);

  motorX.setDirection(dir);	//duplicated code?
  motorY.setDirection(dir);
  motorZ.setDirection(dir);

  Serial.print("turns = ");
  Serial.println(turns);

  Serial.println("PRIMA");
  motorServices.stepAllSync(motorX, motorY, motorZ, turns);
  Serial.println("DOPO");


  posizione = contatore;
}



void loop() {
	  int pressedPin = buttonServices.readPressedNumber();
	  if (pressedPin != -1){
		  Serial.println(pressedPin);
		  VaiAlBinario(pressedPin);

	  }
}






