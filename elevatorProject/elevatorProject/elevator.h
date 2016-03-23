#pragma once
#include <queue>
#include <string>
using namespace std;

class elevator {
private:
	queue<int>elevate;
	bool Stop;
	int currentFloor;
	int floorDifference;
	int waitingTime;
	int stopCount;
	string direction;
public:

elevator() {
	Stop = false;
	currentFloor = 0;
	floorDifference = 0;
	waitingTime = 0;
	stopCount = 0;
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
		floorDifference = currentFloor - floorRequest;
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