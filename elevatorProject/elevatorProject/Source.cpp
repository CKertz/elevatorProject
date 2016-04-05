#include "elevator.h"
#include "PrototypeDefinitions.h"
#include "PriorityQueue.h"
#include <iostream>

using namespace std;

int main() 
{
	//Declarations:
	vector<User> waitList;
	vector<User> arrivedList;
	Elevator elevator;
	srand(time(NULL));
	///////////////
	cout << "Begin simulation" << endl;
	simulation(elevator, waitList, arrivedList);
	for (int i = 0; i < MAXUSERS; i++)
	{
		arrivedList[i].printUserStats();
	}
	return 0;
}