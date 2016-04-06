#pragma once
#include "PlayerInterface.h"
#include "LinkedList.h"
#include <string>

class Player :
	public PlayerInterface
{
private:

	string Name;
	int Strength;
	int Speed;


public:
	Player(string newName, int newStrength, int newSpeed);
	~Player();


	string getName();
	int getStrength();
	int getSpeed();

};

