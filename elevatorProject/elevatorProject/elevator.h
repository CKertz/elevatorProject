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
		direction currentDirection;
	public:
		Elevator() { currentFloor = 1; }
		int getFloor() { return currentFloor; };
		void goUp() { currentFloor++; };
		void goDown() { currentFloor--; };
};

