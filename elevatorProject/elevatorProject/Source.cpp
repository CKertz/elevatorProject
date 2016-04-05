#include "elevator.h"
#include "PrototypeDefinitions.h"
#include "PriorityQueue.h"
#include <iostream>

using namespace std;

int main() 
{
	//Declarations:
	vector<User> people;
	Elevator elevator;
	srand(time(NULL));
	///////////////
	cout << "Begin simulation" << endl;
	simulation(elevator, people);
	cout << people.size() << endl;
	for (int i = 0; i < MAXUSERS; i++)
	{
		people[i].printUserStats();
	}
	return 0;
}