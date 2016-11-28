/*
/	File: lights.cpp
/	Written By: Eric Bouwkamp
/ 	Last Modified: May 12, 2014
/	Calvin College Engineering Department
/	Senior Design 2013-2014
/	Team 11: Lazer-Ops
/ 	Advised By: Professor Steven VanderLeest
*/

#include "lights.h"
using namespace std;

extern statusStruct status;

// Instantiate I2C Class to drive Lights
I2C i2cService;

// Decodes information for desired digit. decoder[desiredDigit] = neededRegisterValue
unsigned int decoder[10] = {0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B};

// Lights Constructor
lights::lights(void)
{
	
}

// Lights Destructor
lights::~lights(void){
}

// lights::initialize() Initializes the light class.
void lights::initialize(void){
	PutMsg("Now Initializing Lights:");
	
	// Initialize I2C Service.
	i2cService.initialize();
	
	// Set Registers for Desired Device Response
	setRegisters();
	
	// Test Lights
	testLights();
	
	// Set Score and Clock Initial States
	setScore1(0);
	setScore2(0);
	setClock(900);
	
}

// lights::setRegisters() sets the registers in each I2C Device to proper values for
// driving 16 7-segment displays at once. 
int lights::setRegisters(void){	
	int error = 1;
	while (1)
	{
		// MAX6955 Device 1
		if (i2cService.write(IC1,REG_DECODE_MODE,0x00)) break;
		if (i2cService.write(IC1,REG_GLOBAL_INTENSE,0x07)) break;
		if (i2cService.write(IC1,REG_SCAN_LIM,0x07)) break;
		if (i2cService.write(IC1,REG_CONFIG,0x21)) break;
		if (i2cService.write(IC1,REG_GPIO_DATA,0xff)) break;
		if (i2cService.write(IC1,REG_PORT_CONFIG,0x00)) break;
		
		// MAX6955 Device 2
		if (i2cService.write(IC2,REG_DECODE_MODE,0x00)) break;
		if (i2cService.write(IC2,REG_GLOBAL_INTENSE,0x07)) break;
		if (i2cService.write(IC2,REG_SCAN_LIM,0x07)) break;
		if (i2cService.write(IC2,REG_CONFIG,0x21)) break;
		if (i2cService.write(IC2,REG_GPIO_DATA,0xff)) break;
		if (i2cService.write(IC2,REG_PORT_CONFIG,0x00)) break;

		// Initialize Value Registers
		for (int i = 0x60; i < 0x68; i++)
		{
			i2cService.write(IC1,i,0x00);
			i2cService.write(IC2,i,0x00);
		}
		
		error = 0;
		break;
	}	
	if (error == 0)
		PutMsg(" Done\n");
	else
		PutMsg(" Error\n");
		
	return error;
}


// lights::testLights() tests the front lights.
// This includes running from 0 to 9 on each segment, along with flashing each status LED.
void lights::testLights(void){

	for (int i = DIG1SEG0; i <= DIG2SEG3; i++)
	{
		for (int j = 0; j < 10 ; j++)
		{
			i2cService.write(IC1,i,decoder[j]);
			usleep(100000);
		}
	}
	for (int i = DIG3SEG0; i <= DIG3SEG3; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			i2cService.write(IC2,i,decoder[j]);
			usleep(100000);			
		}
	}
	
	setLED1(true);
	usleep(400000);
	
	setLED1(false);
	usleep(400000);
	
	setLED2(true);
	usleep(400000);
	
	setLED2(false);
	usleep(400000);	

	setBLK(true);
	usleep(400000);
	
	setBLK(false);
	usleep(400000);	
	
	setLED1(true);
	usleep(400000);
	setLED2(true);
	usleep(400000);
	setBLK(true);
	usleep(400000);
	setLED1(false);
	usleep(400000);
	setLED2(false);
	usleep(400000);
	setBLK(false);
	usleep(400000);	
	
}

// lights::setLED1() will set the LED on or off according to bool onoff. 
// This function reads the existing value in the GPIO register, masks it 
// to turn the desired LED on or off, and writes the value back to the
// GPIO register.
void lights::setLED1(bool onoff){
	unsigned originalValue = 0;
	unsigned int newValue = 0;
	
	originalValue = i2cService.read(IC1,0x05);
	newValue = ~originalValue;
	if (onoff)
		newValue = (newValue | LED1ONMASK);
	else
		newValue = (newValue & LED1OFFMASK);
	newValue = ~newValue;
	i2cService.write(IC1,0x05,newValue);
}

