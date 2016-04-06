#pragma once
#include "FighterInterface.h"
#include <math.h>

class Fighter :
	public FighterInterface
{
protected:

	/*This is where all of the private data members go.*/

	string FighterName;
	string FighterType;

	int Strength;
	int Speed;
	int Magic;
	int MaxHP;

	int HitPoints;

	

	int modifiedMana;
	int modifiedHitPoints;

	int originalSpeed;

	int HPModifier;
	int ManaModifier;

	int MaxMana;
	int CurrentMana;

	const int STRENGTH_MODIFIER = 6;
	const int SPEED_MODIFIER = 4;
	const int MANA_MULTIPLIER = 5;
	const int BASE_DAMAGE = 1;
	const int life_ability_modifier = 3;
	const int ENERGY_MODIFIER = 4;
	const int MAGIC_ENERGY_CORRELATION = 2;
	const int RESET_BONUS_DMG = 0;

public:
	
	Fighter(string FighterName, string FighterType, int MaxHP, int Strength, int Speed, int Magic);

	~Fighter();



	/////GETTERS

	string getName();
	int getMaximumHP();
	int getCurrentHP();
	int getStrength();
	int getSpeed();
	int getMagic();
	virtual int getDamage() = 0;


	////SETTERS
	void takeDamage(int damageGiven);
	virtual void reset() = 0;
	virtual void regenerate() = 0;

	virtual bool useAbility() = 0;


	/////GENERAL
	//string toString();
};

