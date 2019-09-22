/*
Sean Masterson
Alina Suon
September 27, 2018
Purpose: To check whether a string the user types is a palindrome.
Inputs: String the user types
Output: Whether the string the user types is a palindrome
*/

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& input, int begin, int end);
bool isPalindrome(const string& input);

int main(int argc, char** argv)
{
	string userInput; // Stores user input
	
	do
	{
		cout << "Enter the next possible palindrome: ";
		getline(cin, userInput);
		
		if (userInput != "")
		{
		
			if (isPalindrome(userInput))
			{
				cout << userInput << " is a palindrome!" << endl;
			}
			else
			{
				cout << userInput << " is NOT a palindrome." << endl;
			}
		}
	} while (userInput != ""); // Gets user input for string to check whether its a palindrome
	
	cout << "Completed successfully";
	
	return 0;
}

/**
 * To determine whether a string is a palindrome
 * @param    input                The string to check whether it's a palindrome
 * @param    begin                The index of the first character in the string
 * @param    end                  The index of the last character in the string
 * @return                  	  Whether the input is a palindrome
 */
bool isPalindrome(const string& input, int begin, int end)
{
	if (begin >= end)
	{
		return true;
	}
	else
	{
		while (begin < end && !isalpha(input[begin]))
		{	
			++begin;
		} // Increment start position
		
		while (begin < end && !isalpha(input[end]))
		{
			--end;
		} // decrement end position
		
		if (begin <= end)
		{
			if (tolower(input[begin]) == tolower(input[end]))
			{
				return isPalindrome(input, begin + 1, end - 1);
			}
			else
			{
				return false;
			}
			
		}
		
		else
		{
			return true;
		}
	}
}

/**
 * To determine whether a string is a palindrome, using a palindrome helper function
 * @param    input                The string to check whether it's a palindrome
 * @return                  	  Whether the input is a palindrome
 */
bool isPalindrome(const string& input)
{
	return isPalindrome(input, 0, input.length() - 1);
}
