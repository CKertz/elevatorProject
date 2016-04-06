#include "Header.h"
#include "User.h"
#include "elevator.h"
#include "PrototypeDefinitions.h"
#include "PriorityQueue.h"
#include <iostream>

using namespace std;

void Elevator::progression(vector<User> &peopleWait, vector<User> &peopleAccepted, vector<User> &peopleProgress, vector<User> &peopleDone)
{
	//Declarations:
	bool addAccepted = false;
	bool eraseOccured = false;
	bool atStop;
	vector<int> deletion;
	idle = false;
	///////////////
	if (peopleWait.empty() && peopleAccepted.empty() && peopleProgress.empty())
	{
		idle = true;
		visualize(peopleWait, peopleAccepted, peopleProgress, peopleDone);
	}
	else
	{
		visualize(peopleWait, peopleAccepted, peopleProgress, peopleDone);
		if (!peopleWait.empty())
		{
			if (currentPriorities.size() == 0)
			{
				currentDirection = peopleWait.front().getIntendedDirection();
				currentPriorities.changeDirection(currentDirection);
				currentPriorities.add(peopleWait.front().getCurrentFloor());
				peopleAccepted.push_back(peopleWait.front());
				peopleWait.erase(peopleWait.begin());
				/*if (currentDirection == UP)
					cout << "UP established!" << endl;
				else
					cout << "Down established!" << endl;*/
			}
		}
		if (!peopleWait.empty())
		{
			for (int i = 0; i < peopleWait.size(); i++)
			{
				if (peopleWait[i].getIntendedDirection() == currentDirection)
				{
					if (currentDirection == UP)
					{
						if (peopleWait[i].getCurrentFloor() < currentPriorities.get()) // Make sure their current floor is below the elevator's current destination floor
						{
							if (peopleWait[i].getCurrentFloor() >= currentFloor) // Make sure their current floor is above the elevator's current floor
							{
								addAccepted = true;
							}
						}
					}
					if (currentDirection == DOWN)
					{
						if (peopleWait[i].getCurrentFloor() > currentPriorities.get()) // Make sure their current floor is above the elevator's current destination floor
						{
							if (peopleWait[i].getCurrentFloor() <= currentFloor) // Make sure their current floor is below the elevator's current floor
							{
								addAccepted = true;
							}
						}
					}
					if (currentPriorities.get() == MINFLOOR)
					{
						if (peopleWait[i].getCurrentFloor() <= currentFloor)
						{
							if (peopleWait[i].getIntendedDirection() == DOWN)
							{
								addAccepted = true;
							}
						}
					}
					if (currentPriorities.get() == MAXFLOOR)
					{
						if (peopleWait[i].getCurrentFloor() >= currentFloor)
						{
							if (peopleWait[i].getIntendedDirection() == UP)
							{
								addAccepted = true;
							}
						}
					}
				}
				if (addAccepted)
				{
					currentPriorities.add(peopleWait[i].getCurrentFloor()); // Add the floor to the top of the elevator's desintation queue
					peopleAccepted.push_back(peopleWait[i]); // Add to accepted list
					deletion.push_back(i); // Add to deletion list, to be removed from wait list
				}
			}
		}
		deleteEntries(peopleWait, deletion);
		deletion.clear();

		atStop = (currentPriorities.get() == currentFloor); // Check if the currentFloor is a stop point
		if (atStop) //If the floor the elevator is at is one of its destinations (atStop == true) then this statment will run
		{
			incrementTimeAllUsers(peopleWait, true);
			incrementTimeAllUsers(peopleAccepted, true);
			incrementTimeAllUsers(peopleProgress, true);
			for (int i = 0; i < peopleAccepted.size(); i++) // Check to see who gets on the elevator
			{
				if (peopleAccepted[i].getCurrentFloor() == currentFloor) // They must have already been accepted to get on, meaning they have the same direction and are on the way to the elevator's destination
				{
					boarding = true;
					peopleAccepted[i].board(); // Board the elevator
					currentPriorities.add(peopleAccepted[i].getDesiredFloor()); // Add the new user's desired floor to the priority queue
					peopleProgress.push_back(peopleAccepted[i]); // Add to progress list
					deletion.push_back(i); // Remove from accepted list
					//visualize(peopleWait, peopleAccepted, peopleProgress, peopleDone);
				}
				boarding = false;
			}
			deleteEntries(peopleAccepted, deletion);
			deletion.clear();

			//cout << peopleProgress.size() << endl;
			for (int i = 0; i < peopleProgress.size(); i++)
			{
				if (peopleProgress[i].getDesiredFloor() == currentFloor)
				{
					arriving = true;
					peopleProgress[i].arrive(currentFloor); // Get off the elevator
					peopleDone.push_back(peopleProgress[i]); // Add to done list
					deletion.push_back(i); // Remove from progress list
					//visualize(peopleWait, peopleAccepted, peopleProgress, peopleDone);
				}
				arriving = false;
			}
			deleteEntries(peopleProgress, deletion);
			deletion.clear();

			currentPriorities.complete();
		}
		else
		{
			incrementTimeAllUsers(peopleWait, false);
			incrementTimeAllUsers(peopleAccepted, false);
			incrementTimeAllUsers(peopleProgress, false);
		}
		if (!currentPriorities.empty())
		{
			if (currentPriorities.get() > currentFloor)
			{
				goUp();
			}
			else
			{
				goDown();
			}
		}
	}
	//visualize(peopleWait, peopleAccepted, peopleProgress, peopleDone);
}

