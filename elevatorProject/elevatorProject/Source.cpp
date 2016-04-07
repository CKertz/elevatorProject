#include "elevator.h"
#include "PrototypeDefinitions.h"
#include "PriorityQueue.h"
#include <iostream>

using namespace std;

int main() 
{
	cout << "Press any key to begin simulation" << endl;
	system("pause");
	system("cls");
	srand(time(NULL));
	while (true)
	{
		//Declarations:
		vector<User> peopleWait;
		vector<User> peopleAccepted;
		vector<User> peopleProgress;
		vector<User> peopleDone;
		Elevator elevator;
		///////////////
		simulation(elevator, peopleWait, peopleAccepted, peopleProgress, peopleDone);
		cout << "Simulation Results:" << endl;
		cout << "Total Users: " << peopleDone.size() << "  | Building Height: " << MAXFLOOR << endl;
		for (int i = 0; i < MAXUSERS; i++)
		{
			peopleDone[i].printUserStats();
		}
	}	
	return 0;
}