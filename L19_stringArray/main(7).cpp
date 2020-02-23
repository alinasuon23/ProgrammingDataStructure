/*  Sean Masterson
    Alina Susan
    November 15, 2018
    Purpose: Create and display String objects representing a dynamic array of strings.
    Inputs: strings to add to String object.
    Output: What is stored in the String object and any errors that happen.
*/

#include <iostream>
#include "String.h"

int main(int argc, char** argv) {
	
	try
	{
		String stringArray = String(2); // New String object which acts like an array.
		cout << "At the start, no elements, the number of elements is: " << stringArray.getnElements() << " and the capacity is: " << stringArray.getSize() << endl;
		stringArray.add("Billy");
		cout << "After adding one element, the number of elements is: " << stringArray.getnElements() << " and the capacity is: " << stringArray.getSize() << endl;
		stringArray.add("Joel");
		cout << "After adding the second, the number of elements is: " << stringArray.getnElements() << " and the capacity is: " << stringArray.getSize() << endl;
		stringArray.add("concerts");
		cout << "After adding the third, the number of elements is: " << stringArray.getnElements() << " and the capacity is: " << stringArray.getSize() << endl;
		stringArray.add("are");
		cout << "After adding the fourth, the number of elements is: " << stringArray.getnElements() << " and the capacity is: " << stringArray.getSize() << endl;
		stringArray.add("wonderful");
		cout << "After adding the fifth, the number of elements is: " << stringArray.getnElements() << " and the capacity is: " << stringArray.getSize() << endl;
		
		for (int i = 0; i < stringArray.getnElements(); ++i)
		{
			cout << stringArray[i] << endl;
		} // Display every element in String object in order.
		
		stringArray[5];
		
	}
	catch (String::IndexOutOfBounds sz)
	{
		cout << "Error, tried to access element: " << sz.getIndex() << " and got message: " << sz.getMessage() << endl; 
	}
	
	try
	{
		cout << "Attempting to create String with negative size:" << endl;
		String negativeSize = String(-5); // New String object with invalid index.
	}
	catch (String::IndexOutOfBounds sz)
	{
		cout << "Error message: " << sz.getMessage() << endl; 
	}
	
	cout << "Completed satisfactorily";
	
	return 0;
}
