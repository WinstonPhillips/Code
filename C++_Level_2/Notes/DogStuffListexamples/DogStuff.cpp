#include <list>
#include <iostream>
#include "DogStuff.h"

using namespace std;

DogStuff::DogStuff(string name)
{
	Name = name;
}
void DogStuff::appendNode()
{
	float userNum;
	cout << "Float to add?";
		cin >> userNum;
	weightList.push_back(userNum);
}
void DogStuff::removeNode()
{
	int userChoice;
	int x = 0;
	float outputNum;

	for(weightIterator = weightList.begin(); weightIterator != weightList.end(); weightIterator++)
	{
		outputNum = *weightIterator;
		cout << x+1 << ") " << outputNum << "\t";
		x++;
	}
	cout << endl;

	cout << "Pick a number to remove: ";
		cin >> userChoice;

	weightIterator = weightList.begin();	// because begin is a pointer, not like front which is a value


	for (int i = 0; i < userChoice+2; i++)
	{
		weightIterator++;
	}

	weightList.erase(weightIterator);
}