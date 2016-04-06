#include "Player.h"



Player::Player(string newName, int newStrength, int newSpeed)
{
	Name = newName;
	Strength = newStrength;
	Speed = newSpeed;
}

Player::~Player()
{
}


string Player::getName()
{
	/*
	* getName()
	*
	* returns the name of the player
	*/

	return Name;

}


int Player::getStrength()
{
	/*
	*getStrength()
	*
	*returns the strength of the player
	*/

	return Strength;

}


int Player::getSpeed()
{
	/*
	*getSpeed()
	*
	*returns the speed of the player
	*/

	return Speed;

}


