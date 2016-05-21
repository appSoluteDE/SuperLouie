#include "MotorController.h"

MotorController::MotorController()
{
}

MotorController::MotorController(int directionPinA, int directionPinB, int pwmPin)
{
	this->pinA = directionPinA;
	this->pinB = directionPinB;
	this->pinPWM = pwmPin;
}

void MotorController::ChangeDirection()
{
	digitalWrite(pinA, turnDirection); // A = LOW and B = HIGH means the motor will turn left
	digitalWrite(pinB, !turnDirection);
	
	//if (turnDirection == TurnDirection::Right)
	//{
	//	digitalWrite(pinA, LOW); // A = LOW and B = HIGH means the motor will turn left
	//	digitalWrite(pinB, HIGH);
	//}
	//else if (turnDirection == TurnDirection::Left)
	//{
	//	digitalWrite(pinA, HIGH); // A = HIGH and B = LOW means the motor will turn right
	//	digitalWrite(pinB, LOW);
	//}

	turnDirection = static_cast<TurnDirection>(!turnDirection);
}

