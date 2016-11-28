/*
/	File: I2C.cpp
/	Written By: Eric Bouwkamp
/ 	Last Modified: May 12, 2014
/	Calvin College Engineering Department
/	Senior Design 2013-2014
/	Team 11: Lazer-Ops
/ 	Advised By: Professor Steven VanderLeest
*/

#include "I2C.h"
using namespace std;

extern statusStruct status;

// I2C Constructor Function
// Sets Class Variables to their initial state
I2C::I2C(void){
	MAX6955_ADDR1 = 0x64;
	MAX6955_ADDR2 = 0x60;
	devHandle1 = -1;
	devHandle2 = -1;
}

// I2C Destructor
// Nothing needs to be done here
I2C::~I2C(void){

}

// I2C::initialize() sets up I2C bus to communicate with the two I2C devices.
// Sets up Device Handles
int I2C::initialize(void){
	return setupDevice();
}

// I2C::deinitialize() Closes I2C Device Handles used to communicate with I2C devices.
void I2C::deinitialize(void){

	close(devHandle1);
	close(devHandle2);
}

// I2C::setupDevice() Sets up Device Handles for use while class is in use
int I2C::setupDevice(void){

	devHandle1 = wiringPiI2CSetup(MAX6955_ADDR1);
	devHandle2 = wiringPiI2CSetup(MAX6955_ADDR2);
	
	if ((devHandle1 >= 0) && (devHandle2 >= 0))
		return 0;
	else
		return 1;
}

// I2C::write() writes data to device on I2C bus to a Register at addr.
int I2C::write(int device, int addr, int data){
	if (device == 1)
		return wiringPiI2CWriteReg8(devHandle1,addr,data);
	else if (device == 2)
		return wiringPiI2CWriteReg8(devHandle2,addr,data);
	else
		return 1;
}

// I2C::read() reads the data in a register on an I2C Device
int I2C::read(int device, int addr){
	if (device == 1)
		return wiringPiI2CReadReg8(devHandle1,addr);
	else if (device == 2)
		return wiringPiI2CReadReg8(devHandle2,addr);		
	else return 1;
}