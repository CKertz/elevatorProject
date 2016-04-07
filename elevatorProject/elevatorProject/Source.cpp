// Elevator Project
// April 2016
// William Munshaw, Cooper Kertz, Amy Curtis
// File: Source.cpp

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
	char exit = '0';
	while (exit != 'e')
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
		cout << "Notice: Time units are arbitrary." << endl;
		for (int i = 0; i < MAXUSERS; i++)
		{
			peopleDone[i].printUserStats();
		}
		cout << "Simulation complete. Press any key to run again. Press 'e' to exit. " << endl;
		cin >> exit;
	}
	return 0;
}