#include "PathfinderInterface.h"
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#pragma once

class Pathfinder : public PathfinderInterface
{
private:

int currentMaze[5][5][5];
vector<string> PathVector;


public:

Pathfinder();
~Pathfinder();

string getMaze();
void createRandomMaze();
bool importMaze(string file_name);
vector<string> solveMaze();
bool find(int i, int j, int k);


};
