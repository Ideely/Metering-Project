/*
* Title: UserInput.h
* Author: Larkin Crain
* Group: The A Team
* For: Senior Design - Metering Project
* Date: 2/12/2015
*
* This library will wrap all functions relating to getting input from the user.
* This includes button presses, switches, or any other form. 
*	
* Function List:
* Constructor: 		Initializes any settings
* 
*/

//Prevents issues with accidental double linking
#ifndef UserInput_h
#define UserInput_h

class UserInput
{
	public:
		UserInput(int powerpin, int startpin);			//Initialize the Sleep object.
		
		bool checkPowerButton();			//Check to see if the powerButtonCount has reached the threshold
		bool CheckRestartButton();		//Check to see if the startButtonCount has reached the threshold
		
	private:
		bool PollPowerButton();		//Check to see if the power button is pressed
		bool PollStartButton();		//Check to see if the start button is pressed
	
		int powerButtonCount;		//How long the power button has been pressed
		int startButtonCount;		//How long the start button has been pressed
		
		const int powerButtonThreshold = 7;		//Once the count hits this threshold, turn off
		const int startButtonThreshold = 5;		//Once the count hits this threshold, restart
		
		//TO DO: These should be changed to pins rather than integers
		int powerPin = -1;				//Location of the pin where the power button is connected
		int startPin = -1;				//Location of the pin where the start button is connected
}
