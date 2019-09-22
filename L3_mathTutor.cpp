/*	Sean Masterson
	Alina Susan
	September 4, 2018
	Purpose: To generate two random numbers and calculate the result of performing an operation on them. Then check if user predicts answer correctly.
	Inputs: Largest possible random number to generate, operator, and the answer the user predicts.
	Output: Whether the answer the user predicted is correct. If not, then show the real answer.
*/

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>


using namespace std;

int main()
{
	long unsigned int seconds = time(0);
	srand(seconds);
	string someOperator;
	
	do
	{

		int maxRand;
		cout << "What's the largest number that you want to deal with? ";
		cin >> maxRand;
		
		// generate two random numbers
		long int random1 = rand() % (maxRand + 1);
		long int random2 = rand() % (maxRand + 1);
		
		cout << "What operator do you want to try (+ - * /) : ";
		cin >> someOperator;
		
		if (someOperator == "+" || someOperator == "-" || someOperator == "*" || someOperator == "/")
		{
			int userAnswer;
			cout << "What is " << random1 << " " << someOperator << " " << random2 << "?" << endl;
			cin >> userAnswer;
			
			int answer;
			if (someOperator == "+")
			{
				answer = random1 + random2;
			}
			else if (someOperator == "-")
			{
				answer = random1 - random2;
			}
			else if (someOperator == "*")
			{
				answer = random1 * random2;
			}
			else
			{
				answer = random1 / random2;
			}
				
			if (answer == userAnswer)
			{
				cout << "Congratulations" << endl << "Completed Satisfactorily" << endl;
			}
			else
			{
				cout << "Thank you for playing, the real answer is: " << answer << endl << "Completed Satisfactorily" << endl;
			}
			
		}
		
			
		else
			
			cout << "Error, operation " << someOperator << " not valid." << endl;
		
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	} while (true);
		
	
	
	return 0;
}

