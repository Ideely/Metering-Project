/*Title: LED.cpp
* Authors: Clark Asher, Larkin Crain
* Group: The A Team
* For: Senior Design - Metering Project
* Date: 2/18/2015
* Functions for running the LEDs
*
*/

//Constructor
LED::LED(int ledDataPin, ledLatchPin, ledClockPin)
{
		PIN_DATA = ledDataPin;
		PIN_LATCH = ledLatchPin;
		PIN_CLOCK = ledClockPin;
}

//Convert the power to a value between 0 and 10
int LED::ConvertPower(int power, maxPow)
{
	int convertedPower;
	convertedPower = power/maxPow;

	if (x > 10)
		return 10;
	else
		return convertedPower;
}

//Write a value to the LED array
bool LED::LEDwrite(int value)
{
	unsigned int y;
	int i;
	
	if(x>0)     	//makes sure LEDs are off with no input
		bitSet(y,x-1);
	else
		return 0;

	
	for(i=x; x<0 ; x--) //writes data to registers and outputs
	{
		digitalWrite(PIN_LATCH, HIGH); //disable register  || output
		shitfOut(PIN_DATA, PIN_CLOCK, MSBFIRST, highByte(y)); 
		shitfOut(PIN_DATA, PIN_CLOCK, MSBFIRST, lowByte(y));
		digitalWrite(PIN_LATCH, LOW); //enable register || ouput

		y >>= 1;
		delay(100);
	}

	return true;  //returns that write operations were successful
}