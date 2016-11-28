/*
/	File: UDP.cpp
/	Written By: Eric Bouwkamp
/ 	Last Modified: May 12, 2014
/	Calvin College Engineering Department
/	Senior Design 2013-2014
/	Team 11: Lazer-Ops
/ 	Advised By: Professor Steven VanderLeest
*/
#include "UDP.h"
extern statusStruct status;

// UDP constructor, sets IP Address and Port.
UDP::UDP(void){
	IP_ADDR = "192.168.1.200";
	UDP_PORT = 5000;
	socketOpen = false;
}

// UDP desctructor
UDP::~UDP(void){
}

// UDP::initialize() Opens the socket, Binds to it, and sets different variables in the socket structure
void UDP::initialize(void){
	
	putMsg("Now Initializing UDP Server\n");
	while (1)
	{
		// Print IP Address
		putMsg("\tIP Address: ");
		putMsg(IP_ADDR);
		
		// Open Socket
		if (openSocket() < 0)
			break;
			
		if (initializeStructure() != 1)
			break;
		
		if (bindToSocket() != 0)
			break;
			
		if (setNonBlocking() != 0)
			break;
		break;
	}
}

// UPD::deInitialize() destructs the socket.
void UDP::deInitialize(void){
	
	putMsg("Shutting Down UDP Server\n");
	closeSocket();
}

// UDP::openSocket() opens the socket for writing. Assigns the socket's handle.
int UDP::openSocket(void){
	// Open Socket and check for Error
	putMsg("\n\tOpening Socket: ");
	socketHandle = socket(AF_INET, SOCK_DGRAM, 0);
	
	if (socketHandle < 0)
		putMsg("Error\n");
	else
	{
		putMsg("Done\n");
		socketOpen = true;
	}
	return socketHandle;
}

// UDP::closeSocket() closes the socket.
void UDP::closeSocket(void){

	if (socketOpen)
	{
		putMsg("\tClosing Socket: ");
		if (close(socketHandle) != 0)
			putMsg("Error\n");
		else
		{
			socketOpen = false;
			putMsg("Done\n");
		}
	}
}

int UDP::initializeStructure(void){	
	int error = -1;
	
	if (socketOpen)
	{	putMsg("\tInitializing Structure: ");
		server.sin_family = AF_INET;
		server.sin_port = htons(5000);
		error = inet_pton(AF_INET, IP_ADDR.c_str(), &server.sin_addr);
		putMsg("Done\n");
	}
	return error;
}

// UDP::bindToSocket() binds the socketHandle to the port and IP address.
int UDP::bindToSocket(void){
	
	int bindResult = -1;	
	
	if (socketOpen)
	{	
		putMsg("\tBinding to Socket: ");
		bindResult = bind(socketHandle, (struct sockaddr*)&server, sizeof(server));
		if (bindResult != 0)
			putMsg("Error\n");	
		else
			putMsg("Done\n");
	}
	return bindResult;
}

// UDP::setNonBlocking() allows the program to continue if no data is received from the server.
int UDP::setNonBlocking(void){
	int result = -1;
	int flags;
	
	if (socketOpen)
	{
		putMsg("\tSet Non-Blocking: ");
		flags = fcntl(socketHandle,F_GETFL);
		flags |= O_NONBLOCK;
		result = fcntl(socketHandle, F_SETFL, flags);
		putMsg("Done\n");
		return result;
	}
	else
	{
		putMsg("UDP::setNonBlocking() : Socket Not Initialized\n");
		return -1;
	}
	
}


// UDP::receive() receives bytes from the socket and places them into a buffer
int UDP::receive(unsigned int *recvBytes){
	
	unsigned int vals[2];
	int received = 0;
	
	if (socketOpen)
	{
		received = recvfrom(socketHandle, &vals, 8, 0, (struct sockaddr *)&lastclient, &addrlen);
		addrlen = sizeof(lastclient);
		recvBytes[0] = ntohl(vals[0]);
		recvBytes[1] = ntohl(vals[1]);
		return received;
	}
	else
	{	
		putMsg("UDP::receive() : Socket Not Initialized\n");
		recvBytes[0] = 0;
		recvBytes[1] = 0;
		return -1;
	}
	
}

// UDP::send() sends command and data to a client on the network
int UDP::send(unsigned int command, unsigned int data){	
	unsigned int vals[2];
	int sent;
	
	if (socketOpen)
	{
		vals[0] = command;
		vals[1] = data;
		sent = sendto(socketHandle, &vals, 8, 0, (struct sockaddr *)&lastclient, addrlen);
		return sent;
	}
	else
	{
		putMsg("UDP::send() : Socket Not Initialized\n");
		return -1;
	}
}

// UDP::putMsg() prints debug messages
void UDP::putMsg(string message){
	if (status.udpDebug)	
		cout << message << flush;
}
