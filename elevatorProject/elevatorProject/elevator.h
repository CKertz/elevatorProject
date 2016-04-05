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
		priorityUpQueue<int> goingUp;
		priorityDownQueue<int> goingDown;
		direction currentDirection;
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
		void progress(vector<User>&people);
};

