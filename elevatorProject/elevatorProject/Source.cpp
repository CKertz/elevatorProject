#include "elevator.h"
#include "PrototypeDefinitions.h"
#include <iostream>

using namespace std;

int main() 
{
	//Declarations:
	vector<User> people;
	Elevator elevator;
	srand(time(NULL));
	///////////////
	for (int i = 0; i < MAXUSERS; i++)
	{
		User* temp = new User;
		people.push_back(*temp);
		delete temp;
	}
	for (int i = 0; i < MAXUSERS; i++)
	{
		people[i].printUserStats();
	}
	return 0;
}