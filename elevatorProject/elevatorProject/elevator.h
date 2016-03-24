#pragma once
#include <vector>
#include <string>
using namespace std;

class elevator {
private:
	vector<int>elevate;
	bool Stop;
	int currentFloor;
	int floorDifference;
	int waitingTime;
	string direction;
public:

elevator() {
	Stop = false;
	currentFloor = 0;
	floorDifference = 0;
	waitingTime = 0;
	//stopCount = 0;
}
int atDoor(int floor) {

}
int inputRequest(int floor) {
	elevate.push_back(floor);
} 
//elevating will take a request from a user, stop at any floors requested between currentFloor and floorRequest,
//pop these values from the vector, and continue in that direction.
//iterate through elevate, if floor between floorRequest and currentFloor exists in vector, stop at it
//this means if iterator points at any variable greater than currentfloor, less than floorrequest
void elevating(int floorRequest) 
{ //string givenDirection parameter? not sure yet
	vector<int>::iterator itr;
	int i = 0;

	if (elevate.size() == 0)
		throw exception("No commands have been issued");
	if (elevate.size() == 1)
	{
		currentFloor = floorRequest;
		returnTime();
		elevate.erase(elevate.begin());
	}
	for (itr = elevate.begin(); itr < elevate.end(); itr++, i++) //iterates vector, processes requests
	{
		if (*itr < currentFloor && direction == "down")
		{
			int *temp;
			*temp = *itr;
			delete temp;
		}
	}
			
		/*if (floorRequest < currentFloor)// needs to search for numbers ranging between floorRequest to currentFloor, visit, delete from elevate
			{
				direction = "down";
				//floorDifference = currentFloor - floorRequest;
				//waitingTime = floorDifference + 0.5*stopCount;
				currentFloor -= floorRequest;
				

			}*/
	if (floorRequest > currentFloor)
	{
		direction = "up";
		floorDifference = floorRequest - currentFloor;
		currentFloor += floorRequest;
	}
}


int returnTime() 
{
	int timeCounter = 0;
	int stopCount = 0;
	int j = 0;

	if (elevate.size() == 1)
	{
		for (int i = 0; i <= elevate[elevate.front()]; i++)
		{
			//needs to keep track of stops
			timeCounter++;
			return timeCounter;
		}
	}
	// need to get front, iterate and see if anything is between it and where it's going, increment time accordingly
	vector<int>::iterator floorItr;
	for (floorItr = elevate.begin(); floorItr < elevate.end(); floorItr++, j++)
	{
		
	}
}
};
class outsideUser {
private:
	int waitingTime;
	string direction;
	outsideUser() {

	}
};
class User {
	int waitingTime;
	int Request;
	User() {
		Request = 0;
		waitingTime = 0;
	}

};