/*
/	File: server.cpp
/	Written By: Eric Bouwkamp
/ 	Last Modified: May 12, 2014
/	Calvin College Engineering Department
/	Senior Design 2013-2014
/	Team 11: Lazer-Ops
/ 	Advised By: Professor Steven VanderLeest
*/

#include "server.h"
using namespace std;
extern statusStruct status;

// Ininitalize lightService, udpService, and gameTimer.
lights lightService;
UDP udpService;
Timer gameTimer;

// Define Server Structures for gameplay
struct teamStruct teamData[2];
struct gameStruct gameData;
struct playerStruct playerData[20];

// server constructor initializes udpService and lightService.
Server::Server(void){
	udpService.initialize();
	lightService.initialize();
}

// server destructor
Server::~Server(void){
	
}

// Server::run() starts the server starts receiving and interpreting data.
void Server::run(void){

	// Received Data is set from the udp Server. 
	unsigned int receivedData[2] = {0,0};
	
	// Static Variables to keep track of previous values. Used to only
	// change display if new value is found.
	static unsigned int previousTime = 0;
	static unsigned int previousScore0 = 0;
	static unsigned int previousScore1 = 0;
	unsigned int timeVal; 
	
	// Set LED1 to on to indicate server is running
	lightService.setLED1(true);
	while (1)
	{
		// If game is in session, update the display
		if (gameData.playing)
		{
			// get current gameTimer time
			gameTimer.checkTime(&timeVal);
			
			// If no time is left, set playing to false
			if (timeVal == 0)
				gameData.playing = false;
				
			// If a new time is found different from the previous time, set the display
			if (timeVal != previousTime)
			{
				lightService.setClock(timeVal);
				previousTime = timeVal;
			}
			
			// if team 1's score has been increased, update the display
			if (teamData[0].teamScore != previousScore0)
			{
				lightService.setScore1(teamData[0].teamScore);
				previousScore0 = teamData[0].teamScore;
			}
				
			// if team 2's score has been increased, update the display 
			if (teamData[1].teamScore != previousScore1)
			{
				lightService.setScore2(teamData[1].teamScore);
				previousScore1 = teamData[1].teamScore;
			}			
		}
		
		// if the udpService receives 8 bytes from a client, run the command
		if (udpService.receive(receivedData) == 8)
		{
			// Set LED2 on to indicate that it is running the command
			lightService.setLED2(true);
			
			// Run Command
			parseData(receivedData[0], receivedData[1]);
			
			// Set LED2 off to indicated command has completed running
			lightService.setLED2(false);
		}
	}
	
	// If server has halted, set LED1 to false to indicate it is not running
	lightService.setLED1(false);
}

// Server::parseData() receives the command and data to determine which command to run.
// Identifies command structure by the cmdIdent sent in the command
void Server::parseData(unsigned int commandVal, unsigned int dataVal){
	int command, cmdIdent, plyrID, devType, expBits;
	command = (commandVal & 0x000000FF);
	cmdIdent = (commandVal & 0x00000F00) >> 8;
	plyrID = (commandVal & 0x003FF000) >> 12;
	devType = (commandVal & 0x07C00000) >> 22;
	expBits = (commandVal & 0xF8000000) >> 27;
	
	if (status.udpDebug)
		printCommand(command, dataVal, cmdIdent, command, plyrID, devType, expBits);
		
	switch (cmdIdent)
	{
		case ANDROID_IDENT:
			runAndroidCommand(command,plyrID, commandVal, dataVal);
			break;
		case GUNVEST_IDENT:
			runGVCommand(command,plyrID,commandVal, dataVal);
			break; 
		case WINDOWS_IDENT:
			runWindowsCommand(command,plyrID,commandVal, dataVal);
			break;
		case BASEST_IDENT:
			runBaseStationCommand(command,plyrID,commandVal, dataVal);
			break;
		default:
			if (status.udpDebug)
				cout << "Incorrect Command Identifier Received" << endl;
			break;	
	}
	cout << flush;
}

