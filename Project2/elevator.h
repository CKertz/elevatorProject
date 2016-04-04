#pragma once
#include <queue>
#include <string>
using namespace std;

class elevator {
private:
	queue<int>elevate;
public:

	bool Stop = false;
	int currentFloor = 0;
	int floorDifference = 0;
	int waitingTime=0;
	int stopCount = 0;
	string direction;

elevator() {

}
int atDoor(int floor) {

}
int inputRequest(int floor) {
	elevate.push(floor);
} 
void elevating(int floorRequest, string givenDirection) {

	if (floorRequest < currentFloor)
	{
		direction = "down";
		currentFloor - floorRequest = floorDifference;
		waitingTime = floorDifference + 0.5*stopCount;
		currentFloor -= floorRequest;
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

	}
};