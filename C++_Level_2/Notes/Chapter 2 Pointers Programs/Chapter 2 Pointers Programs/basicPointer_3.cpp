/*
	Title:  basicPointer_3.cpp
	Author:  April Crockett
	Date:  8/15/2017
	Purpose:  demonstrate the address operator, defining a pointer, 
				assignment with a pointer, and the indirection operator.
*/
#include <iostream>
using namespace std;

int main()
{
	int x = 25;    // int variable
	int *dog;      // Pointer variable, can point to an int

	dog = &x;      // Store the address of x in dog
	cout << "The value in x is " << x << endl;
	cout << "The address of x using dog " << dog << endl;
	cout << "The value in x using dog is " << *dog << endl;
	cout << "The address of x " << &x << endl;

	return 0;
}

