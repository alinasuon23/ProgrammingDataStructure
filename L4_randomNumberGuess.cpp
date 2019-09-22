/*	September 6, 2018
	Purpose: To allow a user to guess a number randomly generated with a max value specified by the user.
	Inputs: Max random number and user's guesses.
	Output: Whether the user's guess was correct and the maximum number of guesses needed which is log base 2 of the random number.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	long unsigned int seconds = time(0); // current time in seconds
	srand(seconds); // uses current time in seconds as seed
	
	long long maxNumber = 1000001; // Maximum number the user wants to guess. Default value of 1000001 to make while loop fail the first time.
		
	while (maxNumber > 1000000 || maxNumber < 0)
	{
		cout << "What is the maximum random number that you want to guess?" << endl;
		cin >> maxNumber;
		if (maxNumber > 1000000)
		{
			cout << "Please enter a valid positive integer < 1000000." << endl;
		}
		else if (maxNumber < 0)
		{
			cout << "Please enter a valid POSITIVE integer." << endl;
		}
	} // loop to get maximum random number and verify input is correct
		
	double maxNumberLog2 = log10(maxNumber) / log10(2); // maximum number in log 2
	cout << "Log base 2 of the maximum random number is: " << maxNumberLog2 << ".  MaxGuesses that you should need is: " << ceil(maxNumberLog2) << endl;
		
	long long randomNumber = rand() % (maxNumber + 1); // random number
	
	int numberOfGuesses = 0; // number of guesses made by user
		
	do
	{
		long long userGuess = -1; // number user guessed. Default value of -1 to make while loop fail the first time.
		
		while (userGuess < 0 || userGuess > maxNumber)
		{
			cout << "What is your next guess? ";
			cin >> userGuess;
			if (userGuess < 0)
				cout << "Please enter a valid POSITIVE integer." << endl;
			else if (userGuess > maxNumber)
				cout << "Please enter a valid positive integer < " << maxNumber << "." << endl;
		} // loop to get user's guess and make sure input is correct.
		
		++numberOfGuesses;
			
		if (userGuess > randomNumber)
			cout << "Your guess is greater than the random number, try again." << endl;
		else if (userGuess < randomNumber)
			cout << "Your guess is less than the random number, try again." << endl;
		else
		{
			cout << "Bingo!" << endl
				<< "You took " << numberOfGuesses << " guesses to get it." << endl
				<< "You were lucky!" << endl
				<< "Successfully completed." << endl;
			return 0;
		}
		if (numberOfGuesses == ceil(maxNumberLog2) + 1)
		{
			cout << "Failure. The number of guesses you made was larger than the max number of guesses you should need." << endl;
		}
			
			
	} while (true); // loop that gets user guesses
	
	return 0;
}


