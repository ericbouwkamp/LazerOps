/*
/	File: I2C.h
/	Written By: Eric Bouwkamp
/ 	Last Modified: May 12, 2014
/	Calvin College Engineering Department
/	Senior Design 2013-2014
/	Team 11: Lazer-Ops
/ 	Advised By: Professor Steven VanderLeest
*/

#ifndef I2CCLASS_H
#define I2CCLASS_H

#include "lazerOps.h"
#include <iostream>
#include <stdlib.h>
#include <wiringPiI2C.h>
using namespace std;

// Define I2C Class and its Variables
class I2C
{
	private:
		int MAX6955_ADDR1;
		int MAX6955_ADDR2;
		int devHandle1;
		int devHandle2;
		int setupDevice(void);
	public:
		I2C(void);
		~I2C(void);
		int initialize(void);
		void deinitialize(void);
		int write(int device, int addr, int data);
		int read(int device, int addr);
};

#endif

