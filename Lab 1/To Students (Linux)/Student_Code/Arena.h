#pragma once
#include "ArenaInterface.h"

#include "Archer.h"
#include "Robot.h"
#include "Cleric.h"

#include <fstream>
#include <vector>



class Arena :
	public ArenaInterface
{

protected:
	vector<Fighter*> Fighter_List;



public:
	Arena();

	~Arena();


	///////////GETTERS

	FighterInterface* getFighter(string name);
	int getSize();



	///////////SETTERS
	bool removeFighter(string name);
	bool addFighter(string info);

};

