#include "Header.h"
#include "User.h"
#include "elevator.h"
#include "PrototypeDefinitions.h"
#include "PriorityQueue.h"
#include <iostream>

using namespace std;

void Elevator::progress(vector<User>waitList, vector<User>onElevatorList, vector<User>arrivedList)
{
	cout << currentFloor << endl;
	if (goingUp.size() == 0 && goingDown.size() == 0) // Used for checking if both queues are empty and choosing which direction to take next
	{
		if (waitList.begin()->getOutSideRequest() == UP)
		{
			cout << "UP established!" << endl;
			currentDirection = UP;
			goingUp.push(waitList.begin()->getCurrentFloor());
			//inProgressList.push_back(*waitList.begin()); // The less than or greater than statements prevent the same number from being added more than once. Code left for reference
			//waitList.erase(waitList.begin());
		}
		else
		{
			cout << "Down established!" << endl;
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
			cout << "Up check" << endl;
			if (waitListITR->getOutSideRequest() == UP) // Make sure they have the same desired direction as the current direction of the elevator
			{
				if (waitListITR->getCurrentFloor() < goingUp.top()) // Make sure their current floor is below the elevator's current destination floor
				{
					if (waitListITR->getCurrentFloor() > currentFloor) // Make sure their current floor is above the elevator's current floor
						goingUp.push(waitListITR->getCurrentFloor()); // Add the floor to the top of the elevator's destination queue
				}
			}
			waitListITR++;
		}
		waitListITR = waitList.begin(); //Reset wait list iterator
		if (currentFloor == goingUp.top()) //If the floor the elevator is at is one of its destinations
		{
			cout << "Up floor arrived" << endl;
			incrementTimeAllUsers(waitList, true); //Increment a stop time into all wait counters
			incrementTimeAllUsers(onElevatorList, true);
			while (waitListITR != waitList.end()) //Check to see who gets on
			{
				cout << "sucess" << endl;
				if (waitListITR->getCurrentFloor() == currentFloor) //True if the elevator's current floor is the same as the Outside user's current floor
				{
					cout << "Up board" << endl;
					waitListITR->board(); // Board the elevator
					goingUp.push(waitListITR->getInsideRequest()); // Add the new user's desired floor to the priority queue					
					onElevatorList.push_back(*waitListITR); // Add the new user to the on Elevator list
					waitList.erase(waitListITR); // Remove the new user from the wait list
				}
				cout << "Prepare incrment" << endl;
				if (waitListITR != waitList.end())
				{
					waitListITR++;
				}
			}
			while (onElevatorListITR != onElevatorList.end()) // Check to see who gets off
			{
				if (onElevatorListITR->getInsideRequest() == currentFloor) // True if the elevator's current floor is the same as the Inside's user's desired floor
				{
					cout << "Up arrive" << endl;
					onElevatorListITR->arrive(); // Get off the elevator
					arrivedList.push_back(*onElevatorListITR); // Add the departing user to the arrived list
					onElevatorList.erase(onElevatorListITR); // Remove the departing user from the on elevator list
				}
				if (onElevatorListITR != onElevatorList.end())
				{
					onElevatorListITR++;
				}
			}
			goingUp.pop(); // Top of the queue has been visited, remove from queue
		}
		if (currentFloor != MAXFLOOR)
		{
			cout << "Go up" << endl;
			goUp();
		}
		else
		{
			cout << "Exception up" << endl;
		}
	}
	if (currentDirection == DOWN)
	{
		while (waitListITR != waitList.end()) //Check to see if anyone is on the way
		{
			cout << "Down check" << endl;
			if (waitListITR->getOutSideRequest() == DOWN) // Make sure they have the same desired direction as the current direction of the elevator
			{
				if (waitListITR->getCurrentFloor() > goingDown.top()) // Make sure their current floor is above the elevator's current destination floor
				{
					if (waitListITR->getCurrentFloor() < currentFloor) // Make sure their current floor is below the elevator's current floor
						goingDown.push(waitListITR->getCurrentFloor()); // Add the floor to the top of the elevator's destination queue
				}
			}
			waitListITR++;
		}
		waitListITR = waitList.begin(); //Reset wait list iterator
		if (currentFloor == goingDown.top()) //If the floor the elevator is at is one of its destinations
		{
			cout << "Down floor arrived" << endl;
			incrementTimeAllUsers(waitList, true); //Increment a stop time into all wait counters
			incrementTimeAllUsers(onElevatorList, true);
			while (waitListITR != waitList.end()) //Check to see who gets on
			{
				if (waitListITR->getCurrentFloor() == currentFloor) //True if the elevator's current floor is the same as the Outside user's current floor
				{
					cout << "Down board" << endl;
					waitListITR->board(); // Board the elevator
					goingDown.push(waitListITR->getInsideRequest()); // Add the new user's desired floor to the priority queue					
					onElevatorList.push_back(*waitListITR); // Add the new user to the on Elevator list
					waitList.erase(waitListITR); // Remove the new user from the wait list
				}
				if (waitListITR != waitList.end())
				{
					waitListITR++;
				}
			}
			while (onElevatorListITR != onElevatorList.end()) // Check to see who gets off
			{
				if (onElevatorListITR->getInsideRequest() == currentFloor) // True if the elevator's current floor is the same as the Inside's user's desired floor
				{
					cout << "Down arrive" << endl;
					onElevatorListITR->arrive(); // Get off the elevator
					arrivedList.push_back(*onElevatorListITR); // Add the departing user to the arrived list
					onElevatorList.erase(onElevatorListITR); // Remove the departing user from the on elevator list
				}
				if (onElevatorListITR != onElevatorList.end())
				{
					onElevatorListITR++;
				}
			}
			goingDown.pop(); // Top of the queue has been visited, remove from queue
		}
		if (currentFloor != MINFLOOR)
		{
			cout << "Go down" << endl;
			goDown();
		}
		else
		{
			cout << "Exception down" << endl;
			cout << goingDown.size() << endl;
		}
	}
	cout << "Progress complete" << endl;
}