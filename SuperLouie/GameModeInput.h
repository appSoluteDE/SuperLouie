
#ifndef _GAMEMODEINPUT_h 
#define _GAMEMODEINPUT_h

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#endif

#define SWITCH_NORMAL A3
#define SWITCH_FAST A2
#define SWITCH_STOP A1
#define SWITCH_TURN A0

class GameModeInput
{
public:
	GameModeInput();
	
};

