#include "RedRover.h"
#include "LinkedList.h"

#include <sstream>



RedRover::RedRover()  /////When a RedRover is created, 3 LinkedListes are create with it. 1 for TeamA, TeamB, and the Roster.
{
	LinkedList<Player*> RL;   
	LinkedList<Player*> TAL;
	LinkedList<Player*> TBL;

}


RedRover::~RedRover()
{
}


bool RedRover::addToRoster(string player_list)
{
	/*
	* addToRoster()
	* Accepts a string containing the name, strength, and speed of several Players
	* and adds those Players to the roster.
	* The string will be of the format :
	* 			"PlayerName0
	* 			PlayerStrength0
	* 			PlayerSpeed0
	* 			PlayerName1
	* 			PlayerStrength1
	* 			..."
	* and so on with no trailing endline.
	* In the example above, Player0 would be the first entry in the roster followed by Player1 and any other Players.
	* You may assume that the format of the string and the name, strength, and speed of each player will be valid.
	* Returns true if players were added to the roster, false otherwise

	This function will accept a string containing the name, strength, and speed of each player who
	will be participating in the game. You may create your own string for testing purposes, but the TAs will
	use specific lists of players when grading your program. The string will contain a list of Players to be put
	on the roster. The format of the string will look something like this, with one token on each line:
	Kaylee
	25
	12
	Matt
	15
	20
	The first integer following a Player's name is that Player's strength. The second integer is that
	Player's speed. Using the information for each Player, create a new node and add it to the end of your
	roster. If there is a previously existing roster, add the new Players on to the end of the roster. You may
	assume that the string format will be correct. You may NOT assume that a string will contain an even
	number of players or that the string will not be empty. If an empty string is given, advise the user that
	no players have been added to the roster. You may allow multiple players with the same name to be
	placed in the roster.

	*/

	stringstream ss;
	ss << player_list;   ////Passes a string of players into an ss to be parsed out.

	string name;
	int speed;
	int strength;
	int count = 0;
	
	while (ss >> name) ////If in ss there is a string, then it passes into the loop.
	{
		if (ss >> strength >> speed) //// As long as the next 2 data memebers are ints, then it passes and a new Player is made.
		{
			Player* newPlayer = new Player(name, strength, speed);
			RL.insertTail(newPlayer);
			count++;
		}
		else
		{
			ss.clear();
		}
		
	}

	if (count > 0)
	{
		cout << endl << count << " Players have been added to the roster.\n" << endl;
		return true;
	}
	if (count <= 0)
	{
		cout << endl << count << " Players have been added to the roster.\n" << endl;
		return false;
	}

	
}


int RedRover::getRosterSize()
{
	/*
	*getRosterSize()
	*
	* Returns the number of players in the roster.
	*/

	return RL.size();
}

int RedRover::getTeamASize()
{
	/*
	*getTeamASize()
	*
	* Returns the number of players on Team A.
	*/

	return TAL.size();
}

int RedRover::getTeamBSize()
{
	/*
	* getTeamBSize()
	*
	* Returns the number of players on Team B.
	*/

	return TBL.size();
}


//////////////////////////////GETROSTER FUNCTIONS
/*These functions will return a string representation of all the names of the Players in the roster,
in Team A, or in Team B. The name at index 0 will be printed first, followed by the names associated
with the other indices in order. The name of each player should be separated by a single space and
there should be no trailing space at the end of the returned string. For example, if Team A had three
players named “Fred”, “Sam”, and “Carrot” the function getTeamA() would return:
“Fred Sam Carrot”
If the list is empty, the function should return the string “Roster empty”, “Team A empty”, or “Team B
empty”, whichever is appropriate.
*/

string RedRover::getRoster()
{
	/*
	* getRoster()
	*
	* Returns a string representing the players currently in the roster.
	* The returned string should be of the format
	* 		"Player0 Player1 Player2 ..."
	* Where Player0 is the Player located at index 0
	*
	* There should be no trailing space in the string returned
	*
	* Returns the string representation of the roster
	*/

	return RL.toString();
}

