// Elevator Project
// April 2016
// William Munshaw, Cooper Kertz, Amy Curtis
// File: User.h

#pragma once
#include "Header.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


class User
{
	private:
		int creationOrder;
		int originalCurrent;
		int currentFloor;
		int desiredFloor;
		int waitForElevatorTime;
		int waitForDestinationTime;
		int totalWaitTime;
		bool onElevator;
		bool hasArrived;
		direction outSideRequest;
	public:
		//The Default Constructor
		User(int total)
		{
			creationOrder = total;
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
			if (desiredFloor > MAXFLOOR)
				desiredFloor = MAXFLOOR;
			if (desiredFloor < MINFLOOR)
				desiredFloor = MINFLOOR;
			if (currentFloor == desiredFloor)
			{
				if (desiredFloor < MAXFLOOR)
				{
					desiredFloor++;
				}
				else
				{
					desiredFloor--;
				}
			}
			originalCurrent = currentFloor;
		}
		//Getter functions
		int getCurrentFloor() { return currentFloor; }
		int getDesiredFloor() { return desiredFloor; }
		direction getIntendedDirection() { return outSideRequest; }
		//Function used to print the stats of users
		void printUserStats()
		{
			cout << endl;
			cout << creationOrder << ". ";
			if (outSideRequest == DOWN)
			{
				cout << "Requested to go down." << endl;
			}
			else
			{
				cout << "Requested to go up." << endl;
			}
			cout << "Original floor: " << originalCurrent << "  |New current floor: " << currentFloor << " |Originally desired floor: " << desiredFloor << " |Waiting for elevator: " << waitForElevatorTime << " |Waiting to arrive: " << waitForDestinationTime << " |Total Wait time: " << totalWaitTime << endl;
			cout << endl;
		}
		void board()
		{
			onElevator = true;
		}
		void arrive(int elevatorCurrentFloor)
		{
			onElevator = false;
			hasArrived = true;
			currentFloor = elevatorCurrentFloor;
		}
		bool onBoard()
		{
			return onElevator;
		}
		bool arrived()
		{
			return hasArrived;
		}
		//Function used to advance the amount of wait time has passed
		void incrementTime(bool didStop)
		{
			int baseTime = 1;
			if (didStop)
				baseTime *= 10;
			if (!hasArrived)
			{
				//cout << "Increment!" << endl;
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