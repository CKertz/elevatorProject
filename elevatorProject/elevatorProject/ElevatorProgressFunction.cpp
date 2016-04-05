#include "Header.h"
#include "User.h"
#include "elevator.h"
#include "PrototypeDefinitions.h"
#include "PriorityQueue.h"
#include <iostream>

using namespace std;

void Elevator::progress(vector<User>waitList, vector<User>onElevatorList, vector<User>arrivedList)
{
	if (goingUp.size() == 0 && goingDown.size() == 0) // Used for checking if both queues are empty and choosing which direction to take next
	{
		if (waitList.begin()->getOutSideRequest() == UP)
		{
			currentDirection = UP;
			goingUp.push(waitList.begin()->getCurrentFloor());
			//inProgressList.push_back(*waitList.begin()); // The less than or greater than statements prevent the same number from being added more than once. Code left for reference
			//waitList.erase(waitList.begin());
		}
		else
		{
			currentDirection = DOWN;
			goingDown.push(waitList.begin()->getCurrentFloor());
			//inProgressList.push_back(*waitList.begin());
			//waitList.erase(waitList.begin());
		}
	}
	vector<User>::iterator waitListITR = waitList.begin();
	vector<User>::iterator onElevatorListITR = onElevatorList.begin();
	if (currentDirection == UP)
	{
		while (waitListITR != waitList.end()) //Check to see if anyone is on the way
		{
			if (waitListITR->getOutSideRequest() == UP)
			{
				if (waitListITR->getCurrentFloor() < goingUp.top())
				{
					if (waitListITR->getCurrentFloor() > currentFloor)
						goingUp.push(waitListITR->getCurrentFloor());
				}
			}
			waitListITR++;
		}
		waitListITR = waitList.begin();
		if (currentFloor == goingUp.top())
		{
			incrementTimeAllUsers(waitList, true);
			incrementTimeAllUsers(onElevatorList, true);
			while (waitListITR != waitList.end()) //Check to see who gets on
			{
				if (waitListITR->getCurrentFloor() == currentFloor)
				{

				}
				waitListITR++;
			}
			while (onElevatorListITR != onElevatorList.end()) // Check to see who gets off
			{
				if (onElevatorListITR->getInsideRequest() == currentFloor)
				{

				}
				onElevatorListITR++;
			}
		}
	}
	if (currentDirection == DOWN)
	{
		while (waitListITR != waitList.end())
		{

		}
	}
}