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
		void progress(vector<User>waitList, vector<User>inProgressList, vector<User>arrivedList)
		{
			if (goingUp.size() == 0 && goingDown.size() == 0) // Used for checking if both queues are empty and choosing which direction to take next
			{
				if (waitList.begin()->getOutSideRequest() == UP)
				{
					currentDirection = UP;
					goingUp.push(waitList.begin()->getCurrentFloor());
					inProgressList.push_back(*waitList.begin());
					waitList.erase(waitList.begin());
				}
				else
				{
					currentDirection = DOWN;
					goingDown.push(waitList.begin()->getCurrentFloor());
					inProgressList.push_back(*waitList.begin());
					waitList.erase(waitList.begin());
				}
			}
			vector<User>::iterator waitListITR = waitList.begin();
			vector<User>::iterator progressListITR = inProgressList.begin();
			if (currentDirection == UP)
			{

			}
			if (currentDirection == DOWN)
			{

			}
		}
};

