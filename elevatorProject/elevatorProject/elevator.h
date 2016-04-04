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
		priorityUpQueue<int> currentUps;
		priorityUpQueue<int> upWaitList;
		priorityDownQueue<int> currentDowns;
		priorityDownQueue<int> downWaitList;
	public:
		int getFloor() { return currentFloor; };
		void goUp() { currentFloor++; };
		void goDown() { currentFloor--; };
		void completeCurrentDowns()
		{
			while (currentFloor > minFloor)
			{

			}
		}
		void completeCurrentUps()
		{
			while (currentFloor < maxFloor)
			{

			}
		}
};

