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
		vector<User> inside;
	public:
		Elevator() {}
		int getFloor() { return currentFloor; };
		void goUp() { currentFloor++; };
		void goDown() { currentFloor--; };
};