string RedRover::getTeamA()
{
	/*
	* getTeamA()
	*
	* Returns a string representing the players currently on Team A.
	* The returned string should be of the format
	* 		"Player0 Player1 Player2 ..."
	* Where Player0 is the Player located at index 0
	*
	* There should be no trailing space in the string returned
	*
	* Returns the string representation of Team A
	*/

	return TAL.toString();
}

string RedRover::getTeamB()
{
	/*
	* getTeamB()
	*
	* Returns a string representing the players currently on Team B.
	* The returned string should be of the format
	* 		"Player0 Player1 Player2 ..."
	* Where Player0 is the Player located at index 0
	*
	* There should be no trailing space in the string returned
	*
	* Returns the string representation of Team B
	*/

	return TBL.toString();
}


///////////////////////////AT Functions
/*Returns a pointer to the player located at the given index. If the index given is out of range,
instead returns NULL.
*Note: Your getSize() and At() functions will be used to determine the accuracy of your list. Make sure
that all of these functions work properly or we will be unable to grade your project appropriately
*/

PlayerInterface * RedRover::rosterAt(int index)
{
	/*
	* rosterAt()
	*
	* Returns a pointer to the player at the given index in the roster.
	* Returns NULL if the index is out of range
	*/
	if (index < 0)
	{
		return NULL;
	}

	Player* np = RL.at(index);
	return np;
}


PlayerInterface * RedRover::teamAAt(int index)
{
	/*
	* teamAAt()
	*
	* Returns a pointer to the player at the given index in Team A.
	* Returns NULL if the index is out of range
	*/
	if (index < 0)
	{
		return NULL;
	}


	Player* np = TAL.at(index);
	return np;
}


PlayerInterface * RedRover::teamBAt(int index)
{
	/*
	* teamBAt()
	*
	* Returns a pointer to the player at the given index in Team B.
	* Returns NULL if the index is out of range
	*/

	if (index < 0)
	{
		return NULL;
	}

	Player* np = TBL.at(index);
	return np;
}


void RedRover::shuffleRoster()
{
	/*
	* shuffleRoster()
	*
	* Shuffles the players in the roster
	* Does not affect the players in Team A or Team B

	This function will randomly shuffle the Players in your roster. Most students find it convenient
	to use the rand() function to implement their shuffle function. You will receive credit as long as the list is
	somewhat shuffled, but you will only receive half credit for simplistic shuffling like moving every Player
	down one, reversing the order of the list, etc. This function will not affect the order of players who are
	already in Team A or Team B.

	*/
	LinkedList<Player*> Shuff1;  //// I created 2 Linked Lists to shuffle my roster with.
	LinkedList<Player*> Shuff2;

	int random = rand() % 100; ////Generates a random number.
	int RosterSize = RL.size();
	int shuffleTimes = 171;
	for (int i = 0; i < random; i++) ////Shuffles the list the number of times of the random number.
	{
		while (RL.size() > 0)
		{
			for (int i = 0; i < RosterSize; i++)
			{
				if (i % 2 == 0) ////Just a different shuffle way to make it thorough. 
				{
					Player* AMember = RL.at(i);
					Shuff1.insertHead(AMember);

				}
				else////Just a different shuffle way to make it thorough. 
				{
					Player* BMember = RL.at(i);
					Shuff2.insertTail(BMember);
				}
			}
			for (int i = 0; i < RosterSize; i++)
			{
				RL.deleteHead(); ////Gets rid of Roster from the head.
			}
		}

		int TeamASize = Shuff1.size();
		int TeamBSize = Shuff2.size();
		while (Shuff1.size() > 0)
		{
			for (int i = 0; i < TeamASize; i++)
			{
				Player* AMember = Shuff1.at(i); ////Puts the LinkedList, now shuffled, back into Roster.
				RL.insertTail(AMember);
			}
			for (int i = 0; i < TeamASize; i++)
			{
				Shuff1.deleteHead();
			}
		}
		while (Shuff2.size() > 0)
		{
			for (int i = 0; i < TeamBSize; i++)////Puts the LinkedList, now shuffled, back into Roster.
			{
				Player* AMember = Shuff2.at(i);
				RL.insertHead(AMember);
			}
			for (int i = 0; i < TeamBSize; i++)
			{
				Shuff2.deleteHead();
			}
		}
	}
}


