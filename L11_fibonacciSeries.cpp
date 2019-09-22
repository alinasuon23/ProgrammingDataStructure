/*
Sean Masterson
Alina Suon
October 2, 2018
Purpose: To calculate a fibonacci number using both iterative and recursive methods.
Inputs: The numbers to calculate the fibonacci number and a vector of ints to record how many times
the fibonacci number of that number was calculated when calculated recursively.
Output: The fibonacci number and how many times the fibonacci number of that number was calculated
when calculated recursively.
*/

#include <iostream>
#include <vector>

using namespace std;

unsigned long long fibIterative(int n);
int fibRecursive(int number, vector<int>& hits);

int main(int argc, char** argv)
{
	cout << "using the iterative method:" << endl;
	
	for (int i = 0; i < 92; ++i)
	{
		cout << "Fibonacci number: " << i << " = " << fibIterative(i) << endl;
	} // Gets fibonacci number from fibIterative() from j = 0 to 92.
	
	cout << "using the recursive method:" << endl;

	vector<int> hits; // Vector that records how many times the fibonacci number of a particular number has been calculated.
	
	for (int i = 0; i < 20; ++i)
	{
		hits.clear();
		cout << "Fibonacci number: " << i << " = " << fibRecursive(i, hits) << endl;
		
		for (int j = 0; j < hits.size(); ++j)
		{
			cout << "Hit fibonacci number: " << j << " " << hits[j] << " times." << endl;
		}
	} // Gets fibonacci number from fibRecursive() from j = 0 to 20.
	
	cout << "Completed satisfactorily" << endl;
	return 0;
}

/**
Calculates fibonacci number iteratively
@param	n			The fibonacci number that will be calculated at this position.
@return				The fibonacci number.
*/
unsigned long long fibIterative(int n)
{
	if (n == 0)
		return 0;
	
    unsigned long long previous = 1; // (n - 2)th term of fibonacci number
    unsigned long long current = 1; // (n - 1)th term of fibonacci number
    unsigned long long next = 1; // nth term of fibonacci number
    
    for (int i =3; i <=n; ++i)
	{
        next = current + previous;
        previous = current;
        current = next;
    } // Calculates fibonacci number iteratively.
    
    return next;
}

/**
Calculates fibonacci number iteratively
@param	n			The fibonacci number that will be calculated at this position.
@param	hits		Vector that records how many times the fibonacci number of a particular number has been calculated.
@return				The fibonacci number.
*/
int fibRecursive(int number, vector<int>& hits)
{
	while (hits.size() <= number)
	{
		hits.push_back(0);
	} // Adds elements to vector if they do not exist at this point.
	
	++hits[number];
	
	if (number < 2)
	{
		return number;
	}

	return fibRecursive(number - 1, hits) + fibRecursive(number - 2, hits);
}
