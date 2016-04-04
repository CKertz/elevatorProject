#include "Header.h"
#include "User.h"
#include "elevator.h"

using namespace std;

void simulation(Elevator elevator, vector<User>people)
{
	bool done = false;
	while (!done)
	{
		while (elevator.getFloor() != MAXFLOOR)
		{
			elevator.goUp();
		}
	}
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