#pragma once
#include "Header.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


class User
{
	private:
		int currentFloor;
		int desiredFloor;
		int waitForElevatorTime;
		int waitForDestinationTime;
		int totalWaitTime;
		bool onElevator;
		bool hasArrived;
		direction outSideRequest;
	public:
		User()
		{
			int temp;
			waitForElevatorTime = 0;
			waitForDestinationTime = 0;
			totalWaitTime = 0;
			currentFloor = rand() % MAXFLOOR + 1;
			if (currentFloor == MAXFLOOR)
			{
				desiredFloor = rand() % MAXFLOOR + 1;
				outSideRequest = DOWN;
			}
			else if (currentFloor == MINFLOOR)
			{
				desiredFloor = rand() % MAXFLOOR + 2;
				outSideRequest = UP;
			}
			else
			{
				temp = rand() % 6 + 1; // Roll six sided dice to determine direction
				if (temp % 2)
				{
					outSideRequest = UP;
					desiredFloor = rand() % (MAXFLOOR-currentFloor) + currentFloor+1;
				}
				else
				{
					outSideRequest = DOWN;
					desiredFloor = rand() % currentFloor + MINFLOOR-1;
				}
			}
			onElevator = false;
			hasArrived = false;
		}
		int getCurrentFloor() { return currentFloor; }
		int getInsideRequest() { return desiredFloor; }
		direction getOutSideRequest() { return outSideRequest; }
		void printUserStats()
		{
			if (outSideRequest == DOWN)
			{
				cout << "DOWN" << endl;
			}
			else
			{
				cout << "UP" << endl;
			}
			cout << currentFloor << " " <<  desiredFloor << " " << waitForElevatorTime << " " << waitForDestinationTime << " " << totalWaitTime << endl;
		}
		bool arrived()
		{
			return hasArrived;
		}
		void incrementTime(bool didStop)
		{
			int baseTime = 1;
			if (didStop)
				baseTime *= 10;
			if (!hasArrived)
			{
				if (!onElevator)
				{
					waitForElevatorTime += baseTime;
				}
				else
				{
					waitForDestinationTime += baseTime;
				}
				totalWaitTime += baseTime;
			}
		}
};