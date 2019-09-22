/* 
September 11, 2018
Purpose: This program is used to display a bar chart of a population by year given by an input and written to an output file. 
Inputs: the input file name continaning the info
Output: the bar graphs showing population data
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream inputFile;
	
	string filename; // stores input filename specified by user
	
	while (filename.length() == 0)
	{
		cout << "Please enter the input file name: ";
		cin >> filename;
	
		inputFile.open(filename.c_str());
		
		if (inputFile.fail())
		{
			cout << "Error, file: " << filename << " not found." << endl;
			filename = ""; // needed to make loop condition be true
		}
	}
	
	int lines; // The lines read in from inputFile
	
	string outputFilename = "Population Bar Chart.txt"; // output filename
	ofstream outputFile;
	outputFile.open(outputFilename.c_str());
	
	while (inputFile >> lines)
	{
		cout << lines; // display year
		outputFile << lines; // write year to outputFile
		
		inputFile >> lines;
		
		while (lines >= 1000)
		{
			cout << "*";
			outputFile << "*";

			lines -= 1000;
		}
		
		cout << endl;
		outputFile << "\n";
	}
	
	inputFile.close();
	outputFile.close();
	
	cout << "Please see text file: " << outputFilename << " for results" << endl
		<< "Completed satisfactorily" << endl;
	
	return 0;
}