void Elevator::visualize(vector<User> peopleWait, vector<User> peopleAccepted, vector<User> peopleProgress, vector<User> peopleDone)
{
	cout << "Current floor: " << currentFloor << " |Current Destination: ";
	if (!currentPriorities.empty())
		cout << currentPriorities.get() << " |";
	else
		cout << "E | ";
	cout << "Current Status: ";
	if (boarding)
		cout << "Boarding ";
	else if (arriving)
		cout << "Arriving ";
	else if (idle)
		cout << "Idle ";
	else
		cout << "Standard ";
	cout << " | peopleWait#: " << peopleWait.size() << " | peopleAccepted#: " << peopleAccepted.size() << " | peopleProgress#: " << peopleProgress.size() << " | peopleDone#: " << peopleDone.size() << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
	for (int j = MAXFLOOR; j >= MINFLOOR; j--)
	{
		if (currentFloor == j)
		{
			cout << "|      /------------------/           |" << endl;
			cout << "|      |    " << peopleProgress.size() << "             |           |" << endl;
			cout << "|      |                  |           |    Waiting                               Accepted                         Done" << endl;
			cout << "|      |                  |           |   ";
			for (int i = 0; i < peopleWait.size(); i++)
			{
				if (peopleWait[i].getCurrentFloor() == j)
					cout << "W:(" << peopleWait[i].getCurrentFloor() << "," << peopleWait[i].getDesiredFloor() << ") ";
			}
			for (int i = 0; i < peopleAccepted.size(); i++)
			{
				if (peopleAccepted[i].getCurrentFloor() == j)
					cout << "A:(" << peopleAccepted[i].getCurrentFloor() << "," << peopleAccepted[i].getDesiredFloor() << ") ";
			}
			for (int i = 0; i < peopleDone.size(); i++)
			{
				if (peopleDone[i].getCurrentFloor() == j)
					cout << "D:(" << peopleDone[i].getCurrentFloor() << "," << peopleDone[i].getDesiredFloor() << ") ";
			}
			cout << endl;
			cout << "|      |                  |           |" << endl;
			cout << "|      /------------------/           |" << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
		}
		else
		{
			cout << "|                                     |" << endl;
			cout << "|                                     |" << endl;
			cout << "|                                     |    Waiting                               Accepted                         Done" << endl;
			cout << "|                                     |   ";
			for (int i = 0; i < peopleWait.size(); i++)
			{
				if (peopleWait[i].getCurrentFloor() == j)
					cout << "W:(" << peopleWait[i].getCurrentFloor() << "," << peopleWait[i].getDesiredFloor() << ") ";
			}
			for (int i = 0; i < peopleAccepted.size(); i++)
			{
				if (peopleAccepted[i].getCurrentFloor() == j)
					cout << "A:(" << peopleAccepted[i].getCurrentFloor() << "," << peopleAccepted[i].getDesiredFloor() << ") ";
			}
			for (int i = 0; i < peopleDone.size(); i++)
			{
				if (peopleDone[i].getCurrentFloor() == j)
					cout << "D:(" << peopleDone[i].getCurrentFloor() << "," << peopleDone[i].getDesiredFloor() << ") ";
			}
			cout << endl;
			cout << "|                                     |" << endl;
			cout << "|                                     |" << endl;
			cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
		}
	}
	cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
	system("pause");
	system("cls");
}