bool RedRover::createTeams()
{
	/*
	* createTeams()
	*
	* Divides the players in the roster into 2 teams, Team A and Team B
	*
	* The first player in the roster should be added to Team A, the second to Team B, and so on.
	* When a player is added to a team, that player is removed from the roster.
	*
	* Should not remove players from the roster or add them to a team if there are insufficient players in the roster to play the game
	* (there must be at least 2 players on each team in order to play).
	*
	* returns true if Team A and Team B are created successfully, false otherwise

	This function will divide the Players in the roster into two teams. When adding to the teams, you
	must insert at the end of the team's list (i.e. with a new index that is greater than all the existing
	indices). Every other Player will be assigned to a different team. The first Player in the roster will be
	added to Team A, the second Player to Team B, etc. When a Player is added to a team, he is removed
	from the roster. If the roster has an odd number of Players, omit the last Player (the last Player will
	remain on the roster). If the roster has less than 4 Players, do not remove any players from the roster
	and alert the user that no players have been added to the teams.


	*/

	int RosterSize = RL.size();

	if (RosterSize >= 4)
	{
		if (RosterSize % 2 == 0)////Then there are even numbers in the roster
		{
			while (RL.size() > 0)
			{
				for (int i = 0; i < RosterSize; i++)
				{
					if (i % 2 == 0) ////If the index is even, then it adds things to team A.
					{
						Player* AMember = RL.at(i);
						TAL.insertTail(AMember);

					}
					else
					{
						Player* BMember = RL.at(i); ////Else if the index is odd it adds to team B.
						TBL.insertTail(BMember);
						

					}
				}
				for (int i = 0; i < RosterSize; i++)
				{
					RL.deleteHead();  ////Removes from the roster as it adds to the teams.
				}
			}
		}
		else
		{
			while(RL.size() > 1) //// If there are odd members in Roster, then it leaves one in the roster.
			{
				for (int i = 0; i < RosterSize -1; i++)
				{
					if (i % 2 == 0)
					{
						Player* AMember = RL.at(i);
						TAL.insertTail(AMember);

					}
					else
					{
						Player* BMember = RL.at(i);
						TBL.insertTail(BMember);

					}
				}
				for (int i = 0; i < RosterSize -1; i++)////it leaves one in the roster.
				{
					RL.deleteHead();
				}
			}

		}
		return true;
	}
	
	return false;
}


