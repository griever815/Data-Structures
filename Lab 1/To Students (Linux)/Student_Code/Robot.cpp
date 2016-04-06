#include "Robot.h"
#include <math.h>



Robot::Robot(string FighterName, string FighterType, int MaxHP, int Strength, int Speed, int Magic) : Fighter(FighterName, FighterType, MaxHP, Strength, Speed, Magic)
{
	Max_Energy = Magic * MAGIC_ENERGY_CORRELATION;
	Energy = Max_Energy;


	Damage_done = Strength;
	Total_Damage_Dealt = Strength;


	
}


Robot::~Robot()
{
}


//////GETTERS



/////Setters

int Robot::getDamage()
{
	
	return Total_Damage_Dealt;
}


void Robot::reset()
{

	HitPoints = MaxHP;
	Energy = Max_Energy;
	bonus_damage = RESET_BONUS_DMG;

}


void Robot::regenerate()
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


bool Robot::useAbility()
{
	

	if (Energy >= ROBOT_ABILITY_COST)
	{
		damage_modifier = (Strength * (pow((Energy / Max_Energy), ENERGY_MODIFIER)));

		//cout << "*****" << FighterName << "  Damage:" << Total_Damage_Dealt << "  Damage Modifier:" << damage_modifier << "  Bonus Damage:" << bonus_damage << "  Energy:" << Energy << endl;

		bonus_damage = damage_modifier;

		Total_Damage_Dealt = Damage_done + bonus_damage;
		Energy = Energy - ROBOT_ABILITY_COST;

		
		return true;
	
	}
	else
	{
		Total_Damage_Dealt = Damage_done;

		return false;
	}
}