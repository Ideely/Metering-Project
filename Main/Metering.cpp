/*
* Title: Metering.cpp
* Authors: Larkin Crain
* Group: The A Team
* For: Senior Design - Metering Project
* Date: 2/12/2015
*
* This library will wrap the ADE7753 library, and will provide easy functions to
* read the instantaneous power, to read the total energy developed, to reset the 
* cache.
*	
* Primary functions of this library are to read the total power developed 
* and to read the current instantaneous power at the current moment. The
* library will also have a method for resetting the device.
*/

Metering::Metering(			
			int dataIn,
			int dataOut,
			int clockSync,
			int reset) 
{
	//The constructor, initialize any initial settings that we may need to.
	pinDataIn = dataIn;
	pinDataOut = dataOut;
	
	meteringCircuit()
	
}

double Metering::ReadInstantaneousPower(){
	//Return the current power being produced at this moment
	
	return (meteringCircuit.irms() * meteringCircuit.vrms());
}

double Metering::ReadTotalEnergy() {
	//Return the total energy produced up to this moment
	
	return meteringCircuit.getActiveEnergyLineSync();
}

bool Metering::Reset() {
	//Return true if clearing the cache worked fine. Otherwise, return false.
}

