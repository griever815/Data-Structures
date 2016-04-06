#pragma once
#include "RedRoverInterface.h"
#include "LinkedList.h"
#include "Player.h"

#include "PlayerInterface.h"

class RedRover :
	public RedRoverInterface
{
protected:

	


public:
	RedRover();
	~RedRover();

	LinkedList<Player*> RL;
	LinkedList<Player*> TAL;
	LinkedList<Player*> TBL;


	bool addToRoster(string player_list);
	int getRosterSize();
	int getTeamASize();
	int getTeamBSize();
	string getRoster();
	string getTeamA();
	string getTeamB();
	PlayerInterface* rosterAt(int index);
	PlayerInterface* teamAAt(int index);
	PlayerInterface* teamBAt(int index);
	void shuffleRoster();
	bool createTeams();
	void sendSomeoneOver(PlayerInterface* runner, PlayerInterface* defender);
	void teamReset();
	void rosterReset();
	void autoPlay();


	bool isNumber(string token);
	string choosePlayer(int game, string team);

};


