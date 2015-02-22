/*
* Title: Sleep.cpp
* Author: Larkin Crain
* Group: The A Team
* For: Senior Design - Metering Project
* Date: 2/12/2015
*
* Description: This is a class definition of the Sleep library that will have two core functions: 
* 1) Rest - a short (30ms) power down that attempt to conserve power in between times when the 
*      processor needs to be computing
* 2) Hibernate - An indefinite rest that will only be awaken from with an awake signal.
*
* The library includes two other functions, TurnUp and TurnDown that allow the user to specify
* if the chip should turn on or off the non essential features (like the ADC).
*/

#include "Sleep.h"

bool Sleep::Sleep(int unusedPins[]) {
	//Initialize anything in the low-power library that we need. We will pass in an array
	//of numbers representing the pins that will not be used by the program and we will
	//then turn them off. 
	
	TurnDown(unusedPins);	//Turn off these pins
}

bool Sleep::Rest() {
	//This will put the module into a power saving mode for a short period of time.
	//Since the low power library only specifies certain amounts of time to rest the module,
	//we will initially attempt to work around that.
	
	//Go into the lowest power consumption state that the LowPower library offers,
	//lasting 30ms, with the Analogue to Digital Converter off, and the Brown Out Detection
	//Module off as well, to save power.
	LowPower.powerDown(SLEEP_30MS, ADC_OFF, BOD_OFF);
	
	return true;	
}

bool Sleep::Hibernate(){
	//This will place the chip into a deep power saving mode for an indefinite period of time.
	//The chip will only awaken upon an external signal.
	
	//Go into the lowest power consumption state that the LowPower library offers,
	//lasting indefinitely, with the Analogue to Digital Converter off, and the Brown Out Detection
	//Module off as well, to save power.			
	BeginHibernate();
	LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);						 
		
	return true;
}

bool Sleep::TurnDown() {
	//This feature will turn everything off that doesn't need to be running during the hibernate cycle
}

bool Sleep::TurnUp() {
	//This function will enable everything to normal running procedure on the chip.
}

void Sleep::BeginHibernate(){
	//This function will be called when our chip is beginning to go into hibernation. We need to shut off all pins
	//except for the pin used to monitor for the interrupt signal, and then we need to attach an interrupt watcher.
	
	attachInterrupt(		//Attach an interrupt so we can wake when a user interacts with us.
		0, 					//The first argument is the interrupt number, interrupt 0 is pin 2
		BeginWakeUp,		//The second parameter is the function to call, which must accept no parameters and return no value
		HIGH				//The third parameter is the what the trigger condition is, so when the pin goes HIGH is when we'll trigger it
	);

	TurnDown();	
}

void Sleep::BeginWakeUp() {
	detachInterrupt(0);					//When we are leaving the hibernate state, turn off interrupt so we don't waste power
	
	TurnUp();
}
