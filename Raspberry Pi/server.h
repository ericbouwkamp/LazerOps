/*
/	File: server.h
/	Written By: Eric Bouwkamp
/ 	Last Modified: May 12, 2014
/	Calvin College Engineering Department
/	Senior Design 2013-2014
/	Team 11: Lazer-Ops
/ 	Advised By: Professor Steven VanderLeest
*/

#ifndef SERVER_H
#define SERVER_H

#include "lights.h"
#include "UDP.h"
#include "timer.h"
using namespace std;

// Game Variables
#define MAX_PLAYERS 4

// Identifiers
#define ANDROID_IDENT 1
#define GUNVEST_IDENT 2
#define WINDOWS_IDENT 3
#define BASEST_IDENT 4

// Gun Vest Commands
#define ADD_PLYR 1
#define SET_SHOTS 2
#define SET_HITS 3
#define SET_AMMO 4

// Android Commands
#define GET_PLYR_NUM 1
#define GET_REM_TIME 2
#define GET_TEAM_SCORE 3
#define GET_PLYR_STATS 4

// Base Station Commands
#define SET_GLB_DEBUG 1
#define SET_UDP_DEBUG 2
#define SET_I2C_DEBUG 3

// Windows Commands
#define START_GAME 1
#define STOP_GAME 2
#define GET_TEAM_SCORE 3
#define GET_PLYR_STATS 4
#define GET_WREM_TIME 5
#define SET_GAME_TIME 6
#define RESET_STATS 7


// Defines Server Class.
class Server
{
	private:
		void parseData(unsigned int commandVal, unsigned int dataVal);
		void printCommand(unsigned int commandVal, unsigned int dataVal, int cmdIdent, int command, int plyrID, int devType, int expBits);
		void runAndroidCommand(int command, int plyrID, unsigned int commandVal, unsigned int dataValue);
		void runGVCommand(int command, int plyrID, unsigned int commandVal, unsigned int dataValue);
		void runBaseStationCommand(int command, int plyrID, unsigned int commandVal, unsigned int dataValue);
		void runWindowsCommand(int command, int plyrID, unsigned int commandVal, unsigned int dataValue);
			
	public:
		Server(void);
		~Server(void);
		void run(void);
};

// Defines teamStruct which holds data for the individual teams
struct teamStruct
{
	unsigned int teamScore;
	
	teamStruct()
	{
		teamScore = 0;
	}
};

// Defines gameStruct which holds data for the game environment
struct gameStruct
{
	bool playing;
	unsigned int playerCount;
	unsigned int teamCount;
	unsigned int gameDuration;
	
	gameStruct()
	{
		playing = false;
		playerCount = 0;
		teamCount = 2;
		gameDuration = 900;
	}
};

// Defines playerStruct which holds data for each individual player
struct playerStruct
{
	bool valid;
	unsigned int score;
	unsigned int shots;
	unsigned int hits;
	unsigned int ammo;
	double accuracy;
	
	playerStruct()
	{
		valid = false;
		score = 0;
		shots = 0;
		hits = 0;
		ammo = 0;
	}
};
	

#endif


