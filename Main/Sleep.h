/*
* Title: Sleep.h
* Authors: Larkin Crain
* Group: The A Team
* For: Senior Design - Metering Project
* Date: 2/12/2015
*
* This library will wrap the lower power library to provide less options for
* our current program. Many of the functions are presented to the user will
* be simplified and only the features that we need will be wrapped.
*	
* Function List:
* Constructor: 		Initializes any settings
* Rest: 			A short, 15ms power down
* Hibernate:		Power down until a wake signal comes in.
* TurnDown:			Turn off all non essential features of the chip.
* TurnUp:			Turn on all features of the chip, reset to default.
*/

//Prevents issues with accidental double linking
#ifndef Sleep_h
#define Sleep_h

#include "RocketScreamLibrary/LowPower.h"

class Sleep
{
	public:
		Sleep();			//Initialize the Sleep object.
		
		bool Rest();		//Sleep for a short amount of time, specifies the sleep cycle.
		bool Hibernate();	//Deep sleep until an input wakes it up.
		
		bool TurnDown();	//Turn off all non essential features.
		bool TurnUp();		//Turn on all features on the chip.			
	private:
		void BeginWakeUp();	//The function that is called when we receive an interrupt signal 
}

