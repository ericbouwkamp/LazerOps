/*
/	File: lazerOps.cpp
/	Written By: Eric Bouwkamp
/ 	Last Modified: May 12, 2014
/	Calvin College Engineering Department
/	Senior Design 2013-2014
/	Team 11: Lazer-Ops
/ 	Advised By: Professor Steven VanderLeest
*/
#include "lazerOps.h"
statusStruct status;
using namespace std;


// main() function parses commandLine and then starts the Central Hub Server.
int main(int argc, const char* argv[]){
	parseCmdLine(argc,argv);
	Server server;
	server.run();
}

// parseCmdLine() parses the command line for debug variables
void parseCmdLine(int argc, const char* argv[]){

	for (int i = 0; i < argc; i++)
	{
		if (strcmp(argv[i],"-udp") == 0)
			status.udpDebug = true;
		if (strcmp(argv[i],"-i2c") == 0)
			status.i2cDebug = true;			
		if (strcmp(argv[i],"-glb") == 0)
		{
			status.glbDebug = true;
			status.udpDebug = true;			
			status.i2cDebug = true;
		}
	}	
}
