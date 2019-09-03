#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream inputFile;
	ofstream outputFile;

	int readInValue;
	int numValues;

	inputFile.open("DocBrownsText.txt");
	If(!inputFile)
	{
		cout << "Invalid input filee. Please fix and try again";
		return 1; // terminates main function
	}


	outputFile.open("DocBrownsOtherText.txt");	// this file doesn't have to exist
	

	inputFile >> numValues; // read in number of values
	for(int i = 0; i < numValues; i++)
	{
		inputFile >> readInValue;
		outputFile << readInValue << endl;
	}
	outputFile.close();		//closes the file
	inputFile.close();	    // closes the file
	return 0;	
}