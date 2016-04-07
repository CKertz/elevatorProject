// Elevator Project
// April 2016
// William Munshaw, Cooper Kertz, Amy Curtis
// File: Elevator.h

#pragma once
#include <vector>
#include <string>
#include "User.h"
#include "Header.h"
#include "PriorityQueue.h"
using namespace std;

class Elevator
{
	private:
		int currentFloor;
		prioritize currentPriorities;
		direction currentDirection;
		bool boarding;
		bool arriving;
		bool idle;
	public:
		Elevator() { currentFloor = 1; }
		int getFloor() { return currentFloor; };
		void goUp()
		{
			if (currentFloor < MAXFLOOR)
				currentFloor++;
			else
				exception("At highest floor!");
		};
		void goDown() 
		{ 
			if (currentFloor > MINFLOOR)
				currentFloor--;
			else
				exception("At lowest floor!");
		};
		void progression(vector<User> &peopleWait, vector<User> &peopleAccepted, vector<User> &peopleProgress, vector<User> &peopleDone);
		void visualize(vector<User> peopleWait, vector<User> peopleAccepted, vector<User> peopleProgress, vector<User> peopleDone);
};