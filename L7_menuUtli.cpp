/*	September 18, 2018
	Purpose: Display a list of items in a string array.
	Inputs: The string array with the menu options and which option the user wants
	Output: Whether the option the user entered is valid and if it is, which option they entered.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int menu(string options [], int nItems);
int width(int maxPositive);
int validInt (const string& prompt, int min, int max, string options[], int validInt);

int main() {
	string menuOptions [] = {"Go to the park", "Walk the dog", "Get ice cream",
							 "Do homework", "Mow the lawn", "Wash my car", "Go on a date",
							 "Visit Grandma", "Clean the garage", "Watch TV"}; // The array with the menu options
	int option = menu(menuOptions, 10); // Which option the user entered
	cout << "Option selected was: " << option << ": " << menuOptions[option] << endl;
	string * sArray;
	sArray = menuOptions;
	cout << "Completed satisfactorily" << endl; // prints Completed satisfactorily
	return 0;
}

/**
 * Show menu options based on elements in options array
 * @param	options[]	The string array with the menu options.
 * @param	nItems		The number of elements in array.
 * @return				The value retrieved from the user.
 */
int menu(string options[], int nItems)
{
	int spacing = width(nItems); // How many spaces the numbers should be right-aligned
	
	for (int i = 0; i < nItems; ++i)
	{
		cout << setw(spacing) << i << " " << options[i] << endl;
	}
	
	int userInput = validInt("Please enter menu selection -->", 0, nItems - 1, options, nItems); // Gets user input from 0 to nItems - 1
	
	return userInput;
}

/**
 * Calculate the spacing needed to display the menu number options.
 * @param	maxPositive	The maximum integer that will be displayed
 * @return				The number of spaces to display the menu options.
 */
int width(int maxPositive)
{
	int spacing = ceil(log10(maxPositive)); // Calculates the number of spaces the numbers should be right-aligned
	return spacing;
}

/**
 * Using cin to validate the user integer input.
 * @param	prompt		The string used to prompt the user for the input.
 * @param	min			The lowest acceptable value.
 * @param	max			The highest acceptable value.
 * @return				The value retrieved from the user.
 */
int validInt (const string& prompt, int min, int max, string options[], int nItems) {
	int inputValue;
	string junk;					//disposal area for bad input
	bool error = false; // Stores whether the integer was valid.
	while (true) {
		
		if (error)
			cout << "Invalid integer.  Try again -->";
		else
			cout << prompt;
			
		cin >> inputValue;
		if (cin.fail()) {
			
			error = true;
			
			cin.clear();
			getline (cin, junk);
			continue;
		} else {
			//At least some of the input was valid.
			getline (cin, junk);	//scoop up the rest of the input if any
			if (junk.size() > 1) {
				cout << "Part of your input was valid, part not.  Start over." << endl;
				continue;
			}
		}
		if (inputValue < min || inputValue > max) {
			
			
			cout << "Error, " << inputValue <<
					" is not between " << min << " and "
					<< max << ".  Try again." << endl;
			
			
			// re-display menu
			int spacing = width(nItems); // How many spaces the numbers should be right-aligned
	
			for (int i = 0; i < nItems; ++i)
			{
				cout << setw(spacing) << i << " " << options[i] << endl;
			}
			continue;
		}
		break;
	}
	return inputValue;
}
