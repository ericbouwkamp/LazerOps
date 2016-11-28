/*
/	File: lazerOps.h
/	Written By: Eric Bouwkamp
/ 	Last Modified: May 12, 2014
/	Calvin College Engineering Department
/	Senior Design 2013-2014
/	Team 11: Lazer-Ops
/ 	Advised By: Professor Steven VanderLeest
*/
#ifndef LAZEROPS_H
#define LAZEROPS_H

#include "server.h"
#include "string.h"
using namespace std;

// Prototype for ParseCmdLine function called in main()
void parseCmdLine(int argc, const char* argv[]);

// Global Debug Status Structure
struct statusStruct{
	bool udpDebug;
	bool i2cDebug;
	bool glbDebug;
};

#endif