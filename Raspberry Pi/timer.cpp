/*
/	File: timer.cpp
/	Written By: Eric Bouwkamp
/ 	Last Modified: May 12, 2014
/	Calvin College Engineering Department
/	Senior Design 2013-2014
/	Team 11: Lazer-Ops
/ 	Advised By: Professor Steven VanderLeest
*/
#include "timer.h"
using namespace std;

// Timer Constructor
Timer::Timer()
{
	running = false;
	startTime = 0;
	endTime = 0;
}

// Timer Destructor
Timer::~Timer(void)
{
	
}

// Timer::start() receives a duration, and determines the start and end times
// for the timer.
void Timer::start(int minutes, int seconds)
{
	int setMinutes;
	int setSeconds;
	if (!running)
	{
		if (minutes > 99)
			setMinutes = 99;
		else
			setMinutes = minutes;
			
		if (seconds > 59)
			setSeconds = 59;
		else
			setSeconds = seconds;
			
		startTime = time(&timer);
		endTime = (startTime + (setMinutes * 60) + setSeconds);
		running = true;
	}
	else
	{
		stop();
		start(minutes,seconds);	
	}
}

// Timer::checkTime() checks the remaining time and sends the amount of seconds left back to the caller
// Returns true if new time is found or no time left
bool Timer::checkTime(unsigned int *seconds)
{
	static unsigned int previousTime = 0;
	unsigned int currentTime = time(&timer);
	if (running)
	{
		if (currentTime <= endTime)
			*seconds = (endTime - currentTime);
		else
			*seconds = 0;
		if (currentTime != previousTime)
		{	
			if (currentTime <= endTime)
			{
				previousTime = currentTime;
				return true;
			}
			else
				return false;
		}
		else
			return false;	
	}
	else
	{
		*seconds = 0;
		return false;
	}
}

// Timer::stop() stops timer and resets variables
void Timer::stop(void)
{
	startTime = 0;
	endTime = 0;
	running = false;
}