void RedRover::sendSomeoneOver(PlayerInterface * runner, PlayerInterface * defender)
{
	/*
	* sendSomeoneOver()
	*
	* The Player "runner" is called over and attempts to break through the defender's defenses.
	*
	* The runner will always attempt to break the link between the defender and the next player in the defender's team.
	* If the defender is the last player in the team, the runner attempts to break the link between the last two players of the team.
	*
	* The runner is successful if the sum of his strength and speed exceeds the sum of the strengths of the defending players.
	*
	* If the runner is successful the stronger of the two players that he attempted to break through is added to the runner's team after the runner
	* If the runner does not break the link, the runner is added to the defender's team after the defender
	*
	* The names of Players will be unique, they will not exist in more than one team.
	*
	* If the runner and the defender are on the same team or if one of the players cannot be located, does nothing
	* If either the runner or the defender is NULL, does nothing

	This function operates as follows:
	1. The first player (the runner) will be located in either Team A or Team B, and the second player (the
	defender) will be located in the other team.
	2. The runner will attempt to break through the link held by the defender and his successor. The link
	that the runner attempts to break will always be between the defender and the next player in the list
	unless the defender is the last player in the list, at which point the runner will attempt to break the link
	between the last two players. For example,
	Team A: Calvin, Matt, Jason, Yazan
	Runner: Matt
	Team B: Kaylee, Jacob, Trent, Trevor
	Defender: Trent
	In this example, Matt will attempt to break the link between Trent and Trevor. The link is broken if the
	sum of Matt’s strength and speed exceeds the sum of Trent and Trevor's strength. If the link is broken
	then Matt returns to his original index on his team. The stronger Player associated with the link that was
	broken becomes a part of Matt’s team and is inserted after Matt. If the link is not broken then Matt
	becomes part of Team B and is inserted after Trent, between Trent and Trevor.
	If the attack results in either team winning then a message should be displayed showing the
	members of the winning team and alerting the user that a team has won and the game is over. For
	example if the teams were as follows:
	Team A: Riku, Ansem
	Team B: Sora, Kairi, Namine, Olette
	If Olette is called over to Team A and breaks through the link then the stronger of the two
	players in Team A would be added to Team B. If Ansem had a higher strength than Riku the teams
	would look like this after the attack was over:
	Team A: Riku
	Team B: Sora, Kairi, Namine, Olette, Ansem
	The function should then display something like the following:
	“Team B wins! Sora, Kairi, Namine, Olette, Ansem.”
	*/
	bool foundA = TAL.findPlayer(defender->getName());  ////These find functions make it so if it shows up in one Team, it wont show up in the other.
	bool foundB = TBL.findPlayer(defender->getName());
	bool foundRunnerA = TAL.findPlayer(runner->getName());
	bool foundRunnerB = TBL.findPlayer(runner->getName());

	int RunnerForce = runner->getStrength() + runner->getSpeed();
	int runnerIndex;
	int defendingIndex;
	int TotalDEFIndex;
	int DefendingForce;   ///////////These are just different numbers made from the stats of the players so I can add them to the correct list.
	int Defender1Strength;
	int Defender2Strength;

	if (foundA && foundRunnerA)
	{
		cout << "runner and defender from the same team.";
		return;
	}
	if (foundB && foundRunnerB)
	{	
		cout << "runner and defender from the same team.";
		return;
	}
	if (!foundA && !foundB)
	{
		cout << "defender not found";
		return;
	}
	if (!foundRunnerA && !foundRunnerB)
	{
		cout << "Runner not found";
		return;
	}

	if (foundA) ////If the defender was found in TeamA, then the runner will be pulled from team B.
	{
		defendingIndex = TAL.findIndex(defender->getName());
		TotalDEFIndex = TAL.size() - 1;
		runnerIndex = TBL.findIndex(runner->getName());

		if (defendingIndex < TotalDEFIndex) ////THis checks if the defender is the tail or not. 
		{
			DefendingForce = defender->getStrength() + TAL.at(defendingIndex + 1)->getStrength();
			
			Defender1Strength = defender->getStrength();
			Defender2Strength = TAL.at(defendingIndex + 1)->getStrength();
			if (RunnerForce > DefendingForce) ////If the runner breaks through
			{
				if (Defender1Strength > Defender2Strength)  ////IF the first defender is stronger than the second, the first gets taken.
				{
					TBL.insertAfter(TAL.at(defendingIndex), TBL.at(runnerIndex));
					TAL.remove(TAL.at(defendingIndex));
				}
				if (Defender1Strength < Defender2Strength) ////IF the second defender is stronger than the first, the second gets taken.
				{
					TBL.insertAfter(TAL.at(defendingIndex +1), TBL.at(runnerIndex));
					TAL.remove(TAL.at(defendingIndex));
				}
			}
			if (RunnerForce < DefendingForce) //if the runner does not break through. 
			{

				TAL.insertAfter(TBL.at(runnerIndex), TAL.at(defendingIndex));
				TBL.remove(TBL.at(runnerIndex));
				
			}
		}
		if (defendingIndex == TotalDEFIndex) ////////THis is if the defender is the tail end of the list.
		{
			DefendingForce = defender->getStrength() + TBL.at(defendingIndex - 1)->getStrength();
			Defender1Strength = defender->getStrength();
			Defender2Strength = TBL.at(defendingIndex - 1)->getStrength();

			if (RunnerForce > DefendingForce)  //////////If the runner breaks through
			{
				if (Defender1Strength > Defender2Strength)  ///////Calculates which defender gets taken.
				{
					TBL.insertAfter(TAL.at(defendingIndex), TBL.at(runnerIndex));
					TAL.remove(TAL.at(defendingIndex));
				}
				if (Defender1Strength < Defender2Strength) ///////Calculates which defender gets taken.
				{
					TBL.insertAfter(TAL.at(defendingIndex - 1), TBL.at(runnerIndex));
					TAL.remove(TAL.at(defendingIndex - 1));
				}
			}
			if (RunnerForce < DefendingForce) ////If the runner fails to break through.
			{
				TAL.insertAfter(TBL.at(runnerIndex), TAL.at(defendingIndex - 1));
				TBL.remove(TBL.at(runnerIndex));
			}
		}
	}
	if (foundB)////If the defender was found in TeamA, then the runner will be pulled from team B.
	{
		defendingIndex = TBL.findIndex(defender->getName());
		TotalDEFIndex = TBL.size() - 1;
		runnerIndex = TAL.findIndex(runner->getName());

		if (defendingIndex < TotalDEFIndex)////THis checks if the defender is the tail or not. 
		{
			DefendingForce = defender->getStrength() + TBL.at(defendingIndex + 1)->getStrength();
			Defender1Strength = defender->getStrength();
			Defender2Strength = TBL.at(defendingIndex + 1)->getStrength();
			if (RunnerForce > DefendingForce)////If the runner breaks through
			{
				if (Defender1Strength > Defender2Strength)////IF the first defender is stronger than the second, the first gets taken.
				{
					TAL.insertAfter(TBL.at(defendingIndex), TAL.at(runnerIndex));
					TBL.remove(TBL.at(defendingIndex));
				}
				if (Defender1Strength < Defender2Strength)////IF the second defender is stronger than the first, the second gets taken.
				{
					TAL.insertAfter(TBL.at(defendingIndex + 1), TAL.at(runnerIndex));
					TBL.remove(TBL.at(defendingIndex));
				}
			}
			if (RunnerForce < DefendingForce)
			{
				if (Defender1Strength > Defender2Strength)
				{
					TBL.insertAfter(TAL.at(runnerIndex), TBL.at(defendingIndex));
					TAL.remove(TAL.at(runnerIndex));
				}
				if (Defender1Strength < Defender2Strength)
				{
					TBL.insertAfter(TAL.at(runnerIndex), TBL.at(defendingIndex + 1));
					TAL.remove(TAL.at(runnerIndex));
				}
			}
		}
		if (defendingIndex == TotalDEFIndex)  //////This is if the defender is the tail.
		{
			DefendingForce = defender->getStrength() + TBL.at(defendingIndex - 1)->getStrength();
			Defender1Strength = defender->getStrength();
			Defender2Strength = TBL.at(defendingIndex - 1)->getStrength();

			if (RunnerForce > DefendingForce)  ////If the runner breaks through.
			{
				if (Defender1Strength > Defender2Strength)  
				{
					TAL.insertAfter(TBL.at(defendingIndex), TAL.at(runnerIndex));////IF the first defender is stronger than the second, the first gets taken.
					TBL.remove(TBL.at(defendingIndex));
				}
				if (Defender1Strength < Defender2Strength)
				{
					TAL.insertAfter(TBL.at(defendingIndex - 1), TAL.at(runnerIndex));////IF the first defender is stronger than the second, the first gets taken.
					TBL.remove(TBL.at(defendingIndex - 1));
				}
			}
			if (RunnerForce < DefendingForce)
			{
				TBL.insertAfter(TAL.at(runnerIndex), TBL.at(defendingIndex - 1));
				TAL.remove(TAL.at(runnerIndex));
			}
		}
	}
		

}


