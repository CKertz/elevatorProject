#include "elevator.h"
#include "PrototypeDefinitions.h"
#include "PriorityQueue.h"
#include <iostream>

using namespace std;

int main() 
{
	//Declarations:
	vector<User> peopleWait;
	vector<User> peopleAccepted;
	vector<User> peopleProgress;
	vector<User> peopleDone;
	Elevator elevator;
	srand(time(NULL));
	///////////////
	cout << "Press any key to begin simulation" << endl;
	system("pause");
	system("cls");
	simulation(elevator, peopleWait, peopleAccepted, peopleProgress, peopleDone);
	cout << peopleDone.size() << endl;
	for (int i = 0; i < MAXUSERS; i++)
	{
		peopleDone[i].printUserStats();
	}
	system("pause");
	return 0;
}