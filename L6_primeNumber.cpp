/*
Sean Masterson
Alina Suon
September 13, 2018
Purpose: This program is used to determine the amount of prime number the user wants to find using two
            functions with the same name but different arguments to determine the square root of it.
Inputs: The user input, the number (N) of prime numbers user wants to find
Output: 1. The number of prime number(s) the user wants to find, 2. The prime list of prime numbers up to the
            amount user wants, 3. the square root of that prime number.        
*/

#include <iostream>

using namespace std;

long int sqrt(const long int &input);
double sqrt(const double &input);
bool isPrime(const int& primeSuspect);

int main(int argc, char** argv)
{
	int noPrimesToFind; // Number of primes to find determined by user input
	int noPrimesFound = 0; // Number of primes found
	cout << "Enter number of prime numbers to find: ";
	cin >> noPrimesToFind;
	
	int primeSuspect = 2; // Current number currently determining whether its prime
	
	while (noPrimesFound < noPrimesToFind)
	{
		if (isPrime(primeSuspect)) // is prime
		{
			cout << "Next prime number is:          " << primeSuspect << " And its square root is: " << sqrt(static_cast<double>(primeSuspect)) << endl;
			++noPrimesFound;
		}
		++primeSuspect;
	}
	
	cout << "Completed successfully." << endl;
	
	return 0;
}

/**
 * To determine the square root of a number 
 * @param    input                The number to find the square root of
 * @return                  	  The square root of the number.
 */
long int sqrt(const long int& input)
{
	return static_cast<long int>(sqrt(static_cast<double>(input)));
}

/**
 * To determine the square root of a number 
 * @param    input                The number to find the square root of
 * @return                    	  The square root of the number.
 */
double sqrt(const double &input)
{
	if (input < 0.0)
	{
		cout << "ValueError exception: You cannot get square roots of a negative number." << endl;
		return -1;
	}
	
	double squareRoot = input / 2; // Stores square root
	
	while (input - squareRoot * squareRoot >= 0.000001 || input - squareRoot * squareRoot <= -0.000001 )
	{
		squareRoot = (squareRoot + input / squareRoot) / 2;
	}
	
	return squareRoot;	
}

/**
 * To determine whether the input is a prime number or not. 
 * @param    input                The number to determine whether its prime
 * @return                    	  True or false.
 */
bool isPrime(const int& primeSuspect)
{
	double squareRoot = sqrt(static_cast<double>(primeSuspect)); // Stores square root
	for (int i = 2; i <= squareRoot; ++i)
	{
		if (primeSuspect % i == 0)
		{
			return false;
		}
	}
	return true;
}

