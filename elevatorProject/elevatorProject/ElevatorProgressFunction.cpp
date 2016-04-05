#include "Header.h"
#include "User.h"
#include "elevator.h"
#include "PrototypeDefinitions.h"
#include "PriorityQueue.h"
#include <iostream>

using namespace std;

void Elevator::progress(vector<User>&people)
{
	//Declarations:
	bool firstFound = false;
	bool atStop;
	vector<User>::iterator peopleITR = people.begin();
	///////////////
	cout << "Elevator current floor: " << currentFloor << endl;
	/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	if (goingUp.size() == 0 && goingDown.size() == 0 && people.size() != 0) // Used for checking if both queues are empty and if the list of people is not empty. Used for choosing which direction to take next
	{
		while (!firstFound) // Becomes true once the next initial user is found or the end of the list of vectors is reached
		{
			if (!(peopleITR->onBoard()) && !(peopleITR->arrived())) // Is ture if the user has neither got on the elevator or arrived on their desired floor
			{
				if (peopleITR->getOutSideRequest() == UP)
				{
					cout << "UP established!" << endl;
					currentDirection = UP;
					goingUp.push(peopleITR->getCurrentFloor());
				}
				else
				{
					cout << "Down established!" << endl;
					currentDirection = DOWN;
					goingDown.push(peopleITR->getCurrentFloor());
				}
				firstFound = true;
			}
			if (peopleITR != people.end())
				firstFound = true;
			else
				peopleITR++;
		}
	}
	/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	peopleITR = people.begin();
	do
	{
		//cout << "Universal check" << endl;
		if (peopleITR->getOutSideRequest() == currentDirection) // Make sure they have the same desired direction as the current direction of the elevator
		{
			if (!(peopleITR->onBoard()) && !(peopleITR->arrived()))
			{
				if (currentDirection == UP)
				{
					if (peopleITR->getCurrentFloor() < goingUp.top()) // Make sure their current floor is below the elevator's current destination floor
					{
						if (peopleITR->getCurrentFloor() > currentFloor) // Make sure their current floor is above the elevator's current floor
						{
							goingUp.push(peopleITR->getCurrentFloor()); // Add the floor to the top of the elevator's destination queue							
						}
					}
				}
				else
				{
					if (peopleITR->getCurrentFloor() > goingDown.top()) // Make sure their current floor is above the elevator's current destination floor
					{
						if (peopleITR->getCurrentFloor() < currentFloor) // Make sure their current floor is below the elevator's current floor
						{
							goingDown.push(peopleITR->getCurrentFloor()); // Add the floor to the top of the elevator's destination queue
						}
					}
				}

			}
		}
		if (peopleITR != people.end())
			peopleITR++;
	} while (peopleITR != people.end()); //Check to see if anyone is on the way
	peopleITR = people.begin(); //Reset iterator
	if (currentDirection == UP) // Check if the currentFloor is a stop point
		atStop = (goingUp.top() == currentFloor);
	else
		atStop = (goingDown.top() == currentFloor);
	if (atStop) //If the floor the elevator is at is one of its destinations (atStop == true) then this statment will run
	{
		cout << "Univeral arrived" << endl;
		incrementTimeAllUsers(people, true);
		do //Check to see who gets on and off
		{
			if ((peopleITR->getCurrentFloor() == currentFloor) && (peopleITR->getOutSideRequest() == currentDirection) && (!(peopleITR->onBoard())) && (!(peopleITR->arrived())))
			{
				cout << "Boarding" << endl;
				peopleITR->board(); // Board the elevator
				if (currentDirection == UP) // Add the new user's desired floor to the priority queue
					goingUp.push(peopleITR->getInsideRequest());
				else
					goingDown.push(peopleITR->getInsideRequest());
			}
			if ((peopleITR->getInsideRequest() == currentFloor) && (!(peopleITR->arrived())))
			{
				cout << "Arrival" << endl;
				peopleITR->arrive(currentFloor);
			}
			if (peopleITR != people.end())
			{
				peopleITR++;
			}
		} while (peopleITR != people.end());
		if (currentDirection == UP && !goingUp.empty())
			goingUp.pop(); // Top of the queue has been visited, remove from queue
		else if (!goingDown.empty())
			goingDown.pop(); // Top of the queue has been visited, remove from queue
	}
	else
	{
		incrementTimeAllUsers(people, false);
	}
	/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	if (currentDirection == UP)
	{
		if (!goingUp.empty())
		{
			if (goingUp.top() > currentFloor)
			{
				cout << "Previous floor: " << currentFloor << endl;
				cout << "Go up" << endl;
				goUp();
				cout << "New floor: " << currentFloor << endl;
			}
			else
			{
				cout << "Previous floor: " << currentFloor << endl;
				cout << "Go down" << endl;
				goDown();
				cout << "New floor: " << currentFloor << endl;
			}
		}
	}
	else if (!goingDown.empty())
	{
		if (goingDown.top() > currentFloor)
		{
			cout << "Previous floor: " << currentFloor << endl;
			cout << "Go up" << endl;
			goUp();
			cout << "New floor: " << currentFloor << endl;
		}
		else
		{
			cout << "Previous floor: " << currentFloor << endl;
			cout << "Go down" << endl;
			goDown();
			cout << "New floor: " << currentFloor << endl;
		}
	}
	/*------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
	cout << "Progress complete" << endl;
}