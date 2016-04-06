#include "Fighter.h"



Fighter::Fighter(string newName, string newFighterType, int newMaxHP, int newStrength, int newSpeed, int newMagic)
{


	FighterName = newName;
	FighterType = newFighterType;
	MaxHP = newMaxHP;
	Strength = newStrength;
	Speed = newSpeed;
	Magic = newMagic;

	HitPoints = MaxHP;
	originalSpeed = Speed;


	MaxMana = Magic * MANA_MULTIPLIER;
	CurrentMana = MaxMana;

}


Fighter::~Fighter()
{


}

/*This is where where you define the functions that you made in the .h file. */

//////////GETTERS
string Fighter::getName()
{
	return FighterName;
}

int Fighter::getMaximumHP()
{
	return MaxHP;
}

int Fighter::getSpeed()
{


	return Speed;
}

int Fighter::getCurrentHP()
{
	return HitPoints;
}

int Fighter::getStrength()
{
	return Strength;
}



int Fighter::getMagic()
{
	return Magic;
}


/////////////SETTERS


void Fighter::takeDamage(int damageGiven)
{
	int damageModifier = (Speed / SPEED_MODIFIER);

	int damage_taken = damageGiven - damageModifier;

	if (damage_taken <= 0)
	{
		HitPoints = HitPoints - BASE_DAMAGE;
	}
	else
	{
		HitPoints = HitPoints - damage_taken;
	}


}




//////////GENERAL