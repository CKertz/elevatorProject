#pragma once

#include "Header.h"
#include "elevator.h"
#include "User.h"

using namespace std;

/*--------------------------------Prototype Definitions--------------------------------*/

void simulation(Elevator elevator, vector<User>people);
bool generateUser(vector<User> people);
bool allUsersArrived(vector<User> people);
void incrementTime(vector<User> people, bool didStop);