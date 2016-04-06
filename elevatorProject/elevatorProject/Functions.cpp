#include "Header.h"
#include "User.h"
#include "elevator.h"
#include "PrototypeDefinitions.h"

using namespace std;

void simulation(Elevator &elevator, vector<User> &peopleWait, vector<User> &peopleAccepted, vector<User> &peopleProgress, vector<User> &peopleDone)
{
	//Declarations:
	int total = 0;
	//First User is always generated
	User* temp = new User(total);
	peopleWait.push_back(*temp);
	temp->printUserStats();
	//system("pause");
	total++;
	///////////////
	//Loop while the arrivedList does not contain the max amount of the users the program can generate
	do
	{
		elevator.progression(peopleWait, peopleAccepted, peopleProgress, peopleDone);
		generateUser(peopleWait, total);
	} 
	while (peopleDone.size() != MAXUSERS);	
}

void generateUser(vector<User> &people, int &total) // Used to create new people for the scenario
{
	if (total != MAXUSERS)
	{
		int dice = rand() % 6 + 1; // Roll six sided dice to determine if a user is generated or not
		if (dice % 2) // If even, add a user
		{
			cout << "User generated!" << endl;
			User* temp = new User(total);
			people.push_back(*temp);
			temp->printUserStats();
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
	//cout << "Time incremented" << endl; 
	vector<User>::iterator itr = people.begin();
	while (itr != people.end())
	{	
		itr->incrementTime(didStop);
		itr++;
	}
}

void deleteEntries(vector<User> &people, const vector<int> deletion)
{
	int deletes = 0;
	int temp;
	for (int i = 0; i < deletion.size(); i++)
	{
		temp = deletion[i] - deletes;
		people.erase(people.begin() + temp);
		deletes++;
	}
}