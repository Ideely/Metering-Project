/*
* Title: Metering.h
* Authors: Larkin Crain
* Group: The A Team
* For: Senior Design - Metering Project
* Date: 2/12/2015
*
* This library will wrap the ADE7753 library, and will provide easy functions to
* read the instantaneous power, to read the total energy developed, to reset the 
* cache.
*	
* Function List:
* Constructor: 				Initializes any settings.
* ReadInstantaneousPower: 	Read the instantaneous power.
* ReadTotalEnergy:			Read the total energy developed.
* Reset:					Reset the device, clearing cache.
*/

//Prevents issues with accidental double linking
#ifndef Metering_h
#define Metering_h

#include "ADE7753.h"

class Metering
{
	public:
		Metering( 
			int dataIn,
			int dataOut,
			int clockSync,
			int reset
		);			//Initialize the Meter object.
		
		double ReadInstantaneousPower();	//Read the power being measured at that moment.
		double ReadTotalEnergy();			//Read the total power developed up to this point.
		
		bool Reset();						//Reset the device and the device cache.

	private:
		int pinDataIn;
		int pinDataOut;
		int pinClockSync;
		int pinReset;
		
		ADE7753 meteringCircuit;
		
}