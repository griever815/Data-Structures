#include "Pathfinder.h"

using namespace std;

Pathfinder::Pathfinder()
{

	currentMaze [5][5][5];

	for (int i = 0; i < 5; ++i)
	{

		for (int j = 0; j < 5; ++j)
		{
			for (int k = 0; k < 5; ++k)
			{
				currentMaze [i][j][k] = 1;
			}
		}
	}
}

Pathfinder::~Pathfinder()
{

}

/*
Part 1 - Make Your Maze (5 points)
Generate a 3D maze (the storage facility) that measures 50' x 50' x 50' (5 levels with 25 cells on each level, a total of 125 cells)
and write it to a string in the format described below.To indicate whether one cell can be accessed from an adjacent cell,
randomly place roughly equiprobable 1s and 0s in each cell of the maze, except for the cell in the bottom level, first row,
and first column which contains a 1 (entry point), and the cell in the highest level, last row, and last column which also contains a 1 (exit point).
*/


string Pathfinder::getMaze()
{

//Part 1-----------------------------------------------------------------------------------
/*
* getMaze
*
* Returns a string representation of the current maze. Returns a maze of all 1s if no maze
* has yet been generated or imported.
*
* A valid string representation of a maze consists only of 125 1s and 0s (each separated
* by spaces) arranged in five 5x5 grids (each separated by newlines). A valid maze must
* also have 1s in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).
*
* Cell (0, 0, 0) is represented by the first number in the string representation of the
* maze. Increasing in x means moving toward the east, meaning cell (1, 0, 0) is the second
* number. Increasing in y means moving toward the south, meaning cell (0, 1, 0) is the
* sixth number. Increasing in z means moving downward to a new grid, meaning cell
* (0, 0, 1) is the twenty-sixth number. Cell (4, 4, 4) is represented by the last number.
*
* Returns:		string
*				A single string representing the current maze
*/

stringstream thisMaze;


for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			for (int k = 0; k < 5; ++k)
			{
				 thisMaze << currentMaze[i][j][k];
				 if (k < 4)
				 {
				 	thisMaze << " ";
				 }
			}
			thisMaze << "\n";
		}
		thisMaze << "\n";

	}

return thisMaze.str();
}


void Pathfinder::createRandomMaze()
{
/*
* createRandomMaze
*
* Generates a random maze and stores it as the current maze.
*
* The generated maze must contain a roughly equal number of 1s and 0s and must have a 1
* in the entrance cell (0, 0, 0) and in the exit cell (4, 4, 4).  The generated maze may be
* solvable or unsolvable, and this method should be able to produce both kinds of mazes.
*/
	int randomMaze [5][5][5];

	randomMaze[0][0][0] = 1;
	randomMaze[4][4][4] = 1;


	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			for (int k = 0; k < 5; ++k)
			{
				if (i == 0 && j == 0 && k == 0)	{}
			  else if (i == 4 && j == 4 && k == 4) {}
				else
				{
					randomMaze [i][j][k] = rand() % 2;
					currentMaze[i][j][k] = randomMaze[i][j][k];
				}
			}
		}
	}
}


/*
Part 2 - Import Mazes (5 points)
Accept a file name from the test driver and read a maze from that file in the indicated format.
Invalid mazes (e.g. bad tokens, not enough 1's and 0's) in the files should be rejected.
*/


bool Pathfinder::importMaze(string file_name)
{
//Part 2-----------------------------------------------------------------------------------
/*
* importMaze
*
* Reads in a maze from a file with the given file name and stores it as the current maze.
* Does nothing if the file does not exist or if the file's data does not represent a valid
* maze.
*
* The file's contents must be of the format described above to be considered valid.
*
* Parameter:	file_name
*				The name of the file containing a maze
* Returns:		bool
*				True if the maze is imported correctly; false otherwise
*/

int testMaze[5][5][5];
int counter = 0;
int insertToken;

ifstream in;

in.open(file_name);
if (!in.fail())
{

	int inputValue;
	stringstream ss;
	ss << file_name;

	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			for (int k = 0; k < 5; ++k)
			{
				if (in >> inputValue)
				{
					if (inputValue == 1 || inputValue == 0)
					{
						testMaze [i][j][k] = inputValue;
					}
					else
					{
						in.close();
						return false;
					}
				}
			}
		}
	}

	if (testMaze[0][0][0] == 1 && testMaze[4][4][4] == 1 && in.eof())
	{
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				for (int k = 0; k < 5; ++k)
				{
						currentMaze[i][j][k] = testMaze[i][j][k];
				}
			}
		}
		in.close();
		return true;
	}
		in.close();
		return false;
	}
	in.close();
	return false;
}





/*
Part 3 - Solve Yours (9) and Ours (9) (18 points)
Have your program attempt to recursively traverse the current maze to find a valid path.
A valid path is one which starts at the entrance (0, 0, 0) and ends at the exit (4, 4, 4) and does not contain any cycles.
When moving between cells, the divers can only move up, down, left, right, forward, and backwards one cell at a time.
No diagonals are allowed.
*/

bool Pathfinder::find(int i, int j, int k)
{
	stringstream ss;
	string insertVect;

	if (i < 0 || j < 0 || k < 0 || i > 4 || j > 4 || k > 4)
	{
		return false;
	}
	if (currentMaze[i][j][k] == 0 || currentMaze[i][j][k] == 2)
	{
		return false;
	}
	if (currentMaze[i][j][k] == 1)
	{
		currentMaze[i][j][k] = 2;
	}
	if (i == 4 && j == 4 && k == 4)
	{
		ss << "(" << i << ", " << j << ", " << k << ")";
		insertVect = ss.str();
		PathVector.insert(PathVector.begin(), insertVect);
		return true;
	}
	if (find(i-1, j, k) || find(i+1, j, k) || find(i, j-1, k) || find(i, j+1, k) || find(i, j, k-1) || find(i, j, k+1))
	{
		ss << "(" << i << ", " << j << ", " << k << ")";
		insertVect = ss.str();
		PathVector.insert(PathVector.begin(), insertVect);
		return true;
	}

	return false;
}




vector<string> Pathfinder::solveMaze()
{
//Part 3-----------------------------------------------------------------------------------
/*
* solveMaze
*
* Attempts to solve the current maze and returns a solution if one is found.
*
* A solution to a maze is a list of coordinates for the path from the entrance to the exit
* (or an empty vector if no solution is found). This list cannot contain duplicates, and
* any two consecutive coordinates in the list can only differ by 1 for only one
* coordinate. The entrance cell (0, 0, 0) and the exit cell (4, 4, 4) should be included
* in the solution. Each string in the solution vector must be of the format "(x, y, z)",
* where x, y, and z are the integer coordinates of a cell.
*
* Understand that most mazes will contain multiple solutions
*
* Returns:		vector<string>
*				A solution to the current maze, or an empty vector if none exists
*/

	PathVector.clear();
	bool result = find(0, 0, 0);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int k = 0; k < 5; k++)
			{
				if (currentMaze[i][j][k] == 2)
				{
					currentMaze[i][j][k] = 1;
				}
			}
		}
	}
if (result)
{
	return PathVector;
}
else
{
	vector<string> empty;
	return empty;
}

}
