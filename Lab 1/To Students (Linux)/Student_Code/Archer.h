#pragma once
#include "Fighter.h"
class Archer :
	public Fighter
{
private:
	int Damage;

public:
	Archer(string FighterName, string FighterType, int MaxHP, int Strength, int Speed, int Magic);
	~Archer();


	//////GETTERS
	int getDamage();
	

	////SETTERS


	void reset();
	void regenerate();
	bool useAbility();



};

