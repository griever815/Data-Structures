#include <iostream>
#include <fstream>
#include <vector>
#include "LinkedList.h"
#include "Player.h"
#include "RedRover.h"
#include "Factory.h"
#include <ctime>


using namespace std;



int main()
{
	srand(time(0));
	bool flag = true;
	RedRover Red;

	while (flag)
	{

		cout << "\n\n-----------------------------------------\n";
		cout << "WELCOME TO JAKE'S AMAZING RED ROVER GAME!!!\n";
		cout << "-----------------------------------------";

		cout << "\n\n Do you want to: \n";
		cout << "1 - Add list of players to Roster\n";
		cout << "2 - Display all Players in Roster\n";
		cout << "3 - Roster Size\n";
		cout << "4 - Roster At\n";
		cout << "5 - Shuffle Roster\n";
		cout << "6 - Create Teams\n";
		cout << "7 - Show all teams and roster\n";
		cout << "8 - Team Reset\n";
		cout << "9 - Quit\n";
		cout << "10 - Play RedRover\n";

		cout << "\nPick and option: ";

		int option_selection;
		cin >> option_selection;

		string Team1 = "A";
		string Team2 = "B";

		if (!cin.fail())
		{
			if (option_selection == 1)/////Add to Roster
			{
				bool added = Red.addToRoster("Bam 11 5 George 3 14 Jake 44 b3 Bob 5 3 Sam 11 3 Tom 1a 44 Han 1 5 Luke 3 7 R2D2 8 3 C3P0 5 9 Chewbaca 9 6 Leia 10 2 Rand 1 10 Mat 3 9 Perrin 44 b3 Min 5 7 Lews 4 4 Faile 15 44");
			}
			if (option_selection == 2)////Show Roster
			{
				string readout = Red.getRoster();
				cout << readout << endl;
			}
			if (option_selection == 3)////Get Roster Size
			{
				int RostSize = Red.getRosterSize();
				cout << RostSize << endl;
			}
			if (option_selection == 4)////show roster at
			{
				cout << Red.rosterAt(2);

			}
			if (option_selection == 5)////Shuffle
			{
				Red.shuffleRoster();
			}
			if (option_selection == 6)////create teams
			{
				Red.createTeams();
			}
			if (option_selection == 7)////show teams and roster
			{
				string teamAlist = Red.getTeamA();
				string teamBlist = Red.getTeamB();
				string rosterList = Red.getRoster();

				cout << "\nTeam A: " << teamAlist << endl;
				cout << "Team B: " << teamBlist << endl;
				cout << "Roster: " << rosterList << endl;

			}
			if (option_selection == 8)////reset teams
			{
				Red.teamReset();
			}
			if (option_selection == 9)////Quit
			{
				flag = false;
			}
			if (option_selection == 10)////Send Someone Over
			{

				/*
				int randomSelect = rand() % 2;

				if (randomSelect == 0)
				{
					string chosenRunner = Red.choosePlayer(2, "A"); //// 2 means auto pick, 1 means manual pick.
					string chosenDefender = Red.choosePlayer(2, "B");
					cout << chosenRunner << endl;
					cout << chosenDefender << endl;

					int index1 = Red.TAL.findIndex(chosenRunner);
					int index2 = Red.TBL.findIndex(chosenDefender);
					Red.sendSomeoneOver(Red.teamAAt(index1), Red.teamBAt(index2));
				}
				else if (randomSelect == 1)
				{
					string chosenRunner = Red.choosePlayer(2, "B");
					string chosenDefender = Red.choosePlayer(2, "A");
					cout << chosenRunner << endl;
					cout << chosenDefender << endl;

					int index1 = Red.TBL.findIndex(chosenRunner);
					int index2 = Red.TAL.findIndex(chosenDefender);
					Red.sendSomeoneOver(Red.teamBAt(index1), Red.teamAAt(index2));
				}
				*/
				Red.autoPlay();
				
			}
			else
			{

			}

		}
		else
		{
			cout << "\nThat is not a valid option. Please pick a valid option.\n";
			cin.clear();
			cin.ignore();
		}
	
	}



	

	//system("pause");
	return 0;
}