////////////////////RESET Functions
/*
teamReset() empties the players from both teams, but does nothing to the Roster. After
teamReset() is called there should be no players remaining in either Team A or Team B. rosterReset()
empties the Players from the roster but does nothing to the players in Team A or Team B.
*/

void RedRover::teamReset()
{
	/*
	* teamReset()
	*
	* Empties both teams (does not affect the roster)
	*/


	TAL.clear();
	TBL.clear();
}


void RedRover::rosterReset()
{
	/*
	* rosterReset()
	*
	* Empties all players from the roster
	* (does nothing to Team A or Team B)
	*/
	RL.clear();
}


void RedRover::autoPlay()
{
	/*
	* autoPlay()
	*
	* Simulates a game of Red Rover and notifies the user of the winning team.
	*
	* Selects a random player from one team to attempt to break through a random player from the other team until one team has won.
	*
	* Starting with Team A, teams take turns attempting to break through.
	*
	* When the function ends, both teams should be emptied.
	*
	* this function returns nothing, but it MUST print out
	* 		the name of the runner
	* 		the name of the defender and
	* 		the players on each team
	* after each attempt to break through.
	*
	* At the end of the game, print out the name of the winning team and the players on both teams.

	This function will simulate a game of Red Rover. Starting with Team A, your program randomly
	selects a player to try to break a randomly selected link of the other team. Between each turn, display
	the names of Players currently on Team A and Team B. The function continues to play the game until
	either Team A or Team B has exactly one player left. At the end of play, display the name and players of
	the winning team, and then empty both teams. If there are insufficient players in Team A or in Team B,
	alert the user by displaying a message. If you do not wish to implement this function, you should simply
	leave it empty (e.g. you could write “autoPlay() {};” )


	*/

	while (TAL.size() > 1 && TBL.size() > 1)  ////It will continue this loop for as long as there is at least 2 people in each team.
	{
		int randomSelect = rand() % 2; ////Randomly selects which team calls for someone to come over.

		if (randomSelect == 0)
		{
			string chosenRunner = choosePlayer(2, "A");
			string chosenDefender = choosePlayer(2, "B");
		

			int index1 = TAL.findIndex(chosenRunner);
			int index2 = TBL.findIndex(chosenDefender);
			sendSomeoneOver(teamAAt(index1), teamBAt(index2));
			cout << "\nTeam A: " << TAL.toString() << endl;
			cout << "Team B: " << TBL.toString() << endl;
		}
		else if (randomSelect == 1)////Randomly selects which team calls for someone to come over.
		{
			string chosenRunner = choosePlayer(2, "B");
			string chosenDefender = choosePlayer(2, "A");


			int index1 = TBL.findIndex(chosenRunner);
			int index2 = TAL.findIndex(chosenDefender);
			sendSomeoneOver(teamBAt(index1), teamAAt(index2));
			cout << "\nTeam A: " << TAL.toString() << endl;
			cout << "Team B: " << TBL.toString() << endl;
		}
	}

	

}


