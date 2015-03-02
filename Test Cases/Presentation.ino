/*
* Title: Presentation.ino
* Authors: Larkin Crain and Clark Asher
* Date: 3/2/2015
* Description: The program that the Arduino will run during the presentation to the 
* 	class and to the professor demonstrating that our Arduino can measure an analog
*	input and covert it to a digital representation and display the resulting representation
*	through our LED array in our enclosure.
*
*/

#include <arduino.h>
#include "Instance.h"

//Globals
Instance currentInstance;

//Setup Function
void setup()
{
	Serial.begin(9600);				//Talk back to the computerm, for debugging	
	currentInstance(11, 8, 12, A1);
}

//The main loop
void loop() {
    currentInstance.Sleep();
	currentInstance.PerformActions();
}