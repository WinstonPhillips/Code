/*
	Title:  arrayPointer_4.cpp
	Author:  April Crockett
	Date:  8/15/2017
	Purpose:  This program uses the address of each element in the array.
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	const int NUM_COINS = 5;
	double coins[NUM_COINS] = {0.05, 0.1, 0.25, 0.5, 1.0};
	double *doublePtr; // Pointer to a double
	int count;         // Array inde
	// Use the pointer to display the values in the array.
	cout << "Here are the values in the coins array:\n";
	for (count = 0; count < NUM_COINS; count++)
	{
		// Get the address of an array element.
		doublePtr = &coins[count];

		// Display the contents of the element.
		cout << *doublePtr << " ";
	}
	cout << endl;
	
	return 0;
}