/*
* Title: Main.cpp
* Author: Larkin Crain
* Group: The A Team
* For: Senior Design - Metering Project
* Date: 2/12/2015
*
* Hub of the program. Where everything comes together.
*
*/

//Arduino provided libraries
#include "Arduino.h"

//User defined modules
#include "Instance.h"											//Provides an abstracted definition for a metering instance

//Global Variables
Instance currentInstance();	//The current instance object

void Setup() {
	//Setup function, used for initializing variables, setting, classes
	currentInstance.Begin();
}

void loop() {
	//Main Loop
	currentInstance.Sleep();							//Sleep for the interval (30ms)
	currentInstance.PerformActions();	//Perform relevant action
}