#include "Arena.h"
#include <fstream>
#include <sstream>



Arena::Arena()
{
};


Arena::~Arena()
{
};


bool Arena::removeFighter(string name)
{
	for (int i = 0; i < Fighter_List.size(); i++)
	{
		if (name == Fighter_List[i]->getName())
		{
			Fighter_List.erase(Fighter_List.begin() + i);
			return true;
		}

	}

	return false;
}

bool Arena::addFighter(string info)
{

	stringstream ss;

	ss << info;

	string name;
	string type;
	int Max_HP;
	int Strength;
	int Speed;
	int Magic;
	int Too_Many;

	const string ARCHER_TYPE = "A";
	const string ROBOT_TYPE = "R";
	const string CLERIC_TYPE = "C";

	ss >> name;
	for (int i = 0; i < Fighter_List.size(); i++)
	{
		if (name == Fighter_List[i]->getName())
		{
			return false;
		}
	}

	ss >> type;
	if (type == ARCHER_TYPE || type == ROBOT_TYPE || type == CLERIC_TYPE)
	{
		if (ss >> Max_HP >> Strength >> Speed >> Magic)
		{
			if (Max_HP > 0)
			{
				if (Strength > 0)
				{
					if (Speed > 0)
					{
						if (Magic > 0)
						{
							if (ss >> Too_Many)
							{
								return false;
							}
							ss.clear();
							if (type == ARCHER_TYPE)
							{
								Fighter* newArcher = new Archer(name, type, Max_HP, Strength, Speed, Magic);
								Fighter_List.push_back(newArcher);
								return true;

							}
							if (type == CLERIC_TYPE)
							{
								Fighter* newCleric = new Cleric(name, type, Max_HP, Strength, Speed, Magic);
								Fighter_List.push_back(newCleric);
								return true;

							}
							if (type == ROBOT_TYPE)
							{
								Fighter* newRobot = new Robot(name, type, Max_HP, Strength, Speed, Magic);
								Fighter_List.push_back(newRobot);
								return true;

							}
						}
					}
				}
			}
			
		}

	}

	else
	{
		return false;
	}

	return false;
}

FighterInterface* Arena::getFighter(string name)
{
	for (int i = 0; i < Fighter_List.size(); i++)
	{
		if (name == Fighter_List[i]->getName())
		{
			cout << "name: " << Fighter_List[i]->getName() << endl;
			return Fighter_List[i];
		}
	}

	return NULL;

}

int Arena::getSize()
{
	int numb_of_fighters;
	numb_of_fighters = Fighter_List.size();


	return numb_of_fighters;
}