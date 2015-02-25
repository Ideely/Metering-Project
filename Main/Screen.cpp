/*
* Title: Screen.cpp
* Authors: Larkin Crain
* Group: The A Team
* For: Senior Design - Metering Project
* Date: 2/12/2015
*
* Library definition for interfacing with the screen that we will use. Currently, this is the 
* Sharp Memory LCD 2.7in.
*
*/

Screen::Screen(int communicationDisp,
			int communicationETX,
			int communicationXTM,
			int communicationSI, 
			int communicationSCS, 
			int communicationSCLK)
{
	//Initialize anything we need to here
		pinDisp = communicationDisp;
		pinETX = communicationETX;
		pinXTM = communicationETM;
		pinSI = communicationSI;
		pinSCS = communicationSCS;
		pinSCLK = communicationSCLK;	
}

bool Screen::Write(char message[]){
	//Will write the the character array message to the screen and will
	//return true if there is no error in the process.
	
	for(int count = 0; count < message; count ++)
	{
		screebObject.write(message[count]);
	}
	
	return true;
}

bool Screen::Clear() {
	//Clears the screen, will return true if there wasn't an error
}

bool Screen::Flash() {
	//Will cause the screen to quickly flash, which will be effected by quickly inverting
	//and un-inverting the screen
}
