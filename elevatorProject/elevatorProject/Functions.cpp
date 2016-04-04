#include "Header.h"
#include "User.h"
#include "elevator.h"

using namespace std;

void simulation(Elevator elevator, vector<User>people)
{
	int dice;
	bool done = false; //determined if all users have arrived AND if the max number of generated users has been met
	while (!done)
	{
		while (elevator.getFloor() != MAXFLOOR)
		{
			if (generateUser(people)) // If statement is to determine if a new entry should be added to the elevator's tasks. If true, add the last user's currentFloor
			{

			}
			
			elevator.goUp();
		}
		while (elevator.getFloor() != MINFLOOR)
		{
			if (generateUser(people))
			{

			}

			elevator.goDown();
		}
	}
}

bool generateUser(vector<User> people) // Used to create new people for the scenario
{
	if (people.size() != MAXUSERS)
	{
		int dice = rand() % 6 + 1; // Roll six sided dice to determine if a user is generated or not
		if (dice % 2) // If even, add a user
		{
			User* temp = new User;
			people.push_back(*temp);
			delete temp;
			return true;
		}
		else // If odd, return
		{
			return false;
		}
	}
	return false;
}

bool allUsersArrived(vector<User> people)
{
	bool allArrived = true;
	vector<User>::iterator itr = people.begin();
	while (itr != people.end())
	{
		if (!(itr->arrived()))
		{
			allArrived = false;
		}
		itr++;
	}
	return allArrived;
}

void incrementTimeAllUsers(vector<User> people, bool didStop)
{	
	vector<User>::iterator itr = people.begin();
	while (itr != people.end())
	{		
		itr->incrementTime(didStop);
	}
}