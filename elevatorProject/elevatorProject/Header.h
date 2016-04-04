#pragma once
using namespace std;

//Constants:
int const MAXFLOOR = 8;
int const MINFLOOR = 1;
int const CAPACITY = 10;
int const MAXUSERS = 1200000;
////////////

//Eumerations
enum direction{UP, DOWN};
/////////////

//Prototype Definitions:
void simulation(Elevator elevator, vector<User>people);
////////////////////////