string RedRover::choosePlayer(int game, string team)
{
	string ChosenOne;
	int randomIndex = 0;

	if (game == 1) ////Manually pick a player
	{
		if (team == "A")
		{
			cout << "Pick a player" << endl;
			cout << TAL.toString() << endl;
			cin >> ChosenOne;

			
				bool found = TAL.findPlayer(ChosenOne); ////CHekcs to make sure that the player you picked exists in this Team
				int index = TAL.findIndex(ChosenOne);
				if (found == true)
				{
					return TAL.at(index)->getName();
				}
		
			return "That is not a valid name";

		}
		else
		{
			cout << "Pick a player" << endl;
			cout << TBL.toString() << endl;
			cin >> ChosenOne;

			bool found = TBL.findPlayer(ChosenOne);////CHekcs to make sure that the player you picked exists in this Team
			int index = TBL.findIndex(ChosenOne);
			if (found == true)
			{
				return TBL.at(index)->getName();
			}

			return "That is not a valid name";
		}
	
	}
	if (game == 2) ////Autopick
	{
		if (team == "A")
		{
			randomIndex = rand() % TAL.size();
			return TAL.at(randomIndex)->getName();
			 
		}
		if (team == "B")
		{
			randomIndex = rand() % TBL.size();
			return TBL.at(randomIndex)->getName();
		}


	}

}
