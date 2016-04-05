#pragma once

#include "Header.h"
#include "elevator.h"
#include "User.h"

using namespace std;

/*--------------------------------Prototype Definitions--------------------------------*/

void simulation(Elevator elevator, vector<User>people, vector<User>arrivedList);
void generateUser(vector<User> people, int &total);
bool allUsersArrived(vector<User> people);
void incrementTimeAllUsers(vector<User> people, bool didStop);