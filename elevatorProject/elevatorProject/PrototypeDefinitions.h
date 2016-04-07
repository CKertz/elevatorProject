// Elevator Project
// April 2016
// William Munshaw, Cooper Kertz, Amy Curtis
// File: PrototypeDefinitions.h

#pragma once

#include "Header.h"
#include "elevator.h"
#include "User.h"

using namespace std;

/*--------------------------------Prototype Definitions--------------------------------*/

void simulation(Elevator &elevator, vector<User> &peopleWait, vector<User> &peopleAccepted, vector<User> &peopleProgress, vector<User> &peopleDone);
void generateUser(vector<User> &people, int &total);
void incrementTimeAllUsers(vector<User> &people, bool didStop);
void deleteEntries(vector<User> &people, const vector<int> deletion);