// Server::runAndroidCommand() runs when the command parser finds a command with the Android Command Identifier
void Server::runAndroidCommand(int command, int plyrID, unsigned int commandVal, unsigned int dataValue){
	cout << "AA CMD, ";
	switch (command)
	{
		case GET_PLYR_NUM:
		{
			udpService.send(commandVal,gameData.playerCount);
			cout << "Sent Player Count : " << gameData.playerCount << endl;		
			break;
		}
		
		case GET_REM_TIME:
		{
			unsigned int time;
			gameTimer.checkTime(&time);
			udpService.send(commandVal,time);
			cout << "Sent Remaining Time : " << time << endl;	
			break;
		}
		case GET_TEAM_SCORE:
		{
			int teamID = (plyrID & 0x300) >> 8;
			udpService.send(commandVal, teamData[teamID].teamScore);
			cout << "Sent Team Score " << teamID << " : " << teamData[teamID].teamScore << endl;
			break;
		}
		
		case GET_PLYR_STATS:
		{
			unsigned int data = 0;
			unsigned int playerID = (plyrID & 0xFF);
			cout << "Get Player Stats " << playerID << endl << flush;
			data |= (playerData[playerID].shots & 0x7FF) << 21;
			data |= (playerData[playerID].hits & 0x7FF) << 10;
			data |= (playerData[playerID].ammo & 0x3FF);
			cout << "Data Sent " << data << endl;
			udpService.send(commandVal,data);
			break;
		}
		
		default:
			cout << "Invalid CMD" << endl;
			break;
	}

}

// Server::runGVCommand() runs when the command parser finds a command with the Gun/Vest Command Identifier
void Server::runGVCommand(int command, int plyrID, unsigned int commandVal, unsigned int dataValue){
	cout << "GV CMD, ";
	unsigned int playerID = (plyrID & 0xFF);
	switch (command)
	{
		case ADD_PLYR:
			// Add Player
			
			if (playerData[plyrID].valid)
			{
				cout << "Player " << plyrID << " Already Initialized. Resetting Statistics " << endl;
				playerData[playerID].score = 0;
				playerData[playerID].shots = 0;
				playerData[playerID].hits = 0;
				playerData[playerID].ammo = 0;
			}
			else
			{
				cout << "Player " << playerID << " Initialized" << endl;
				playerData[playerID].score = 0;
				playerData[playerID].shots = 0;
				playerData[playerID].hits = 0;
				playerData[playerID].ammo = 0;	
				gameData.playerCount++;
			}
			break;
			
		case SET_SHOTS:
			if (gameData.playing)
			{
				cout << "Set Shots Fired for player " << playerID << " : " << dataValue << endl;
				playerData[playerID].shots = dataValue;
			}
			else{
				cout << "Set Shots Fired for player " << playerID << " : " << dataValue << ", Game Not Running" <<  endl;
			}
			break;
			
		case SET_HITS:
			if (gameData.playing){
				cout << "Set Hit Count for player " << playerID << " : " << dataValue << endl;
				if (playerID == 0)
				{
					playerData[1].hits = dataValue;				
					teamData[1].teamScore = (dataValue * 5);
				}
				else if (playerID == 1)
				{
					playerData[0].hits = dataValue;				
					teamData[0].teamScore = (dataValue * 5);					
				}
			}
			else{
				cout << "Set Hit Count for player " << playerID << " : " << dataValue << ", Game Not Running" <<  endl;
			}
			break;
			
		case SET_AMMO:
			if (gameData.playing){
				cout << "Set Ammo Count for player " << playerID << " : " << dataValue << endl;
				playerData[playerID].ammo = dataValue;
			}
			else{
				cout << "Set Ammo Count for player " << playerID << " : " << dataValue << ", Game Not Running" <<  endl;			
			}
			break;
		default:
			cout << "Invalid Command Found" << endl;
			break;
	}
}

// Server::runBaseStationCommand() runs when the command parser finds a command with the Base Station Command Identifier
void Server::runBaseStationCommand(int command, int plyrID, unsigned int commandVal, unsigned int dataValue){	
	cout << "BS CMD, ";
	switch (command)
	{
		case SET_GLB_DEBUG:
			cout << "glb dbg: " << dataValue << endl;
			
			if (dataValue == 1)
			{
				status.udpDebug = true;
				status.i2cDebug = true;
				status.glbDebug = true;
			}
			else
				status.glbDebug = false;
			break;
			
		case SET_UDP_DEBUG:
			cout << "udp dbg: " << dataValue << endl;
			
			if (dataValue == 1)
				status.udpDebug = true;
			else
				status.udpDebug = false;
			break;
			
		case SET_I2C_DEBUG:
			cout << "i2c dbg: " << dataValue << endl;
			
			if (dataValue == 1)
				status.i2cDebug = true;
			else	
				status.i2cDebug = false;
			break;
			
		default:
		
			cout << "Invalid CMD" << endl;
			break;
	}
		

}

