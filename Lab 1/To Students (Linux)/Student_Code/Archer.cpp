#include "Archer.h"



Archer::Archer(string newFighterName, string newFighterType, int newMaxHP, int newStrength, int newSpeed, int newMagic) : Fighter(newFighterName, newFighterType, newMaxHP, newStrength, newSpeed, newMagic)
{
	


}


Archer::~Archer()
{
}


//////GETTERS




/////Setters

int Archer::getDamage()
{
	int speed = getSpeed();

	int damage_dealt = speed;

	return damage_dealt;
}


void Archer::reset()
{

	HitPoints = MaxHP;
	Speed = originalSpeed;

}


void Archer::regenerate()
{
	HPModifier = Strength / STRENGTH_MODIFIER;
	if (HPModifier < 1)
	{
		HPModifier = 1;
	}
	else
	{
	}

	modifiedHitPoints = HitPoints + HPModifier;

	if (modifiedHitPoints > MaxHP)
	{
		HitPoints = MaxHP;
	}
	else
	{
		HitPoints = modifiedHitPoints;
	}
}


bool Archer::useAbility()
{

	
		Speed++;

		return true;
}