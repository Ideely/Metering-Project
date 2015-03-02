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

//Describes the state of the instance
enum InstanceState {
	OFF,				//The instance hasn't stated, getting ready to start
	STARTED,			//The instance is going, computing power, and the timer is counting down
	COMPLETED			//The instance has completed fully. 
};

class Instance {
	public:
		Instance(int ledDataPin, int ledLatchPin, int ledClockPin, int voltageInputPin);
		
		bool Sleep();							//Will put the microprocessor to sleep for 30ms
		bool PerformActions();					//Will perform certain actions depending upon the current clock cycle
		int GetAnalogVoltageInput();			//FOR TESTING ONLY
		
		InstanceState state;					//The current state of the instance
		
	private:
		double currentTimeMillseconds;		//The time on the timer
		double currentSleepCycle;			//The current sleep cycle that the instance is on	
		
		const int readUserInputInterval;		//Check every 5 sleep cycles
		const int readkMeteringInputInterval;	//Check every 3 sleep cycles
		const int talkLEDInterval;				//Talk to them every 2 sleep cycles
		const int talkScreenInterval;			//Talk to it every 2 sleep cycles

		int PIN_LED_DATA;
		int PIN_LED_LATCH;
		int PIN_LED_CLOCK;
		
		int  PIN_VOLTAGE_INPUT;
		
		LEDS leds;
		
		//const int PIN_METER_DATA_IN;
		//const int PIN_METER_DATA_OUT;
		//const int PIN_METER_CLOCK_SYNC;
		//const int PIN_METER_RESET;

		//const int PIN_SCREEN_COMMUNICATION_DSIP;
		//const int PIN_SCREEN_COMMUNICATION_EXTX;
		//const int PIN_SCREEN_COMMUNICATION_EXTM;
		//const int PIN_SCREEN_COMMUNICATION_SI;
		//const int PIN_SCREEN_COMMUNICATION_SCS;
		//const int PIN_SCREEN_COMMUNICATION_SCLK;
}

#endif