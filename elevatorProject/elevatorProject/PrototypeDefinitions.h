#pragma once

#include "Header.h"
#include "elevator.h"
#include "User.h"

using namespace std;

/*--------------------------------Prototype Definitions--------------------------------*/

void simulation(Elevator elevator, vector<User>people, vector<User>arrivedList);
bool generateUser(vector<User> people);
bool allUsersArrived(vector<User> people);
void incrementTimeAllUsers(vector<User> people, bool didStop);