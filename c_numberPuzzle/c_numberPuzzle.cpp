
#include <iostream>
#include <time.h>

// console input output hearder file.
// Header file that provides functions to input/output from the console.
#include <conio.h>

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	for (int i = 0; i < 24; ++i)
	{
		iNumber[i] = i + 1;
	}

	// INT_MAX in the last index of the array
	// INT_MAX is maximum value of int
	iNumber[24] = INT_MAX;

	// Create a variable to store where * is located.
	int iStarIndex = 24;

	// Shuffle indexes 0 to 23.
	int iTemp, idx1, idx2;

/*	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}*/
	while (true)
	{

		// Shuffle indexes 0 to 23.
		int iTemp, idx1, idx2;

		for (int i = 0; i < 100; ++i)
		{
			idx1 = rand() % 24;
			idx2 = rand() % 24;

			iTemp = iNumber[idx1];
			iNumber[idx1] = iNumber[idx2];
			iNumber[idx2] = iTemp;
		}

		// Check if it is right inversion.
		// Inversion must be even.
		int	iInversion = 0;

		for (int i = 0; i < 24; ++i)
		{
			for (int j = 0; j < 23; ++j)
			{
				if (iNumber[i] > iNumber[j + i + 1])
				{
					++iInversion;
				}

			}
		}
		if (iInversion % 2 == 0)
		{
//			cout << iInversion << endl;
			break;
		}
	}
	while (true)
	{
		system("cls");
		// The nurber of vertical spaces.
		for (int i = 0; i < 5; ++i)
		{
			// The number of squares.
			for (int j = 0; j < 5; ++j)
			{
				// Line number * Horizontal number + space number
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";

				else
					cout << iNumber[i * 5 + j] << "\t";
			}

			cout << endl;
		}
		
		bool	bWin = true;
		// Check if you have completed the puzzle.
		for (int i = 0; i < 24; ++i)
		{
			if (iNumber[i] != i + 1)
			{
				bWin = false;
				break;
			}
		}

		if (bWin == true)
		{
			cout << "You win" << endl;
		}

		cout << "w : Up, s : Down, a : Left, d : Right, q : Quit : ";
		// _getch() is function of receiving one character.
		// this function is even if you don't type enter, the moment you press the char, 
		// it returns the char and ends.
		char	cInput = _getch();

		if (cInput == 'q' || cInput == 'Q')
			break;

		switch (cInput)
		{
		case 'w':
		case 'W':
			// In the top row, do not move w.
			if (iStarIndex > 4)
			{
				// Put the value right above where * is.
				iNumber[iStarIndex] = iNumber[iStarIndex - 5];
				// Put * in the above position to replace the two values.
				iNumber[iStarIndex - 5] = INT_MAX;
				// Put the index one space above.
				iStarIndex -= 5;
			}
			break; 
		case's':
		case'S':
			// In the bottom row, do not move s.
			if (iStarIndex < 20)
			{
				iNumber[iStarIndex] = iNumber[iStarIndex + 5];
				iNumber[iStarIndex + 5] = INT_MAX;
				iStarIndex += 5;
			}
			break; 
		case'a':
		case'A':
			if (iStarIndex % 5 != 0)
			{
				iNumber[iStarIndex] = iNumber[iStarIndex - 1];
				iNumber[iStarIndex - 1] = INT_MAX;
				--iStarIndex;
			}
			break; 
		case'd':
		case'D':
			if (iStarIndex % 5 != 4)
			{
				iNumber[iStarIndex] = iNumber[iStarIndex + 1];
				iNumber[iStarIndex + 1] = INT_MAX;
				++iStarIndex;
			} 
			break; 
		default:
			break;
		}
	}

	cout << endl << "Quit the game." << endl;
	return 0;
}