// Server::runWindowsCommand() runs when the command parser finds a command with the Windows Command Identifier
void Server::runWindowsCommand(int command, int plyrID, unsigned int commandVal, unsigned int dataValue){
	cout << "WIN CMD, ";
	unsigned int playerID = (plyrID & 0xFF);
	switch(command)
	{
		case START_GAME:
		{
			if (gameData.playing == false)
			{
				gameData.playing = true;
				gameTimer.start((gameData.gameDuration / 60),(gameData.gameDuration % 60));
				lightService.setLED2(true);
				cout << "Starting Game " << endl;
			}
			else
			{
				cout << "Game Already Running " << endl;
			}
			break;
		}
		
		case STOP_GAME:
		{
			if (gameData.playing == true)
			{
				gameData.playing = false;
				gameTimer.stop();
				lightService.setLED2(false);
				cout << "Stopping Game " << endl;
			}
			else
			{
				cout << "Game Already Stopped " << endl;
			}
			break;
		}	
		
		case GET_TEAM_SCORE:
		{
			int teamID = (plyrID & 0x300) >> 8;
			udpService.send(commandVal, teamData[teamID].teamScore);
			cout << "Sent Team Score " << teamID << " : " << teamData[teamID].teamScore << endl;
			break;
		}

		case GET_PLYR_STATS:
		{
			unsigned int data = 0;
			data |= (playerData[playerID].shots & 0x7FF) << 21;
			data |= (playerData[playerID].hits & 0x7FF) << 10;
			data |= (playerData[playerID].ammo & 0x3FF);
			udpService.send(commandVal,data);
			cout << "Get Player Stats " << playerID << endl;		
			break;
		}
	
		case GET_WREM_TIME:
		{
			unsigned int time;
			gameTimer.checkTime(&time);
			udpService.send(commandVal,time);
			cout << "Sent Remaining Time : " << time << endl;	
			break;
		}
		
		case SET_GAME_TIME:
		{
			if (gameData.playing)
			{
				cout << "Setting Game Duration: Error. Cannot Set While Game is Playing" << endl;
			}
			else
			{
				cout << "Setting Game Duration to " << dataValue << " seconds" << endl;
				gameData.gameDuration = dataValue;
				lightService.setClock(dataValue);
			}
			break;
		}	
		
		case RESET_STATS:
		{
			if (gameData.playing)
			{
				cout << "Reset Statistics Failed: Game In Session" << endl;
			}
			else
			{
				for (int i = 0; i < 2; i++)
				{
					teamData[i].teamScore = 0;
				}
				
				for (int i = 0; i < 20; i++)
				{
					playerData[i].shots = 0;
					playerData[i].hits = 0;
					playerData[i].ammo = 0;
				}
				
				gameData.playing = false;				
				gameTimer.stop();
			}
		}
		
		default:
		{
			cout << "Invalid CMD" << endl;
			break;
		}
	}
}

// Server::printCommand() prints the command to the console for debugging purposes
void Server::printCommand(unsigned int commandVal, unsigned int dataVal, int cmdIdent, int command, int plyrID, int devType, int expBits){
	static bool firstRun = true;
	char cmdString[200] = "";
	int playerID = (plyrID & 0xFF);
	
	if (firstRun)
	{
		cout << "\n| Command Value |   Data Value  | Command Ident | Command | PlayerID | Device Type | Expansion |" << endl;
		cout <<   "| -------------------------------------------------------------------------------------------- |" << endl;
		firstRun = false;
	}
	sprintf(cmdString,"|   %10u  |   %10u  |       %2i      |   %3i   |   %4i   |      %2i     |    %2i     | ", commandVal, dataVal, cmdIdent, command, playerID, devType, expBits);
	cout << cmdString;
}

