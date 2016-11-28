/*
/	File: lights.cpp
/	Written By: Eric Bouwkamp
/ 	Last Modified: May 12, 2014
/	Calvin College Engineering Department
/	Senior Design 2013-2014
/	Team 11: Lazer-Ops
/ 	Advised By: Professor Steven VanderLeest
*/

#ifndef LIGHTS_H
#define LIGHTS_H

#include "I2C.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

// Configuration Registers on the MAX6955 Device
#define REG_DECODE_MODE 	0x01
#define REG_GLOBAL_INTENSE 	0x02
#define REG_SCAN_LIM	 	0x03
#define REG_CONFIG	 		0x04
#define REG_GPIO_DATA		0x05
#define REG_PORT_CONFIG		0x06
#define REG_DISP_TEST 		0x07

// Constants for 2 I2C Devices
#define IC1					1
#define IC2					2

// Register Addresses for different Central Hub Digits
#define DIG1SEG0			0x68
#define DIG1SEG1			0x69
#define DIG1SEG2			0x6A
#define DIG1SEG3			0x6B
#define DIG2SEG0			0x6C
#define DIG2SEG1			0x6D
#define DIG2SEG2			0x6E
#define DIG2SEG3			0x6F
#define DIG3SEG0			0x68
#define DIG3SEG1			0x69
#define DIG3SEG2			0x6A
#define DIG3SEG3			0x6B

// BitMasks for Front Status LEDs.
#define LED1ONMASK			0x04
#define LED2ONMASK			0x02
#define BLKONMASK			0x08
#define LED1OFFMASK			0x1B
#define LED2OFFMASK			0x1D
#define BLKOFFMASK			0x17


// Lights Class Definition
class lights
{
	private:
		int setRegisters(void);
		void PutMsg(string message);
		void testLights(void);
	public:
		lights(void);
		~lights(void);
		void initialize(void);
		void setLED1(bool onoff);
		void setLED2(bool onoff);
		void setBLK(bool onoff);
		void setScore1(int score);
		void setScore2(int score);
		void setClock(int time);
};

#endif
