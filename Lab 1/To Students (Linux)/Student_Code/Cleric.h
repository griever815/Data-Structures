#pragma once
#include "Fighter.h"
class Cleric :
	public Fighter
{
private:

	

	int life_healed;




public:
	Cleric(string newFighterName, string newFighterType, int newMaxHP, int newStrength, int newSpeed, int newMagic);

	~Cleric();


	//////GETTERS
	int getDamage();
	

	////SETTERS


	void reset();
	void regenerate();
	bool useAbility();



};

