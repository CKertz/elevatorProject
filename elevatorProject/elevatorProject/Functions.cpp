#include "Header.h"
#include "User.h"
#include "elevator.h"
#include "PrototypeDefinitions.h"

using namespace std;

void simulation(Elevator &elevator, vector<User>&people)
{
	//Declarations:
	vector<User>::iterator peopleITR;
	int total = 0;
	//First User is always generated
	User* temp = new User;
	people.push_back(*temp);
	temp->printUserStats();
	//system("pause");
	total++;
	///////////////
	//Loop while the arrivedList does not contain the max amount of the users the program can generate
	//cout << "First user created!" << endl;
	do
	{
		elevator.progress(people);
		generateUser(people, total);
	} 
	while (!allUsersArrived(people) && total != MAXUSERS);	
}

void generateUser(vector<User> &people, int &total) // Used to create new people for the scenario
{
	if (total != MAXUSERS)
	{
		int dice = rand() % 6 + 1; // Roll six sided dice to determine if a user is generated or not
		if (dice % 2) // If even, add a user
		{
			cout << "User generated!" << endl;
			User* temp = new User;
			people.push_back(*temp);
			temp->printUserStats();
			//system("pause");
			total++;
		}
	}		
}

bool allUsersArrived(vector<User> &people)
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

void incrementTimeAllUsers(vector<User> &people, bool didStop)
{	
	cout << "Time incremented" << endl; 
	vector<User>::iterator itr = people.begin();
	while (itr != people.end())
	{	
		itr->incrementTime(didStop);
		itr++;
	}
}