// lights::setLED2() will set the LED on or off according to bool onoff. 
// This function reads the existing value in the GPIO register, masks it 
// to turn the desired LED on or off, and writes the value back to the
// GPIO register.
void lights::setLED2(bool onoff){
	unsigned originalValue = 0;
	unsigned int newValue = 0;
	
	originalValue = i2cService.read(IC1,0x05);
	newValue = ~originalValue;
	if (onoff)
		newValue = (newValue | LED2ONMASK);
	else
		newValue = (newValue & LED2OFFMASK);
	newValue = ~newValue;
	i2cService.write(IC1,0x05,newValue);
}

// lights::setBLK() will set the Clock Blinker on or off according to bool onoff. 
// This function reads the existing value in the GPIO register, masks it 
// to turn the desired Clock Blinker on or off, and writes the value back to the
// GPIO register.
void lights::setBLK(bool onoff){
	unsigned originalValue = 0;
	unsigned int newValue = 0;
	
	originalValue = i2cService.read(IC1,0x05);
	newValue = ~originalValue;
	if (onoff)
		newValue = (newValue | BLKONMASK);
	else
		newValue = (newValue & BLKOFFMASK);
	newValue = ~newValue;
	i2cService.write(IC1,0x05,newValue);
}

// lights::setScore1() can be passed an integer. This function will decode the
// value and set the appropriate register to drive the display.
void lights::setScore1(int score){
	char myScore[4];
	int setScore = 0;
	if (score > 9999)
		setScore = 9999;
	else if (score < 0)
		setScore = 0;
	else
		setScore = score;
		
	sprintf(myScore,"%04d",setScore);
	
	i2cService.write(IC1,DIG1SEG0,decoder[(int)myScore[0] - 48]);
	i2cService.write(IC1,DIG1SEG1,decoder[(int)myScore[1] - 48]);
	i2cService.write(IC1,DIG1SEG2,decoder[(int)myScore[2] - 48]);
	i2cService.write(IC1,DIG1SEG3,decoder[(int)myScore[3] - 48]);	
}

// lights::setScore2() can be passed an integer. This function will decode the
// value and set the appropriate register to drive the display.
void lights::setScore2(int score){
	char myScore[4];
	int setScore = 0;
	if (score > 9999)
		setScore = 9999;
	else if (score < 0)
		setScore = 0;
	else
		setScore = score;
		
	sprintf(myScore,"%04d",setScore);
	
	i2cService.write(IC2,DIG3SEG0,decoder[(int)myScore[0] - 48]);
	i2cService.write(IC2,DIG3SEG1,decoder[(int)myScore[1] - 48]);
	i2cService.write(IC2,DIG3SEG2,decoder[(int)myScore[2] - 48]);
	i2cService.write(IC2,DIG3SEG3,decoder[(int)myScore[3] - 48]);	
}

// lights::setScore1() can be passed a time in seconds. This function will decode the
// value and set the appropriate register to drive the clock display.
void lights::setClock(int time){
	static bool previousBlink = false;
	char myTime[4];
	int minutes;
	int seconds;
	
	minutes = time / 60;
	seconds = time % 60;
	
	sprintf(myTime,"%02d%02d",minutes,seconds);
	
	if (previousBlink)
	{
		setBLK(false);
		previousBlink = false;
	}
	else
	{
		setBLK(true);
		previousBlink = true;
	}
	
	i2cService.write(IC1,DIG2SEG0,decoder[(int)myTime[0] - 48]);
	i2cService.write(IC1,DIG2SEG1,decoder[(int)myTime[1] - 48]);
	i2cService.write(IC1,DIG2SEG2,decoder[(int)myTime[2] - 48]);
	i2cService.write(IC1,DIG2SEG3,decoder[(int)myTime[3] - 48]);		
}

// lights::putMsg() for debug purposes.
void lights::PutMsg(string message){
	if (status.i2cDebug)
		cout << message;
}