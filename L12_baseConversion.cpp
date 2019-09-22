/*
Sean Masterson
Alina Suon
October 4, 2018
Purpose: To convert a decimal number to a different base.
Inputs: The number the user wants to convert and to what base.
Output: The converted number.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

//unsigned long long int getDecimal(const string& toDecimal, unsigned base);
string newBase(const unsigned long long int& decimal, unsigned int base);
string intToString(int input);
int get_int_value(const string& message, int min, int max);
//int stringToInt(const string& input);

int main(int argc, char** argv)
{
	int min = 0; // min value
	int max = 1000000000; // max value
	
	string prompt = "Please enter a value between " + intToString(min) + " and " + intToString(max) + ": "; // prompt
	
	cout << "Please enter the number to convert: ";
	
	unsigned long long int decimal = get_int_value(prompt, min, max);
	unsigned int base;
	
	do
	{
		min = 2;
		max = 16;
	
		cout << "Please enter the base to convert to: ";
		prompt = "Please enter a value between " + intToString(min) + " and " + intToString(max) + ": ";
		
		base = get_int_value(prompt, min, max);
		
		cout << "Decimal: " << decimal << " in base: " << base << " is: " << newBase(decimal, base) << endl;
		
		min = 0;
		max = 1000000000;
		
		cout << "Please enter the number to convert or 0 to exit." << endl;
		prompt = "Please enter a value between " + intToString(min) + " and " + intToString(max) + ": ";
		
		decimal = get_int_value(prompt, min, max);
		
	} while (decimal != 0); // Gets user input for number to convert and what base, then display it.
	
	/*
	
	*
	*
	*
	*
	*
	UNFINISHED - This part not required anyways.
	*
	*
	*
	*
	*
	
	min = 2;
	max = 16;
	
	cout << "Please enter a base for the first number to convert to base 10:"; 
	prompt = "Please enter a value between " + intToString(min) + " and " + intToString(max) + ": ";
	
	base = get_int_value(prompt, min, max);
	string toDecimal;
	
	do
	{
		cout << "Please enter a number to convert to base 10 or 0 to exit: ";
		prompt = "Please enter a base " + intToString(base) + " number: ";
		
		getline(cin, toDecimal);
		
		cout << "Decimal equivalent of " << toDecimal << " base " << base << " is " << 987654321 << "in decimal." << endl;
		
		
		
	} while (toDecimal != "-1");
	
	*/
	
	cout << "Completed Satisfactorily" << endl;
	return 0;
}

/*
unsigned long long int getDecimal(const string& toDecimal, unsigned base)
{
	if (toDecimal.length() == 0)
	{
		return 0;
	}
	
	int getMsb = stringToInt(toDecimal.substr(0,1));
	
	// pow(base, exponent);
	return getDecimal(toDecimal.substr(1), base) + pow(getMsb, toDecimal.length());
}
*/

/**
Converts a number of base 10 to a different base from 2 to 16.
@param	decimal		The decimal integer to be converted to a a different base.
@return				The integer as a string.
*/
string newBase(const unsigned long long int& decimal, unsigned int base)
{
	const string digits = "0123456789ABCEDF";
	unsigned long long int next = decimal / base;
	
	if (next == 0)
	{
		return digits.substr(decimal, 1);
	}
	else
	{
		string nextDigit = digits.substr(decimal % base, 1);
		string rest = newBase(next, base);
		return rest.append(nextDigit);
	}
}

/**
Converts an interger to a string
@param	input		The integer to be converted to a string.
@return				The integer as a string.
*/
string intToString(int input)
{
	stringstream ss;
	ss << input;
	return ss.str();
}

/*
/
Converts a string to integer
@param	input		The string to be converted to a integer.
@return				The string as an integer.

int stringToInt(const string& input)
{
	const string digits = "0123456789ABCEDF";
	
	char input2 = input[0];
	
	if (toupper(input2) == 'A')
		return 10;
	else if (toupper(input2) == 'B')
		return 11;
	else if (toupper(input2) == 'C')
		return 12;
	else if (toupper(input2) == 'D')
		return 13;
	else if (toupper(input2) == 'E')
		return 14;
	else
		return 15;
		
	stringstream value(input);
	int output;
	value >> output;
	return output;
}
*/

/**
Stored in repl.it as "int validate input"
This is a quick and effective way to prompt the user for an integer
from the console with a prompt, and a min and max boundary.  Other
datatypes are easily accommodated with this general form.  If you
use a C++ template, you only have to write this once, and it will
work for any numeric type.
@param	message	The prompt to give the user so that they know
		what they are entering.
@param	min	The minimum value accepted.
@param	max	The maximum value accepted.
@return		The value that the user finally gave us.
*/
int get_int_value(const string& message, int min, int max)
{
	int output;
	string input;

	while(true) {
		cout << message;
		getline(cin, input);	//read input as a string until user presses ENTER/RETURN
		if(cin) {		//if you read a string successfully...	
			stringstream extract(input);		//convert input to a new stream...
			if(extract >> output			//if the stream successfully converts to the intended type
				&& !(extract >> input)) { 	//and no input is left in the stream
				if (output < min || output > max) {
					cout << "Error, input not in range." << endl;
					// cout << "Error, " << input << " is not between " << min << " and " <<  max << endl;
				} else {			//The input is within range
					return output;
				}
			}
		}
		else cin.clear();											//flush the input buffer
		//cerr << "\nInvalid input. Please try again.\n"; 	//you didn't enter a valid value if you get here
	} //endless while loop that keeps prompting for a valid value
} //End of the get_int_value function
