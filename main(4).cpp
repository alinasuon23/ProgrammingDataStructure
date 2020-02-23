/*  Sean Masterson
    Alina Susan
    October 30, 2018
    Purpose: Takes a static array and stores it in reverse order in a dynamic array
    Inputs: The contents of the static array.
    Output: The contents reversed.
*/

#include <iostream>

using namespace std;

const int SIZE = 10; // The size of the static array.

int* reverse(int arr[], int size);

int main(int argc, char** argv) {
	
	int array[SIZE]; // Creates new static array with size of SIZE.
	
	for (int i = 0; i < SIZE; ++i)
	{
		cout << "Next element in original order: ";
		cin >> array[i];
	} // Gets user input and stores it in the static array.
	
	int* reverseArray = reverse(array, SIZE); // Pointer to first element of dynamic array.
	
	for (int i = 0; i < SIZE; ++i)
	{
		cout << "Using ptr arithmetic: " << (*reverseArray) << endl;
		++reverseArray;
	} // Gets every element of dynamic array and display it.
	
	reverseArray = reverseArray - 10;
	
	delete [] reverseArray;
	
	cout << "Completed satisfactorily";
	return 0;
}

/*
Reverse static array and stores elements in reversed order in dynamic array.
@param	arr[]	The static array.
@param	size	The size of the static array.
@return			The dynamic array with the contents in reverse order.
*/
int* reverse(int arr[], int size)
{
	int* reverseArray = new int[size]; // Pointer to first element of dynamic array.
	for (int i = size - 1; i >= 0; --i)
	{
		reverseArray[size-1-i] = arr[i];
	} // Stores every element of arr[] in reverse order into dynamic array reverseArray.
	return reverseArray;
}
