#ifndef MOTORSERVICES_H_
#define MOTORSERVICES_H_

#include <Arduino.h>
#include "Motor.h"

class MotorServices {
public:
	void stepAllSync(Motor& motorX, Motor& motorY, Motor& motorZ, int turns);
	void setDirectionAll(Motor& motorX, Motor& motorY, Motor& motorZ, bool dir);
};

#endif /* MOTORSERVICES_H_ */
