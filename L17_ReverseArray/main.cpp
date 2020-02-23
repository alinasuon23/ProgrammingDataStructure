#include <iostream>
#include <string>
using namespace std;
/*
const int SIZE = 10;
int* reverse (int arr[], int size);

int main(int argc, char** argv) 
{
	//static array ( declare size before)
	int array[SIZE];
	
	//for (int i = 0; i < 10; ++i)
	for (int i = 0; i < SIZE; ++i)
	{
		cout << "Next element in original order: ";
		cin >> array[i];
	}
	
	// points to first element of dynamic array (reverse)
	int* reverseArray = reverse(array, SIZE);

	for (int i = 0; i < SIZE; ++i)
	{
		cout << "Using ptr arithmetic: ";
		cout << (*reverseArray) <<endl;
		
		++reverseArray;
	}
	
	//points to the last element so we need to point to first element
	reverseArray = reverseArray - SIZE;
	//frees up the space of reverseArray
	delete [] reverseArray;
	
	
	cout << "Completed satisfactorily ";
	
	return 0;
}

int* reverse (int arr[], int size)
{
	int* reverseArray = new int[size];
	for (int i = size -1 ; i >= 0; --i)
	{
		reverseArray[(size-1)-i] = arr[i];
	}
		return reverseArray;
}

*/


int main ()
{
	cout <<"Enter size array: ";
	int size;
	cin>>size;
	
	//new dynamic string array
//	string* dynamicArray = new string[size];
	
	string* dynamicArray; //create a pointer to a string
	dynamicArray = new string[size]; //point at the first element of a newly created dynamic array 
	
	for(int i =0; i<size;++i)
	{
	cout << "enter element " <<endl;
	cin >> *dynamicArray;
	++dynamicArray;
	}
	
	dynamicArray = dynamicArray - size;

	for (int i=0; i< size; ++i)
	{
		cout << *dynamicArray;
		++dynamicArray;
	}

	//points dynamicArray back to first position
	dynamicArray = dynamicArray - size;
	//frees space
	delete[] dynamicArray;
	return 0;
}
