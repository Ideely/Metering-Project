/*Title: Bargraph.cpp
* Authors: Clark Asher
* Group: The A Team
* For: Senior Design - Metering Project
* Date: 2/18/2015
* Functions for running bargraph
*
*/


int Bargraph::ConvertPower(int power, maxPow)
{

	int x;
	x = power/maxPow;

	if (x > 10)
		return 10;
	else
		return x;
}


bool Bargraph::LEDwrite( int value)
{
	unsigned int y;
	int i;
	
	if(x>0)     	//makes sure LEDs are off with no input
	bitSet(y,x-1);
	else
	return 0;

	/*  pin sets
	int latchPin = 8;  //Pin connected to ST_CP of 74HC595
	
	int clockPin = 12; //Pin connected to SH_CP of 74HC595
	
	int dataPin = 11;  //Pin connected to SH_CP of 74HC595

	void setup() 
	{
  		//set pins to output because they are addressed in the main loop
  		pinMode(latchPin, OUTPUT);
 		pinMode(clockPin, OUTPUT);
 	 	pinMode(dataPin, OUTPUT);
	}

	*/
	
	for(i=x; x<0 ; x--) //writes data to registers and outputs
	{
		digitalWrite(latchPin, HIGH); //disable register  || output

		shitfOut(datapin, clockpin, MSBFIRST, highByte(y)); 
				
		shitfOut(datapin, clockpin, MSBFIRST, lowByte(y));

		digitalWrite(latchPin, LOW); //enable register || ouput

		y >>= 1;
		delay(100);
	}

	return 1;  //returns that write operations were successful
}