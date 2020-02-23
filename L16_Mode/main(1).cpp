/*  Sean Masterson
    Alina Susan
    October 23, 2018
    Purpose: Gets a list of elements from user input, store them in an array, and finds the mode of that array.
    Inputs: The size of the array and the elements in it.
    Output: The mode.
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct freq
{
	int value; // The value.
	int frequency; // The frequency of the value.
};

bool findFreq(vector<freq>& frequencies, int value, int& frequency);
vector<freq> mode(int* inputArray, int nValues);
int get_int_value(string message, int min, int max);

const int MAX_LENGTH = 100; // Maximum length of the array.

int main(int argc, char** argv)
{
	string message; // Message to display to the user.
	string userInput; // User input.
	const int min = 1; // Minimum allowable integer value from user.
	
	do
	{
		
		int numberOfValues; // Number of values to go in array.
		message = "How many values --> ";
		numberOfValues = get_int_value(message, min, MAX_LENGTH);
		//cin >> numberOfValues;
		
		int elements = 0; // Current number of elements in the array.
		int values[MAX_LENGTH]; // The array.
		
		while (elements < numberOfValues)
		{
			int nextValue; // The value to be added to array.
			message = "Enter the next value --> ";
			nextValue = get_int_value(message, min, MAX_LENGTH);
			values[elements] = nextValue;
			++elements;
		}
		
		vector<freq> theMode = mode(values, elements); // The vector of freqs containing the mode.
		
		for (int i = 0; i < theMode.size(); ++i)
		{
			cout << "The next value/frequency is: " << theMode[i].value << "/" << theMode[i].frequency << endl;
		} // Display all of the modes.
		
		cout << "Continue (y/n) --> ";
		getline(cin, userInput);
	
	} while(userInput == "y"); // Gets elements in array from user input and finds the mode.
	
	cout << "Completed satisfactorily";
	
	return 0;
}

/*
Find value within a vector of frequency and stores the frequency of that value in 'frequency' and returhs true if found, false otherwise.
@param frequencies		The vector of frequencies to search for the value in
@param value			The value (frequency) to search for within the vector of freqs.
@param frequency		The frequency of the value if it was found.
@return					Whether the value was found.
*/
bool findFreq(vector<freq>& frequencies, int value, int& frequency)
{
	bool alreadyFound = false; // Stores whether the value (frequency) was already found in the vector.
	for (int i = 0; i < frequencies.size(); ++i)
	{
		if (value == frequencies[i].value)
		{
			alreadyFound = true;
			frequency = ++frequencies[i].frequency;
		}
	}
	
	return alreadyFound;
}

/*
Finds the mode of an array and stores it as a vector of freq instances.
@param inputArray		The pointer to the first element of the araray.
@param nValues			The number of elements in array.
@return					A vector of freqs containing the mode.
*/
vector<freq> mode(int* inputArray, int nValues)
{
	// int* inputArray == inputArray[MAX_VALUES]
	
	vector<freq> theMode; // The mode.
	int maxFreq = 0; // The current maximum frequency found.
	int frequency = 0; // The current frequency being looked at.
	
	for (int j = 0; j < nValues; ++j)
	{
		bool alreadyFound = findFreq(theMode, *inputArray, frequency); // Stores whether the frequency was found.
		
		if (!alreadyFound)
		{
			freq newFreq;
			newFreq.value = *inputArray;
			newFreq.frequency = 1;
			theMode.push_back(newFreq);
			frequency = 1;
		}
		
		if (frequency > maxFreq)
			maxFreq = frequency;
			
		++inputArray;
	} // Traverses every element of the array and stores it as a frequency instance added to theMode.
	
	int vectorSize = theMode.size(); // Gets the size of the vector.
	
	for (int i = 0; i < vectorSize; ++i)
	{
		if (theMode[i].frequency < maxFreq)
		{
			theMode.erase(theMode.begin() + i);
			--vectorSize;
			--i;
		}
	} // Removes all freq instances from theMode that contain frequencies less than maxFreq
	
	return theMode;
}

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
int get_int_value(string message, int min, int max)
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
					cout << "Error, " << input << " is not between " << min << " and " <<  max << endl;
				} else {			//The input is within range
					return output;
				}
			}
		}
		else cin.clear();											//flush the input buffer
		cerr << "\nInvalid input. Please try again.\n"; 	//you didn't enter a valid value if you get here
	} //endless while loop that keeps prompting for a valid value
} //End of the get_int_value function
