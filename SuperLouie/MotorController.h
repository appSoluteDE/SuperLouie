
#ifndef _MOTORCONTROLLER_h
#define _MOTORCONTROLLER_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#endif

#define SPEED_NORMAL 40
#define SPEED_FAST 100
#define SPEED_STOP 10

enum MotorSpeed { Slow, Normal, Fast };
enum TurnDirection { Right = 0, Left = 1};

class MotorController
{
public:
	MotorController();
	MotorController(int directionPinA, int directionPinB, int pwmPin);

	MotorSpeed motorSpeed;
	TurnDirection turnDirection;
private:
	int pinA;
	int pinB;
	int pinPWM;

	void ChangeDirection();
};

