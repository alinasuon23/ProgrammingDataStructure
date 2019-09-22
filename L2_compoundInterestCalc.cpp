/* Sean Masterson 018653932
   Alina Susan
   August 30, 2018
   Purpose: This program is used to calculate how many years it takes to make $75,000 with an original principle of $50,000
   Inputs: interest rate, number of times compounded, original principle
   Outputs: The number of years needed to have a balance >= $75,000
*/

#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char** argv)
{
	// P = 50,000
	// r = .04
	// n = 12
	// t = number of years
	
	const double rate = 0.04;
	const int originalPriciple = 50000;
	const int tagetBalance = 75000;
	const int numberOfTimesCompounded = 12;
	
	double accuredBalance = 0.0;
	int numberOfPeriods = 0;
	
	while (accuredBalance < tagetBalance)
	{
		accuredBalance = originalPriciple * pow(1 + (rate / numberOfTimesCompounded), numberOfTimesCompounded * numberOfPeriods);
		
		cout << "After " << numberOfPeriods << " years, the balance will be: $" << accuredBalance << endl;
		++numberOfPeriods;
	} // end while loop
	
	cout << "You will have a balance >=" << tagetBalance << " after " << numberOfPeriods - 1 << " years.";
	
	return 0;
}
