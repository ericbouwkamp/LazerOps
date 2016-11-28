/*
/	File: UDP.h
/	Written By: Eric Bouwkamp
/ 	Last Modified: May 12, 2014
/	Calvin College Engineering Department
/	Senior Design 2013-2014
/	Team 11: Lazer-Ops
/ 	Advised By: Professor Steven VanderLeest
*/
#ifndef UDPCLASS_H
#define UDPCLASS_H

#include "lazerOps.h"
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h> // sockaddr_in Structure
#include <fcntl.h>
#include <arpa/inet.h>
#include <stdint.h>
#include <iomanip>
#include <exception>
using namespace std;

// Defines UDP class functions and variables
class UDP
{
	private:
		int socketHandle;
		int UDP_PORT;
		bool socketOpen;
		string IP_ADDR;
		struct sockaddr_in server;
		sockaddr_in lastclient;
		socklen_t addrlen;
		
		int initializeStructure(void);
		int bindToSocket(void);
		int setNonBlocking(void);
		void putMsg(string message);
		void parseReceivedMessage(unsigned int commandValue, int *cmdIdent, int *command, int *plyrID, int *devType, int *expBits);
	public:
		UDP(void);
		~UDP(void);
		
		// Utility
		void initialize(void);
		void deInitialize(void);
		int openSocket(void);
		void closeSocket(void);
		
		// Communication
		int receive(unsigned int *recvBytes);
		int send(unsigned int command, unsigned int data);

};

#endif

