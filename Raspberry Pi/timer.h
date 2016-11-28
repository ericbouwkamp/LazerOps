/*
/	File: timer.h
/	Written By: Eric Bouwkamp
/ 	Last Modified: May 12, 2014
/	Calvin College Engineering Department
/	Senior Design 2013-2014
/	Team 11: Lazer-Ops
/ 	Advised By: Professor Steven VanderLeest
*/
#ifndef TIMER_H
#define TIMER_H
#include <stdio.h>
#include <time.h>
#include <iostream> 
using namespace std;

// Defines Timer Class
class Timer
{
	private:
		unsigned int startTime;
		unsigned int endTime;
		bool running;
		time_t timer;
	public:
		Timer(void);
		~Timer(void);
		void start(int minutes, int seconds);
		bool checkTime(unsigned int *seconds);
		void stop(void);
};

#endif