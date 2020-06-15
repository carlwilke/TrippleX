// This code was created by:					Carl Wilke
// Date created:								Jun 13, 2020
// Date updated:								Jun 13, 2020
// ---------------------------------------------------------------------
// End Comment
#include <iostream>
#include <ctime>

using namespace std;

void PrintIntroduction(int Difficulty)
{
	cout << "\n\nYou are an operative breaking into a level " << Difficulty;
	cout << " secure server room... \nYou need to enter the correct pass-code to continue....\n\n";

}
bool PlayGame(int Difficulty)
{
	PrintIntroduction(Difficulty);
	
	const int CodeA = rand() % Difficulty + Difficulty;
	const int CodeB = rand() % Difficulty + Difficulty;
	const int CodeC = rand() % Difficulty + Difficulty;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;


	cout << endl;
	cout << "+ There are 3 numbers in the code" << endl;
	cout << "+ The codes add-up to: " << CodeSum << endl;
	cout << "+ The codes multiply to give: " << CodeProduct << endl;

	int GuessA, GuessB, GuessC;

	cin >> GuessA;
	cin >> GuessB;
	cin >> GuessC;

	cout << "You entered: " << GuessA << GuessB << GuessC << endl;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	if ((GuessSum == CodeSum) && (GuessProduct == CodeProduct))
	{
		cout << "** You retrieved all the files in this directory **";
		return true;
	}
	else
	{
		cout << "Retry the level again";
		return false;
	}
}

int main()
{
	int LevelDifficulty = 1;
	int const MaxDifficulty = 5;
	srand(time(NULL));

	while (LevelDifficulty <= MaxDifficulty)	// Loop game until all levels completed
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		cin.clear();		// Clear any errors
		cin.ignore();		// Discard the buffer
		if (bLevelComplete)
		{
			// Increase the level difficulty
			LevelDifficulty++;
		}
	}

	cout << " You managed to pass all the levels and now have full access to the network";
	
	return 0;
}