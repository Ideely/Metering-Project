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

//The constructor, will initially set the state to be OFF
//and will set the time information to 0
Instance::Instance(){
	state = OFF;
}

//This function will start a new instance, changing it's state from OFF to STARTED
bool Instance::Begin(){
	state = STARTED;
}

//The function we will go to when we want to sleep,
//Will return true if there weren't any errors during the sleep cycle
//Will return false if there was an error generated during the sleep cycle
//Increments currentSleepCycle after a rest
bool Instance::Sleep(){

	sleeper.Rest();
	currentSleepCycle ++;
	
	return true;
}

//The function we will go to when we are awake and we want to perform out actions
//before we go back to sleep.
bool Instance::PerformActions(double sleepCycle){
	//Logic here that will determine which actions to perform based on the value of the current time
	//Actions to perform:
	//Check for user input
	//Poll IC if running
	//Talk to LEDs
	//Talk to screen
	double meterReading 0;
	
	if(sleepCycle % readUserInputInterval == 0){
		HandleButtonPresses();	//Read user input, such as restart, start, timer, etc.
	}
	if(sleepCycle % readkMeteringInputInterval == 0) {
		meterReading = ReadInstantaneousPowerFromMeter();	//Read metering input
	}
	if(sleepCycle % talkLEDInterval == 0) {
		//Display the current power being produced to the LEDs
		
	}
	if(sleepCycle % talkScreenInterval == 0) {
		//Print the new screen on the memory LCD
	}

	return true;
}

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

//Thus function will start a new instance, resetting the timer, sleep cycle, clearing the screen,
//Possibly flashing the LEDs?
bool Instance::StartNewInstance() {
	//This function will clear the state of the machine, such as time, sleep cycle,
	//clear the screen and reset the timer, and clear the cache on the metering circuit,
	//perhaps even flash the LEDs to indicate that there is a new state.
	
	currentTime = 0;
	currentSleepCycle = 0;
	state = OFF;
}
