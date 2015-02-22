/*
* Title: UserInput.cpp
* Author: Larkin Crain
* Group: The A Team
* For: Senior Design - Metering Project
* Date: 2/12/2015
*
* Description: This is a class definition of the UserInput library that will ne in charge of handling user input.
* So far, it will check for the user pressing the start button and the power button but more buttons can be added.
*	
* Function List:
* Constructor: 		Initializes any settings
* CheckPower: 		Check to see if we have pressed the button long enough to shutdown
* CheckStart:		Check to see if we have pressed the start button long enough to restart and return to initial state
*
* 
*/

UserInput::UserInput(int powerpin, int startpin){
	//Initialize any settings
	
	//Set user input pins
	powerPin = powerpin;
	startPin = startpin
	
}

bool UserInput::checkPowerButton() {
	//If we have pressed the button long enough to warrant turning off, then turn off

	if(powerButtonCount >= powerButtonThreshold)
		return true;
	else
		return false;
}

bool UserInput::CheckRestartButton() {
	//If we have pressed the start button long enough to return to a home setting
	if(startButtonCount == startButtonThreshold)
		return true;
	else
		return false;
}

