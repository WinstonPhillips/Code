/*
Winston Phillips
T00212039
9/12/2017
Math Tutor
*/
#include <iomanip>
#include <iostream>
#include "randomInt.h"
#include <cstdlib>

using namespace std;

int main()
{

/**************Variables**************/
	int num1, num2;
	int Answer;
	int inputAns;
/**************Main Output************/

	seedRand();				// initializes srand()

	randomInt1(num1);		// generates first random integer

	randomInt2(num2);		// generates second random integer

	cout << setw(10) << num1 << endl;
	cout << setw(5) << "+" <<  setw(5) << num2 << endl;
	cout << setw(10) << "---" << endl;
	cout << setw(7) << " ";		// so inputed answer lines up
		cin >> inputAns;

	if (inputAns == num1 + num2)
	{
		cout << "That is correct!" << endl;
	}
	else
	{
		cout << "I am sorry, that is incorrect. The correct answer is " << num1 + num2 << endl;
	}
	return 0;
}