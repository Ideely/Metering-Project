/*
* Title: Instance.h
* Author: Larkin Crain
* Group: The A Team
* For: Senior Design - Metering Project
* Date: 2/12/2015
*
* This is the abstraction of an instance of a metering. That is, when the user selects that they would like
* to begin monitoring the amount of energy produced during a certain interval, the time from the moment that
* the start button is pressed to the end of the specified interval is the instance. The instance will remain
* active until the user resets it or the micro-controller loses power.
*
*/

//Prevents issues with accidental double linking
#ifndef Instance_h
#define Instance_h

#include "Input/UserInput/UserInput.h"
#include "Input/Metering/Metering.h"
#include "Output/Screen/Screen.h"
#include "Output/LED/LED.h"

//Libraries from third parties to include
#include "Input/Metering/ADE7753.h"								//ADE7753 communication library
#include "Output/Screen/Adafruit-GFX-library/Adafruit_GFX.h"	//Library that the sharp memory library extends
#include "Output/Screen/SharpMemoryLCD/SharpMemoryLcd.h"		//Sharp Memory LCD communication library
#include "PowerSaving/RocketScreamLibrary/LowPower/h"			//Provides powerful low-power sleep functions

//Describes the state of the instance
enum InstanceState {
	OFF,				//The instance hasn't stated, getting ready to start
	STARTED,			//The instance is going, computing power, and the timer is counting down
	COMPLETED			//The instance has completed fully. 
};

class Instance {
	public:
		bool Sleep();							//Will put the microprocessor to sleep for 30ms
		bool PerformActions();					//Will perform certain actions depending upon the current clock cycle
		
		bool UpdatePower(double powerAddition);	//Updates the total power developed
		int HandleUserInput(bool powerButtonPress, bool startButtonPress); //Given the current state, determine the course of action
		
		bool Restart();							//Sets the state to OFF, and immediately
		bool Stop();							//Sets the state to OFF
		
		double averagePower;					//The average power produced
		double totalEnergy;						//The total energy developed up to now.
		InstanceState state;					//The current state of the instance
		
	private:
		double currentTimeMillseconds;		//The time on the timer
		double currentSleepCycle;			//The current sleep cycle that the instance is on	
		
		const int readUserInputInterval = 3;		//Check every 5 sleep cycles
		const int readkMeteringInputInterval = 2;	//Check every 3 sleep cycles
		const int talkLEDInterval = 1;				//Talk to them every 2 sleep cycles
		const int talkScreenInterval = 1;			//Talk to it every 2 sleep cycles

		Sleep sleeper;			//The sleep object, will be used to perform rest operations
		UserInput userIn;		//The user input object, will be used to evaluate any input from the user
		MeterInput meterIn;		//The meter input object, will be used to read from the metering circuit
		Screen screenOut;		//The screen output object, we will use it to communicate with our screen
		
		const int PIN_INTERRUPT = 2				//The pin for the interrupt. This cannot change.
		const int PIN_POWER = -1;				//Pin that is associated with the power button
		const int PIN_START = -1;				//The pin that is associated with the start button
		const int PIN_METERING_COM = -1;		//The pin that is associated with the metering circuit
		const int PIN_LEDS[] = {-1, -1, -1};	//The pin array that is associated with the LEDs
		const int PIN_SCREEN[] = {-1, -1, -1};	//The pin array that is associated with the screen
}
