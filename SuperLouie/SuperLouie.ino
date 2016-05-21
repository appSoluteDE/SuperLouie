/*
 Name:		SuperLouie.ino
 Created:	13.12.2015 22:40:45
 Author:	nhhop
*/
#define DEBUG true

#define SWITCH_NORMAL A3
#define SWITCH_FAST A2
#define SWITCH_STOP A1
#define SWITCH_TURN A0

#define SPEED_NORMAL 40
#define SPEED_FAST 100
#define SPEED_STOP 10

bool normalEnabled = false;
bool fastEnabled = false;
bool stopEnabled = false;
bool turnEnabled = false;
int turnProbability = 20;
int stopProbability = 15;
int highProbability = 35;

int motor1_A = 6;
int motor1_B = 5;
int SPEED_PIN = 3;

int motor2_A = 6;
int motor2_B = 5;
int motor2_Speed = 3;

bool isOn = true;
int motorSpeed = 180;

int d = 0;

long randNumber;

int spin;


void setup() {
	if (DEBUG) {
		Serial.begin(9600);
	}

	//Random seed from empty pin --> Noise
	randomSeed(analogRead(A5));

	//LED
	pinMode(13, OUTPUT);

	//Motor pins
	pinMode(motor1_A, OUTPUT);
	pinMode(motor1_B, OUTPUT);

	//Game mode switch
	pinMode(SWITCH_NORMAL, INPUT);
	pinMode(SWITCH_FAST, INPUT);
	pinMode(SWITCH_STOP, INPUT);
	pinMode(SWITCH_TURN, INPUT);

	//reset
	digitalWrite(motor1_A, LOW); // A = LOW and B = HIGH means the motor will turn left
	digitalWrite(motor1_B, HIGH);

	analogWrite(SPEED_PIN, 180);

	spin = 1;
}

void checkGameMode()
{
	normalEnabled = digitalRead(SWITCH_NORMAL) == 1;
	fastEnabled = digitalRead(SWITCH_FAST) == 1;
	stopEnabled = digitalRead(SWITCH_STOP) == 1;
	turnEnabled = digitalRead(SWITCH_TURN) == 1;
}

void loop()
{
	checkGameMode();

	randNumber = random(0, 100);


	if (stopEnabled && randNumber < stopProbability)
	{
		Serial.println("stop");

		motorSpeed = changeSpeed(SPEED_STOP);

		delay(random(1000, 3000));

		motorSpeed = changeSpeed(SPEED_NORMAL);
	}

	if (fastEnabled && randNumber < highProbability)
	{
		Serial.println("high speed");

		motorSpeed = changeSpeed(SPEED_FAST);

		delay(random(1000, 4000));

		//highProbability--;
	}
	else if (normalEnabled && randNumber >= (100 - highProbability))
	{
		Serial.println("normal speed");

		motorSpeed = changeSpeed(SPEED_NORMAL);

		delay(random(2000, 4000));

		//highProbability++;
	}


	if (turnEnabled && randNumber < turnProbability)
	{
		Serial.println("direction change");

		changeDirection();

		delay(random(2000, 5000));

		changeDirection();

	}

	if (DEBUG)
	{
		Serial.print(d);
		Serial.println("---------------------");
		d++;
	}

	delay(1000);
}

int changeSpeed(int newSpeed)
{
	if (newSpeed <256)
	{
		if (newSpeed < motorSpeed)
		{
			for (int i = motorSpeed; i > newSpeed; i -= 5)
			{
				analogWrite(SPEED_PIN, i);
				delay(100);
			}
		}
		else
		{
			for (int i = motorSpeed; i < newSpeed; i += 5)
			{
				analogWrite(SPEED_PIN, i);
				delay(100);
			}
		}



		return newSpeed;
	}
}

void changeDirection()
{
	//int oldSpeed = motorSpeed;

	//slow down
	//changeSpeed(50);

	//change direction
	if (spin == 0)
	{
		digitalWrite(motor1_A, LOW); // A = LOW and B = HIGH means the motor will turn left
		digitalWrite(motor1_B, HIGH);

		spin = 1;
	}
	else
	{
		digitalWrite(motor1_A, HIGH); // A = HIGH and B = LOW means the motor will turn right
		digitalWrite(motor1_B, LOW);

		spin = 0;
	}

	//speed up
	//changeSpeed(oldSpeed);
}
