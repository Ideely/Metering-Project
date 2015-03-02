/*
* Title: Instance.cpp
* Authors: Larkin Crain
* Group: The A Team
* For: Senior Design - Metering Project
* Date: 2/15/2015
*
* The instance object, which defines what actions happen during a metering
* instance.
*
*/

#include "Instance.h"
#include "Arduino.h"

//The constructor, will initially set the state to be OFF
//and will set the time information to 0
Instance::Instance(int ledDataPin, int ledLatchPin, int ledClockPin, int voltageInputPin){
	//Specify which pins are to be used as input and output
	//Example: pinMode(ledPin, OUTPUT);      // sets the digital pin as output
	
	/* TESTING ONLY
	screen(
		PIN_SCREEN_COMMUNICATION_DSIP = -1,
		PIN_SCREEN_COMMUNICATION_EXTX = -1,
		PIN_SCREEN_COMMUNICATION_EXTM = -1,
		PIN_SCREEN_COMMUNICATION_SI = -1, 
		PIN_SCREEN_COMMUNICATION_SCS = -1, 
		PIN_SCREEN_COMMUNICATION_SCLK = -1
	);
	meterIn(
		PIN_METER_DATA_IN = 0,
		PIN_METER_DATA_OUT = 1,
		PIN_METER_CLOCK_SYNC = 2,
		PIN_METER_RESET = 3;
	);
	userIn(PIN_POWER, PIN_START);
	*/
	
	LED(int ledDataPin, int ledLatchPin, int ledClockPin);
	
	state = OFF;
	
	readUserInputInterval = 3;		//Check every 5 sleep cycles
	readkMeteringInputInterval = 2;	//Check every 3 sleep cycles
	talkLEDInterval = 1;				//Talk to them every 2 sleep cycles
	talkScreenInterval = 1;
}

//The function we will go to when we want to sleep,
//Will return true if there weren't any errors during the sleep cycle
//Will return false if there was an error generated during the sleep cycle
//Increments currentSleepCycle after a rest
bool Instance::Sleep(){

	//sleeper.Rest();
	delay(30);
	currentSleepCycle ++;
	
	return true;
}

//The function we will go to when we are awake and we want to perform out actions
//before we go back to sleep.
bool Instance::PerformActions(){
	//Logic here that will determine which actions to perform based on the value of the current time
	//Actions to perform:
	//Check for user input
	//Poll IC if running
	//Talk to LEDs
	//Talk to screen
	double meterReading 0;
	int voltage = 0;
	
	//For testing ONLY
	voltage = GetAnalogVoltageInput();
	leds.LEDwrite(leds.ConvertPower(voltage, 5));
	
	/*
	if(sleepCycle % readUserInputInterval == 0){
		//HandleButtonPresses();	//Read user input, such as restart, start, timer, etc.
	}
	if(sleepCycle % readkMeteringInputInterval == 0) {		
		//meterReading = ReadInstantaneousPowerFromMeter();	//Read metering input
	}
	if(sleepCycle % talkLEDInterval == 0) {
		//Display the current power being produced to the LEDs
		//Clark, call your LED talking function. We'll give you a number, you convert it into a serial stream
		//and send it to the LEDS
		
		//FOR TESTING ONLY
	}
	if(sleepCycle % talkScreenInterval == 0) {
		//Print the new screen on the memory LCD
	}
	*/
	
	return true;
}

int Instance::GetAnalogVoltageInput(){
	return analogRead(A1);
}

/*
//This function will take the 
bool Instance::HandleButtonPresses() {
	bool powerButtonPressed = false;
	bool restartButtonPressed = false;
	
	powerButtonPressed = userIn.CheckPowerButton();
	restartButtonPressed = userIn.CheckRestartButton();
	
	if(powerButtonPressed && !restartButtonPressed) {
		//Then we need to go into shutdown mode
		sleeper.Hibernate();
	}
	else if(restartButtonPressed && !powerButtonPressed) {
		//Then we need to restart the state of the machine
		
	}
}

//This function will read the result from the meter
double Instance::ReadInstantaneousPowerFromMeter(){
	return meterIn.ReadInstantaneousPower();
}
*/

