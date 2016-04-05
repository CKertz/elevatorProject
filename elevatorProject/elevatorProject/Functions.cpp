#include "Header.h"
#include "User.h"
#include "elevator.h"
#include "PrototypeDefinitions.h"

using namespace std;

void simulation(Elevator elevator, vector<User>waitList, vector<User>arrivedList)
{
	vector<User> inProgressList;
	//First User is always generated
	User* temp = new User;
	waitList.push_back(*temp);
	delete temp;
	//Loop while the arrivedList does not contain the max amount of the users the program can generate
	do
	{
		elevator.progress(waitList, inProgressList, arrivedList);
		generateUser(waitList);
	} 
	while (arrivedList.size() != MAXUSERS);
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

bool allUsersArrived(vector<User> people) // to be depricated
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