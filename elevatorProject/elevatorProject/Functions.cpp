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

			
			elevator.goUp();
		}
		while (elevator.getFloor() != MINFLOOR)
		{


			elevator.goDown();
		}
	}
}

void generateUser(vector<User> people) // Used to create new people for the scenario
{
	int dice = rand() % 6 + 1; // Roll six sided dice to determine if a user is generated or not
	if (dice % 2) // If even, add a user
	{
		User* temp = new User;
		people.push_back(*temp);
		delete temp;
	}
	else // If odd, return
	{
		return;
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