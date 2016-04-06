#pragma once
#include "Fighter.h"
class Robot :
	public Fighter
{
private:


	int Max_Energy; 
	double Energy;


	double damage_modifier;
	int bonus_damage;
	int Damage_done;
	int Total_Damage_Dealt;

public:
	Robot(string newFighterName, string newFighterType, int newMaxHP, int newStrength, int newSpeed, int newMagic);
	~Robot();




	//////GETTERS
	int getDamage();
	


	////SETTERS


	void reset();
	void regenerate();
	bool useAbility();

};

