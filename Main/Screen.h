/*
* Title: Screen.h
* Authors: Larkin Crain
* Group: The A Team
* For: Senior Design - Metering Project
* Date: 2/12/2015
*
* Library definition for interfacing with the screen that we will use. Currently, this is the 
* Sharp Memory LCD 2.7in.
*
*/

//Prevents issues with accidental double linking
#ifndef Screen_h
#define Screen_h

#include "Adafruit-GFX-library/Adafruit_GFX.h"
#include "SharpMemoryLCD/SharpMemopryLcd.h"

class Screen {
	
	public:
		bool Write(char message[]);		//Send a message to the screen
		bool Clear();					//Clear the screen
		bool Flash();					//Quickly make the screen flash (by inverting and un-inverting it quickly)
	private:
		SHARPMEMORYLCD screenObject;	//The library for talking to the Sharp Memory LCD
		int flashDelay;					//The number of microseconds to delay between inverting when flashing the screen
	
}
