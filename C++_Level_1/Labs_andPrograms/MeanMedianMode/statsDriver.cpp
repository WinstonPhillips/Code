/*
	Winston Phillips
	T00212039
	11/6/2017
	Mean, Median, Mode Program
	Professor: Dr. Brown
*/
#include <iostream>
#include <fstream>
#include "BasicSort.h"
#include "Statistics.h"

using namespace std;


int main()
{
/**********************Variables************************/
	float mean,median;
	int mode;
	int userChoice;	// choice for the main menu
	int size; // size of Array

	string fileName;

	bool goodFile = false; // used for filename validation;

	ifstream inFile;	// writing from a file
/*******************************************************/


    do{		// input validation for filename 
	cout << "Please enter the name of your data file: ";
		cin >> fileName;

		inFile.open(fileName.c_str());	//  using cstring

			if (!inFile)
			{
				cout << "Invalid file name. ";
			}
			else 
			{
				goodFile = true;
			}
		}while(!goodFile);

	inFile >> size;		// gets the number of elements to be put into array

	int* numberArray = new int[size];	// declaring numberArray after size is inputed

	for (int i = 0; i < size; i++)
	{
		inFile >> numberArray[i];
	}


do{
cout << "1.	See the Mean of the provided data set" << endl;
cout << "2.	See the Mode of the provided data set" << endl;
cout << "3.	See the Median of the provided data set" << endl;
cout << "4.	Quit" << endl;

	do{			//input validation for user's choice
	cout << "Enter your selection: ";
		cin >> userChoice;
		if (userChoice > 4  && userChoice < 0)	// input validation for user choice
		{
			cout << "Invalid choice";
		}
	}while(!(userChoice < 5 && userChoice > 0));

	


	if(userChoice == 1)
	{
		mean = findMean(numberArray,size);
		cout << endl;
		cout << "The mean of this data set is " << mean << endl;
		cout << endl;
	}
	else if(userChoice == 2)
	{
		mode = findMode(numberArray,size);
		cout << endl;
		cout << "The mode for this data set is " << mode << endl;
		cout << endl;
	}
	else if(userChoice == 3)
	{
		median = findMedian(numberArray,size);
		cout << endl;
		cout << "The median for this data set is " << median << endl;
		cout << endl;
	}

}while(userChoice != 4);

cout << endl;
cout << "Have a nice day!" << endl;
inFile.close();	// close the file

return 0;


}