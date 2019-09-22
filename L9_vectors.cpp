/*	September 25, 2018
	Purpose: To create a vector of names and make changes to it.
	Inputs: What name the user wants to add prior to 'Doug' and what name to remove
	Output: The vector after each modification
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayVector(const vector<string>& input);

int main(int argc, char** argv)
{
	vector<string> names1; // Vector to store list of names
	
	cout << "Task #1" << endl;
	names1.push_back("Alice");
	names1.push_back("Bob");
	names1.push_back("Connie");
	names1.push_back("David");
	names1.push_back("Edward");
	names1.push_back("Fran");
	names1.push_back("Gomez");
	names1.push_back("Harry");
	displayVector(names1);
	
	cout << "Task #2" << endl;
	cout << "First element: " << names1[0] << endl;
	cout << "Last element : " << names1[names1.size() - 1] << endl;
	
	cout << "Task #3" << endl;
	cout << "Size of the vector is now: " << names1.size() << endl;
	
	cout << "Task #4" << endl;
	
	vector<string>::iterator iter; // Iterator for beginning position
	vector<string>::iterator iterEnd = names1.end(); // Iterator for ending position
	
	for (iter = names1.begin(); iter != iterEnd; ++iter)
	{
		
		if (*iter == "Alice")
		{
			names1.insert(names1.erase(iter), "Alice B. Toklas");
			break;
		}
		
	}
	displayVector(names1);
	
	cout << "Task #5" << endl;
	displayVector(names1);
	cout << "Enter a name to insert 'Doug' after: ";
	string userInput; // String to store user input
	getline(cin, userInput);
	cout << "You entered: " << userInput << endl;
	
	iterEnd = names1.end();
	
	for (iter = names1.begin(); iter != iterEnd; ++iter)
	{
		if (*iter == userInput)
		{
			names1.insert(iter + 1, "Doug");
			break;
		}
	}

	displayVector(names1);
	
	cout << "Task #6" << endl;
	cout << "Enter the name to remove: ";
	getline(cin, userInput);
	cout << "You entered: " << userInput << endl;
	
	iterEnd = names1.end();
	
	for (iter = names1.begin(); iter != iterEnd; ++iter)
	{
		if (*iter == userInput)
			{
				names1.erase(iter);
				break;
			}
	}
	displayVector(names1);
	
	cout << "Task #7" << endl;
	vector<string> names2; // Vector to store copy of all names in names1 vector
	
	for (int i = 0; i < names1.size(); ++i)
		names2.push_back(names1[i]);
		
	iter = names1.begin();
	
	names1.erase(iter);
	
	cout << "First vector, after removing the first name:" << endl;
	displayVector(names1);
	
	cout << "Copy of vector, taken before removing the first name:" << endl;
	displayVector(names2);
	
	cout << "Ended successfully" << endl;
	
	return 0;
}

/*
To iterate through vector and display every element.
@param input	Vector to be displayed
*/
void displayVector(const vector<string>& input)
{
	for (int i = 0; i < input.size(); ++i)
	{
		cout << input[i] << endl;
	}
}

// vector.end points to element after last one. 
