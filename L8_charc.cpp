/* 
Sean Masterson
Alina Suon
September 20, 2018
Purpose: This program is used to count the number of each character the user entered
Input: What the user types
Output: The number of each character entered
*/

#include <iostream>
#include <cstring>

using namespace std;

const int ALPHABET_LENGTH = 26; // Number of letters in the alphabet
const int MAX_INPUT_LENGTH = 81; // Maximum length that the user can input, plus one for the null character
const char ALPHABET[ALPHABET_LENGTH] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
										'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
										'U', 'V', 'W', 'X', 'Y', 'Z'}; // The alphabet
										
void countChar(char letters[MAX_INPUT_LENGTH], int length, int charCount[ALPHABET_LENGTH + 1]);
int letterIndex(char letter);

int main(int argc, char** argv) {
	char userInput[MAX_INPUT_LENGTH]; // C-string to contain user input
	
	do
	{
		cout << "Please enter the next string to evaluate or null to exit." << endl;
		cin.getline(userInput, MAX_INPUT_LENGTH);
		
		cin.clear();
		cin.sync();
		
		int charCount[ALPHABET_LENGTH + 1] = {0}; // Array of ints corresponding to number of times each letter of alphabet is present, plus 1 for 'other'
		
		countChar(userInput, strlen(userInput), charCount);
		
	} while (strlen(userInput) != 0); // Gets C-string to evaluate from user and calls function that evaluates string and print results of evaluation.
	
	cout << "Completed satisfactorily" << endl;
	
	return 0;
}

/**
Counts the number of characters in a c-string and stores it in a parallel array
@param letters		C-string that contains user input
@param length		The length of the C-string
@param charCount	Array of ints corresponding to number of times each letter of alphabet is present, plus 1 for 'other'	
*/
void countChar(char letters[MAX_INPUT_LENGTH], int length, int charCount[ALPHABET_LENGTH + 1])
{
	for (int i = 0; i < length; ++i)
	{
		if (letterIndex(letters[i]) >= 0 && letterIndex(letters[i]) < ALPHABET_LENGTH)
			++charCount[letterIndex(letters[i])];
		else
			++charCount[ALPHABET_LENGTH];
	} // Counts number of times each letter of alphabet appears, including non-alphabet chars as 'other'
	
	for (int i = 0; i < ALPHABET_LENGTH; ++i)
	{
		if (charCount[i] > 0)
			cout << "Letter: " << ALPHABET[i] << " occurred " << charCount[i] << " times." << endl;
	} // Displays number of times each letter of alphabet appears if > 0
	
	if (charCount[ALPHABET_LENGTH] > 0)
		cout << "Letter: other occurred " << charCount[ALPHABET_LENGTH] << " times." << endl;
}

/**
Finds index a letter of the alphabet is from 0 to 25
@param letter		A letter of the alphabet
@return				What index it is in the alphabet from 0 to 25
*/
int letterIndex(char letter)
{
	return (toupper(letter) - 'A');
}
