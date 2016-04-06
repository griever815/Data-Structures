#include "Cleric.h"



Cleric::Cleric(string newFighterName, string newFighterType, int newMaxHP, int newStrength, int newSpeed, int newMagic) : Fighter(newFighterName, newFighterType, newMaxHP, newStrength, newSpeed, newMagic)
{
	

	life_healed = Magic / life_ability_modifier;

}


Cleric::~Cleric()
{
}


//////GETTERS


/////Setters

int Cleric::getDamage()
{
	int magic_dealt = getMagic();

	int damage_dealt = magic_dealt;

	return damage_dealt;
}


void Cleric::reset()
{

	HitPoints = MaxHP;
	CurrentMana = MaxMana;

}


void Cleric::regenerate()
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


	ManaModifier = Magic / MANA_MULTIPLIER;
	if (ManaModifier < 1)
	{
		ManaModifier = 1;
	}
	else
	{
	}

	modifiedMana = CurrentMana + ManaModifier;
	
	if (modifiedMana > MaxMana)
	{
		CurrentMana = MaxMana;
	}
	else
	{
		CurrentMana = modifiedMana;
	}

}


bool Cleric::useAbility()
{


		if (CurrentMana >= CLERIC_ABILITY_COST)
		{
			if (HitPoints <= MaxHP)
			{
				if (MaxHP >= (HitPoints + life_healed))
				{
					CurrentMana = CurrentMana - CLERIC_ABILITY_COST;
					HitPoints = HitPoints + life_healed;

					return true;
				}
				else
				{

					CurrentMana = CurrentMana - CLERIC_ABILITY_COST;
					HitPoints = MaxHP;

					return true;
				}
			}
		}
		else
		{
			return false;
		}

		return false;
	
}